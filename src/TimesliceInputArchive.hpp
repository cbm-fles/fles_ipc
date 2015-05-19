// Copyright 2013 Jan de Cuveland <cmail@cuveland.de>
#pragma once

#include "TimesliceSource.hpp"
#include "ArchiveDescriptor.hpp"
#include "StorableTimeslice.hpp"
#include <string>
#include <fstream>
#include <memory>
#include <boost/archive/binary_iarchive.hpp>

namespace fles
{

//! The TimesliceInputArchive deserializes timeslice data sets from an input
// file.
class TimesliceInputArchive : public TimesliceSource
{
public:
    TimesliceInputArchive(const std::string& filename);

    TimesliceInputArchive(const TimesliceInputArchive&) = delete;
    void operator=(const TimesliceInputArchive&) = delete;

    virtual ~TimesliceInputArchive(){};

    /// Read the next timeslice.
    std::unique_ptr<StorableTimeslice> get()
    {
        return std::unique_ptr<StorableTimeslice>(do_get());
    };

    const ArchiveDescriptor& descriptor() const { return _descriptor; };

private:
    virtual StorableTimeslice* do_get();

    std::unique_ptr<std::ifstream> _ifstream;
    std::unique_ptr<boost::archive::binary_iarchive> _iarchive;
    ArchiveDescriptor _descriptor;
};

} // namespace fles {
