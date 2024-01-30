/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 *
 * CompressBZIP2.h : wrapper to BZIP2 compression library http://www.bzip.org/
 *
 *  Created on: Jul 24, 2017
 *      Author: William F Godoy godoywf@ornl.gov
 */

#ifndef ADIOS2_OPERATOR_COMPRESS_COMPRESSBZIP2_H_
#define ADIOS2_OPERATOR_COMPRESS_COMPRESSBZIP2_H_

#include "adios2/core/Operator.h"

namespace adios2
{
namespace core
{
namespace compress
{

class CompressBZIP2 : public Operator
{

public:
    /**
     * Unique constructor
     */
    CompressBZIP2(const Params &parameters);

    ~CompressBZIP2() = default;

    /**
     * @param dataIn
     * @param blockStart
     * @param blockCount
     * @param type
     * @param bufferOut
     * @return size of compressed buffer
     */
    size_t Operate(const char *dataIn, const Dims &blockStart, const Dims &blockCount,
                   const DataType type, char *bufferOut) final;

    /**
     * @param bufferIn
     * @param sizeIn
     * @param dataOut
     * @return size of decompressed buffer
     */
    size_t InverseOperate(const char *bufferIn, const size_t sizeIn, char *dataOut) final;

    bool IsDataTypeValid(const DataType type) const final;

private:
    /**
     * check status from BZip compression and decompression functions
     * @param status returned by BZip2 library
     * @param hint extra exception information
     */
    void CheckStatus(const int status, const std::string hint) const;

    /**
     * Decompress function for V1 buffer. Do NOT remove even if the buffer
     * version is updated. Data might be still in lagacy formats. This function
     * must be kept for backward compatibility
     * @param bufferIn : compressed data buffer (V1 only)
     * @param sizeIn : number of bytes in bufferIn
     * @param dataOut : decompressed data buffer
     * @return : number of bytes in dataOut
     */
    size_t DecompressV1(const char *bufferIn, const size_t sizeIn, char *dataOut);
};

} // end namespace compress
} // end namespace core
} // end namespace adios2

#endif /* ADIOS2_TRANSFORM_COMPRESSION_COMPRESSBZIP2_H_ */
