/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 *
 * BP3Serializer.h
 *
 *  Created on: Jan 24, 2017
 *      Author: William F Godoy godoywf@ornl.gov
 */

#ifndef ADIOS2_TOOLKIT_FORMAT_BP_BP3_BP3SERIALIZER_H_
#define ADIOS2_TOOLKIT_FORMAT_BP_BP3_BP3SERIALIZER_H_

#include "BP3Base.h"

#include "adios2/core/Attribute.h"
#include "adios2/core/IO.h"

#include "adios2/toolkit/format/bp/BPSerializer.h"

#ifdef _WIN32
#pragma warning(disable : 4250)
#endif

namespace adios2
{
namespace format
{

class BP3Serializer : public BP3Base, public BPSerializer
{

public:
    /**
     * Unique constructor
     * @param mpiComm MPI communicator for BP1 Aggregator
     */
    BP3Serializer(helper::Comm const &comm);

    ~BP3Serializer() = default;

    /**
     * Writes a process group index PGIndex and list of methods (from
     * transports). Done at Open or Advance.
     * @param ioName from IO class, identify Process Group with IO name
     * @param hostLanguage from ADIOS class passed to IO
     * @param transportsTypes passed to get list of transport "bp methods"
     */
    void PutProcessGroupIndex(const std::string &ioName, const std::string hostLanguage,
                              const std::vector<std::string> &transportsTypes) noexcept;

    /**
     * Put in buffer metadata for a given variable
     */
    template <class T>
    void PutVariableMetadata(const core::Variable<T> &variable,
                             const typename core::Variable<T>::BPInfo &blockInfo,
                             const bool sourceRowMajor = true,
                             typename core::Variable<T>::Span *span = nullptr) noexcept;

    /**
     * Put in buffer variable payload. Expensive part.
     * @param variable payload input from m_PutValues
     */
    template <class T>
    void PutVariablePayload(const core::Variable<T> &variable,
                            const typename core::Variable<T>::BPInfo &blockInfo,
                            const bool sourceRowMajor = true,
                            typename core::Variable<T>::Span *span = nullptr) noexcept;

    template <class T>
    void PutSpanMetadata(const core::Variable<T> &variable,
                         const typename core::Variable<T>::Span &span) noexcept;

    /**
     * Serializes the metadata indices appending it into the data buffer inside
     * m_Data
     * @param updateAbsolutePosition true: adds footer size to absolute position
     * used for Close,
     * false: doesn't update absolute, used for partial buffer
     * @param inData true: serialize in data , false: only update metadata
     * indices, do not serialize in data
     */
    void SerializeMetadataInData(const bool updateAbsolutePosition = true,
                                 const bool inData = true);

    /**
     * Finishes bp buffer by serializing data and adding trailing metadata
     * @param io
     */
    void CloseData(core::IO &io);

    /**
     * Closes bp buffer for streaming mode...must reset metadata for the next
     * step
     * @param io object containing all attributes
     * @param addMetadata true: process metadata and add to data buffer
     * (minifooter)
     */
    void CloseStream(core::IO &io, const bool addMetadata = true);
    void CloseStream(core::IO &io, size_t &metadataStart, size_t &metadataCount,
                     const bool addMetadata = true);

    void ResetIndices();

    /**
     * Aggregate collective metadata
     * @param comm input establishing domain (all or per aggregator)
     * @param bufferSTL buffer to put the metadata
     * @param inMetadataBuffer collective metadata from absolute rank = 0, else
     *                         from aggregators
     */
    void AggregateCollectiveMetadata(helper::Comm const &comm, BufferSTL &bufferSTL,
                                     const bool inMetadataBuffer);

private:
    std::vector<char> m_SerializedIndices;
    std::vector<char> m_GatheredSerializedIndices;

    /** aggregate pg rank indices */
    std::vector<char> m_PGRankIndices;
    /** deserialized variable indices per rank (vector index) */
    std::unordered_map<std::string, std::vector<BPBase::SerialElementIndex>> m_VariableRankIndices;
    /** deserialized attribute indices per rank (vector index) */
    std::unordered_map<std::string, std::vector<BPBase::SerialElementIndex>>
        m_AttributesRankIndices;

