/*
  Copyright (c) 2011-2014, Intel Corporation
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.


   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
   IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
   TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
   PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "cuda_helpers.cuh"
__device__ static inline float clamp(float v, float low, float high)
{
      return min(max(v, low), high);
}


#define float3 Float3
struct Float3
{
  float x,y,z;
  __device__ friend Float3 operator+(const Float3 a, const Float3 b)
  {
    Float3 c;
    c.x = a.x+b.x;
    c.y = a.y+b.y;
    c.z = a.z+b.z;
    return c;
  }
  __device__ friend Float3 operator-(const Float3 a, const Float3 b)
  {
    Float3 c;
    c.x = a.x-b.x;
    c.y = a.y-b.y;
    c.z = a.z-b.z;
    return c;
  }
  __device__ friend Float3 operator/(const Float3 a, const Float3 b)
  {
    Float3 c;
    c.x = a.x/b.x;
    c.y = a.y/b.y;
    c.z = a.z/b.z;
    return c;
  }
  __device__ friend Float3 operator*(const Float3 a, const Float3 b)
  {
    Float3 c;
    c.x = a.x*b.x;
    c.y = a.y*b.y;
    c.z = a.z*b.z;
    return c;
  }
  __device__ friend Float3 operator*(const Float3 a, const float b)
  {
    Float3 c;
    c.x = a.x*b;
    c.y = a.y*b;
    c.z = a.z*b;
    return c;
  }
};

struct Ray {
    float3 origin, dir;
};


__device__ static void
generateRay(const float raster2camera[4][4],
            const float camera2world[4][4],
            float x, float y, Ray &ray) {
    // transform raster coordinate (x, y, 0) to camera space
    float camx = raster2camera[0][0] * x + raster2camera[0][1] * y + raster2camera[0][3];
    float camy = raster2camera[1][0] * x + raster2camera[1][1] * y + raster2camera[1][3];
    float camz = raster2camera[2][3];
    float camw = raster2camera[3][3];
    camx /= camw;
    camy /= camw;
    camz /= camw;

    ray.dir.x = camera2world[0][0] * camx + camera2world[0][1] * camy + camera2world[0][2] * camz;
    ray.dir.y = camera2world[1][0] * camx + camera2world[1][1] * camy + camera2world[1][2] * camz;
    ray.dir.z = camera2world[2][0] * camx + camera2world[2][1] * camy + camera2world[2][2] * camz;

    ray.origin.x = camera2world[0][3] / camera2world[3][3];
    ray.origin.y = camera2world[1][3] / camera2world[3][3];
    ray.origin.z = camera2world[2][3] / camera2world[3][3];
}


__device__ static inline bool
Inside(float3 p, float3 pMin, float3 pMax) {
    return (p.x >= pMin.x && p.x <= pMax.x &&
            p.y >= pMin.y && p.y <= pMax.y &&
            p.z >= pMin.z && p.z <= pMax.z);
}


__device__ static bool
IntersectP(Ray ray, float3 pMin, float3 pMax, float &hit0, float &hit1) {
    float t0 = -1e30f, t1 = 1e30f;

    float3 tNear = (pMin - ray.origin) / ray.dir;
    float3 tFar  = (pMax - ray.origin) / ray.dir;
    if (tNear.x > tFar.x) {
        float tmp = tNear.x;
        tNear.x = tFar.x;
        tFar.x = tmp;
    }
    t0 = max(tNear.x, t0);
    t1 = min(tFar.x, t1);

    if (tNear.y > tFar.y) {
        float tmp = tNear.y;
        tNear.y = tFar.y;
        tFar.y = tmp;
    }
    t0 = max(tNear.y, t0);
    t1 = min(tFar.y, t1);

    if (tNear.z > tFar.z) {
        float tmp = tNear.z;
        tNear.z = tFar.z;
        tFar.z = tmp;
    }
    t0 = max(tNear.z, t0);
    t1 = min(tFar.z, t1);

    if (t0 <= t1) {
        hit0 = t0;
        hit1 = t1;
        return true;
    }
    else
        return false;
}


__device__ static inline float Lerp(float t, float a, float b) {
    return (1.f - t) * a + t * b;
}


__device__ static inline float D(int x, int y, int z, int nVoxels[3],
                      float density[]) {
    x = clamp(x, 0, nVoxels[0]-1);
    y = clamp(y, 0, nVoxels[1]-1);
    z = clamp(z, 0, nVoxels[2]-1);

    return density[z*nVoxels[0]*nVoxels[1] + y*nVoxels[0] + x];
}


__device__ static inline float3 Offset(float3 p, float3 pMin, float3 pMax) {
    return (p - pMin) / (pMax - pMin);
}


__device__ static inline float Density(float3 Pobj, float3 pMin, float3 pMax,
                     float density[], int nVoxels[3]) {
    if (!Inside(Pobj, pMin, pMax))
        return 0;
    // Compute voxel coordinates and offsets for _Pobj_
    float3 vox = Offset(Pobj, pMin, pMax);
    vox.x = vox.x * nVoxels[0] - .5f;
    vox.y = vox.y * nVoxels[1] - .5f;
    vox.z = vox.z * nVoxels[2] - .5f;
    int vx = (int)(vox.x), vy = (int)(vox.y), vz = (int)(vox.z);
    float dx = vox.x - vx, dy = vox.y - vy, dz = vox.z - vz;

    // Trilinearly interpolate density values to compute local density
    float d00 = Lerp(dx, D(vx, vy, vz, nVoxels, density),
                     D(vx+1, vy, vz, nVoxels, density));
    float d10 = Lerp(dx, D(vx, vy+1, vz, nVoxels, density),
                     D(vx+1, vy+1, vz, nVoxels, density));
    float d01 = Lerp(dx, D(vx, vy, vz+1, nVoxels, density),
                     D(vx+1, vy, vz+1, nVoxels, density));
    float d11 = Lerp(dx, D(vx, vy+1, vz+1, nVoxels, density),
                     D(vx+1, vy+1, vz+1, nVoxels, density));
    float d0 = Lerp(dy, d00, d10);
    float d1 = Lerp(dy, d01, d11);
    return Lerp(dz, d0, d1);
}


/* Returns the transmittance between two points p0 and p1, in a volume
   with extent (pMin,pMax) with transmittance coefficient sigma_t,
   defined by nVoxels[3] voxels in each dimension in the given density
   array. */
