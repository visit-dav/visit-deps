#ifndef VTKMDIY_MPI_MPITYPES_H
#define VTKMDIY_MPI_MPITYPES_H

#include <cstring>

#define TYPESIZE_MPI_Comm     4
#define TYPESIZE_MPI_Datatype 8
#define TYPESIZE_MPI_Status   12
#define TYPESIZE_MPI_Request  4
#define TYPESIZE_MPI_Op       4
#define TYPESIZE_MPI_File     4
#define TYPESIZE_MPI_Win      8

namespace diy
{
namespace mpi
{

#if defined(VTKMDIY_HAS_MPI)
#  define ASSERT_MPI_TYPE_SIZE(mpitype) static_assert(sizeof(mpitype) <= sizeof(DIY_##mpitype), "");
#else
# define ASSERT_MPI_TYPE_SIZE(mpitype)
struct MPI_Win;
#endif

#define DEFINE_DIY_MPI_TYPE(mpitype)                                         \
struct DIY_##mpitype {                                                       \
  void* data[((TYPESIZE_##mpitype) + sizeof(void*) - 1)/sizeof(void*)];      \
};                                                                           \
ASSERT_MPI_TYPE_SIZE(mpitype)

#define DEFINE_DIY_MPI_TYPE_MOVE(mpitype)                                               \
  struct DIY_##mpitype                                                                  \
  {                                                                                     \
    DIY_##mpitype() = default;                                                          \
    DIY_##mpitype(const mpitype&) = delete;                                             \
    DIY_##mpitype& operator=(const mpitype&) = delete;                                  \
    DIY_##mpitype(mpitype&& obj)                                                        \
    {                                                                                   \
      std::memcpy(data, &obj, TYPESIZE_##mpitype);                                      \
      std::memset(&obj, 0, TYPESIZE_##mpitype);                                         \
    }                                                                                   \
    DIY_##mpitype& operator=(mpitype&& obj)                                             \
    {                                                                                   \
      std::memcpy(data, &obj, TYPESIZE_##mpitype);                                      \
      std::memset(&obj, 0, TYPESIZE_##mpitype);                                         \
      return *this;                                                                     \
    }                                                                                   \
    operator const mpitype&() const { return *reinterpret_cast<const mpitype*>(data); } \
    void reset() { std::memset(data, 0, TYPESIZE_##mpitype); }                          \
                                                                                        \
  private:                                                                              \
    char* data[TYPESIZE_##mpitype];                                                     \
  };                                                                                    \
  ASSERT_MPI_TYPE_SIZE(mpitype);

DEFINE_DIY_MPI_TYPE(MPI_Comm)
DEFINE_DIY_MPI_TYPE(MPI_Datatype)
DEFINE_DIY_MPI_TYPE(MPI_Status)
DEFINE_DIY_MPI_TYPE(MPI_Request)
DEFINE_DIY_MPI_TYPE(MPI_Op)
DEFINE_DIY_MPI_TYPE(MPI_File)
DEFINE_DIY_MPI_TYPE_MOVE(MPI_Win)

#undef DEFINE_DIY_MPI_TYPE
#undef DEFINE_DIY_MPI_TYPE_MOVE
#undef ASSERT_MPI_TYPE_SIZE

}
} // diy::mpi

#undef TYPESIZE_MPI_Comm
#undef TYPESIZE_MPI_Datatype
#undef TYPESIZE_MPI_Status
#undef TYPESIZE_MPI_Request
#undef TYPESIZE_MPI_Op
#undef TYPESIZE_MPI_File
#undef TYPESIZE_MPI_Win

#endif // VTKMDIY_MPI_MPITYPES_H
