// Copyright 2013 Jan de Cuveland <cmail@cuveland.de>
#pragma once

#include "TimesliceDescriptor.hpp"
#include <cstdint>
#include <boost/serialization/access.hpp>

namespace fles
{

#pragma pack(1)

/**
 * \brief %Timeslice work item struct.
 */
struct TimesliceWorkItem {
    /// The timeslice descriptor
    TimesliceDescriptor ts_desc;
    /// Size exponential (in bytes) of each data buffer
    uint32_t data_buffer_size_exp;
    /// Size exponential (in bytes) of each descriptor buffer
    uint32_t desc_buffer_size_exp;

    friend class boost::serialization::access;
    /// Provide boost serialization access.
    template <class Archive>
    void serialize(Archive& ar, const unsigned int /* version */)
    {
        ar& ts_desc;
        ar& data_buffer_size_exp;
        ar& desc_buffer_size_exp;
    }
};

#pragma pack()

} // namespace fles {