__device__ static inline float
transmittance(float3 p0, float3 p1, float3 pMin,
              float3 pMax, float sigma_t,
              float density[], int nVoxels[3]) {
    float rayT0, rayT1;
    Ray ray;
    ray.origin = p1;
    ray.dir = p0 - p1;

    // Find the parametric t range along the ray that is inside the volume.
    if (!IntersectP(ray, pMin, pMax, rayT0, rayT1))
        return 1.f;

    rayT0 = max(rayT0, 0.f);

    // Accumulate beam transmittance in tau
    float tau = 0.0f;
    float rayLength = sqrt(ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y +
                           ray.dir.z * ray.dir.z);
    float stepDist = 0.2f;
    float stepT = stepDist / rayLength;

    float t = rayT0;
    float3 pos = ray.origin + ray.dir * rayT0;
    float3 dirStep = ray.dir * stepT;
    while (t < rayT1) {
        tau += stepDist * sigma_t * Density(pos, pMin, pMax, density, nVoxels);
        pos = pos + dirStep;
        t += stepT;
    }

    return exp(-tau);
}


__device__ static inline float
distanceSquared(float3 a, float3 b) {
    float3 d = a-b;
    return d.x*d.x + d.y*d.y + d.z*d.z;
}


__device__ static inline float
raymarch(float density[], int nVoxels[3], Ray ray) {
    float rayT0, rayT1;
    float3 pMin = {.3f, -.2f, .3f}, pMax = {1.8f, 2.3f, 1.8f};
    float3 lightPos = { -1.f, 4., 1.5f };

    if (!IntersectP(ray, pMin, pMax, rayT0, rayT1))
        return 0.f;

    rayT0 = max(rayT0, 0.f);

    // Parameters that define the volume scattering characteristics and
    // sampling rate for raymarching
    float Le = .25f;            // Emission coefficient
    float sigma_a = 10.f;        // Absorption coefficient
    float sigma_s = 10.f;        // Scattering coefficient
    float stepDist = 0.025f;    // Ray step amount
    float lightIntensity = 40.0f; // Light source intensity

    float tau = 0.f;  // accumulated beam transmittance
    float L = 0.f;      // radiance along the ray
    float rayLength = sqrt(ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y +
                           ray.dir.z * ray.dir.z);
    float stepT = stepDist / rayLength;

    float t = rayT0;
    float3 pos = ray.origin + ray.dir * rayT0;
    float3 dirStep = ray.dir * stepT;
    while (t < rayT1)
    {
        float d = Density(pos, pMin, pMax, density, nVoxels);

        // terminate once attenuation is high
        float atten = exp(-tau);
        if (atten < .005f)
            break;

        // direct lighting
        float Li = lightIntensity / distanceSquared(lightPos, pos) *
            transmittance(lightPos, pos, pMin, pMax, sigma_a + sigma_s,
                          density, nVoxels);
        L += stepDist * atten * d * sigma_s * (Li + Le);

        // update beam transmittance
        tau += stepDist * (sigma_a + sigma_s) * d;

        pos = pos + dirStep;
        t += stepT;
    }

    // Gamma correction
    return pow(L, 1.f / 2.2f);
}


