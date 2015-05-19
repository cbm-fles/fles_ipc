// Copyright 2015 Jan de Cuveland <cmail@cuveland.de>
#pragma once

#include "MicrosliceSource.hpp"
#include "ArchiveDescriptor.hpp"
#include "StorableMicroslice.hpp"
#include <string>
#include <fstream>
#include <memory>
#include <boost/archive/binary_iarchive.hpp>

namespace fles
{

//! The MicrosliceInputArchive deserializes microslice data sets from an input
// file.
class MicrosliceInputArchive : public MicrosliceSource
{
public:
    MicrosliceInputArchive(const std::string& filename);

    MicrosliceInputArchive(const MicrosliceInputArchive&) = delete;
    void operator=(const MicrosliceInputArchive&) = delete;

    virtual ~MicrosliceInputArchive(){};

    /// Read the next microslice.
    std::unique_ptr<StorableMicroslice> get()
    {
        return std::unique_ptr<StorableMicroslice>(do_get());
    };

    const ArchiveDescriptor& descriptor() const { return _descriptor; };

private:
    virtual StorableMicroslice* do_get();

    std::unique_ptr<std::ifstream> _ifstream;
    std::unique_ptr<boost::archive::binary_iarchive> _iarchive;
    ArchiveDescriptor _descriptor;
};

} // namespace fles {