    /**
     * Put in BP buffer attribute header, called from PutAttributeInData
     * specialized functions
     * @param attribute input
     * @param stats BP3 Stats
     * @return attribute length position
     */
    template <class T>
    size_t PutAttributeHeaderInData(const core::Attribute<T> &attribute, Stats<T> &stats) noexcept;

    /**
     * Called from WriteAttributeInData specialized functions
     * @param attribute input
     * @param stats BP3 stats
     * @param attributeLengthPosition
     */
    template <class T>
    void PutAttributeLengthInData(const core::Attribute<T> &attribute, Stats<T> &stats,
                                  const size_t attributeLengthPosition) noexcept;

#define declare_template_instantiation(T)                                                          \
    void DoPutAttributeInData(const core::Attribute<T> &attribute, Stats<T> &stats) noexcept final;
    ADIOS2_FOREACH_ATTRIBUTE_STDTYPE_1ARG(declare_template_instantiation)
#undef declare_template_instantiation

    template <class T>
    void PutAttributeInDataCommon(const core::Attribute<T> &attribute, Stats<T> &stats) noexcept;

    /**
     * Get variable statistics
     * @param variable
     * @param isRowMajor
     * @return stats BP3 Stats
     */
    template <class T>
    Stats<T> GetBPStats(const bool singleValue, const typename core::Variable<T>::BPInfo &blockInfo,
                        const bool isRowMajor) noexcept;

    template <class T>
    void PutVariableMetadataInData(const core::Variable<T> &variable,
                                   const typename core::Variable<T>::BPInfo &blockInfo,
                                   const Stats<T> &stats,
                                   const typename core::Variable<T>::Span *span = nullptr) noexcept;

    template <class T>
    void PutVariableMetadataInIndex(const core::Variable<T> &variable,
                                    const typename core::Variable<T>::BPInfo &blockInfo,
                                    const Stats<T> &stats, const bool isNew,
                                    BPBase::SerialElementIndex &index,
                                    typename core::Variable<T>::Span *span) noexcept;

    template <class T>
    void PutVariableCharacteristics(const core::Variable<T> &variable,
                                    const typename core::Variable<T>::BPInfo &blockInfo,
                                    const Stats<T> &stats, std::vector<char> &buffer,
                                    typename core::Variable<T>::Span *span) noexcept;

    template <class T>
    void PutVariableCharacteristics(const core::Variable<T> &variable,
                                    const typename core::Variable<T>::BPInfo &blockInfo,
                                    const Stats<T> &stats, std::vector<char> &buffer,
                                    size_t &position) noexcept;

    /** Writes min max */
    template <class T>
    void PutBoundsRecord(const bool singleValue, const Stats<T> &stats,
                         uint8_t &characteristicsCounter, std::vector<char> &buffer) noexcept;

    /** Overloaded version for data buffer */
    template <class T>
    void PutBoundsRecord(const bool singleValue, const Stats<T> &stats,
                         uint8_t &characteristicsCounter, std::vector<char> &buffer,
                         size_t &position) noexcept;

    /**
     * Wraps up the data buffer serialization in m_HeapBuffer and fills the pg
     * length, vars count, vars
     * length and attributes count and attributes length
     * @param io object containing all attributes
     */
    void SerializeDataBuffer(core::IO &io) noexcept final;

    /**
     * Refactored function that reduces the communication at scale by just
     * calling a Gather/GatherV pair once for all indices
     * @param comm
     * @param bufferSTL
     * @param inMetadataBuffer
     * @return contains indices positions in buffer
     */
    std::vector<size_t> AggregateCollectiveMetadataIndices(helper::Comm const &comm,
                                                           BufferSTL &bufferSTL);
};

} // end namespace format
} // end namespace adios2

#endif /* ADIOS2_UTILITIES_FORMAT_BP3_BP3Serializer_H_ */