/* Utility routine used by both the task-based and the single-core entrypoints.
   Renders a tile of the image, covering [x0,x0) * [y0, y1), storing the
   result into the image[] array.
 */
__device__ static void
volume_tile(int x0, int y0, int x1,
            int y1, float density[], int nVoxels[3],
            const float raster2camera[4][4],
            const float camera2world[4][4],
            int width, int height, float image[]) {
    // Work on 4x4=16 pixel big tiles of the image.  This function thus
    // implicitly assumes that both (x1-x0) and (y1-y0) are evenly divisble
    // by 4.
    for (int y = y0; y < y1; y += 8) {
        for (int x = x0; x < x1; x += 8) {
              for (int ob = 0; ob < 64; ob += programCount)
              {
                const int o = ob + programIndex;


                // These two arrays encode the mapping from [0,15] to
                // offsets within the 4x4 pixel block so that we render
                // each pixel inside the block
                const int xoffsets[16] = { 0, 1, 0, 1, 2, 3, 2, 3,
                  0, 1, 0, 1, 2, 3, 2, 3 };
                const int yoffsets[16] = { 0, 0, 1, 1, 0, 0, 1, 1,
                  2, 2, 3, 3, 2, 2, 3, 3 };

                const int xblock[4] = {0, 4, 0, 4};
                const int yblock[4] = {0, 0, 4, 4};

                // Figure out the pixel to render for this program instance
                const int xo = x + xblock[o/16] + xoffsets[o&15];
                const int yo = y + yblock[o/16] + yoffsets[o&15];

                // Use viewing parameters to compute the corresponding ray
                // for the pixel
                Ray ray;
                generateRay(raster2camera, camera2world, xo, yo, ray);

                // And raymarch through the volume to compute the pixel's
                // value
                int offset = yo * width + xo;
                if (xo < x1 && yo < y1)
                  image[offset] = raymarch(density, nVoxels, ray);
            }
        }
    }
}


