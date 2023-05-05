
#ifndef _H5PART_ATTRIB_H_
#define _H5PART_ATTRIB_H_

#include "h5part_exports.h"

#ifdef __cplusplus
extern "C" {
#endif


h5part_int64_t H5PART_API
H5PartWriteFileAttribFloat64 (
	H5PartFile *f,
	const char *name,
	const h5part_float64_t data
	);

h5part_int64_t H5PART_API
H5PartWriteFileAttribFloat32 (
	H5PartFile *f,
	const char *name,
	const h5part_float32_t data
	);

h5part_int64_t H5PART_API
H5PartWriteFileAttribInt64 (
	H5PartFile *f,
	const char *name,
	const h5part_int64_t data
	);

h5part_int64_t H5PART_API
H5PartWriteFileAttribInt32 (
	H5PartFile *f,
	const char *name,
	const h5part_int32_t data
	);

h5part_int64_t H5PART_API
H5PartWriteStepAttribFloat64 (
	H5PartFile *f,
	const char *name,
	const h5part_float64_t data
	);

h5part_int64_t H5PART_API
H5PartWriteStepAttribFloat32 (
	H5PartFile *f,
	const char *name,
	const h5part_float32_t data
	);

h5part_int64_t H5PART_API
H5PartWriteStepAttribInt64 (
	H5PartFile *f,
	const char *name,
	const h5part_int64_t data
	);

h5part_int64_t H5PART_API
H5PartWriteStepAttribInt32 (
	H5PartFile *f,
	const char *name,
	const h5part_int32_t data
	);


#ifdef __cplusplus
}
#endif

#endif
