// Copyright 2013 Jan de Cuveland <cmail@cuveland.de>

#include "StorableTimeslice.hpp"

namespace fles
{

StorableTimeslice::StorableTimeslice(const Timeslice& ts)
    : _data(ts._data),
      _desc(ts._desc)
{
    init_pointers();
}

StorableTimeslice::StorableTimeslice(Timeslice&& ts)
    : _data(std::move(ts._data)),
      _desc(std::move(ts._desc))
{
    init_pointers();
}

StorableTimeslice::StorableTimeslice() {}

} // namespace fles {