__global__ void
volume_task(float density[], int _nVoxels[3],
            const float _raster2camera[4][4],
            const float _camera2world[4][4],
            int width, int height, float image[]) {
  if (taskIndex0 >= taskCount0) return;

#if 0
  int nVoxels[3];
  nVoxels[0] = _nVoxels[0];
  nVoxels[1] = _nVoxels[1];
  nVoxels[2] = _nVoxels[2];

  float raster2camera[4][4];
  raster2camera[0][0] = _raster2camera[0][0];
  raster2camera[0][1] = _raster2camera[0][1];
  raster2camera[0][2] = _raster2camera[0][2];
  raster2camera[0][3] = _raster2camera[0][3];
  raster2camera[1][0] = _raster2camera[1][0];
  raster2camera[1][1] = _raster2camera[1][1];
  raster2camera[1][2] = _raster2camera[1][2];
  raster2camera[1][3] = _raster2camera[1][3];
  raster2camera[2][0] = _raster2camera[2][0];
  raster2camera[2][1] = _raster2camera[2][1];
  raster2camera[2][2] = _raster2camera[2][2];
  raster2camera[2][3] = _raster2camera[2][3];
  raster2camera[3][0] = _raster2camera[3][0];
  raster2camera[3][1] = _raster2camera[3][1];
  raster2camera[3][2] = _raster2camera[3][2];
  raster2camera[3][3] = _raster2camera[3][3];

  float camera2world[4][4];
  camera2world[0][0] = _camera2world[0][0];
  camera2world[0][1] = _camera2world[0][1];
  camera2world[0][2] = _camera2world[0][2];
  camera2world[0][3] = _camera2world[0][3];
  camera2world[1][0] = _camera2world[1][0];
  camera2world[1][1] = _camera2world[1][1];
  camera2world[1][2] = _camera2world[1][2];
  camera2world[1][3] = _camera2world[1][3];
  camera2world[2][0] = _camera2world[2][0];
  camera2world[2][1] = _camera2world[2][1];
  camera2world[2][2] = _camera2world[2][2];
  camera2world[2][3] = _camera2world[2][3];
  camera2world[3][0] = _camera2world[3][0];
  camera2world[3][1] = _camera2world[3][1];
  camera2world[3][2] = _camera2world[3][2];
  camera2world[3][3] = _camera2world[3][3];
#else
#define  nVoxels _nVoxels
#define  raster2camera _raster2camera
#define  camera2world _camera2world
#endif

  int dx = 8, dy = 8; // must match value in volume_ispc_tasks
  int xbuckets = (width + (dx-1)) / dx;
  int ybuckets = (height + (dy-1)) / dy;

  int x0 = (taskIndex % xbuckets) * dx;
  int y0 = (taskIndex / xbuckets) * dy;
  int x1 = x0 + dx, y1 = y0 + dy;
  x1 = min(x1, width);
  y1 = min(y1, height);

  volume_tile(x0, y0, x1, y1, density, nVoxels, raster2camera,
      camera2world, width, height, image);
}


extern "C"
__global__ void
volume_ispc_tasks___export( float density[],  int nVoxels[3],
    const  float raster2camera[4][4],
    const  float camera2world[4][4],
    int width,  int height,  float image[]) {
  // Launch tasks to work on (dx,dy)-sized tiles of the image
  int dx = 8, dy = 8;
  int nTasks = ((width+(dx-1))/dx) * ((height+(dy-1))/dy);
  launch(nTasks,1,1,volume_task)
    (density, nVoxels, raster2camera, camera2world,
     width, height, image);
  cudaDeviceSynchronize();
}

extern "C"
__host__ void
volume_ispc_tasks( float density[],  int nVoxels[3],
    const  float raster2camera[4][4],
    const  float camera2world[4][4],
    int width,  int height,  float image[]) {
  volume_ispc_tasks___export<<<1,32>>>(density, nVoxels, raster2camera, camera2world, width, height,image);
  cudaDeviceSynchronize();
}
