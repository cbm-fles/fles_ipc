#pragma once

#include "MicrosliceDescriptor.hpp"
#include <vector>

namespace fles {

/**
 * Store microslice metadata and content in a single object.
 */
struct MicrosliceContainer {
    MicrosliceContainer(const MicrosliceView& mc);

    MicrosliceContainer(MicrosliceDescriptor d, const uint8_t *content);
    /**<
     * Copy the descriptor and the data pointed to by `content` into the
     * MicrosliceContainer. The `size` field of the descriptor must already
     * be valid and will not be modified.
     */

    MicrosliceContainer(MicrosliceDescriptor d, std::vector<uint8_t> content);
    /**<
     * Copy the descriptor and copy or move the data contained in
     * `content` into the MicrosliceContainer. The descriptor will be
     * updated to match the size of the `content` vector.
     *
     * Copying the vector is avoided if it is passed as an rvalue,
     * like in
     *     MicrosliceContainer {..., std::move(some_vector)}
     * or
     *     MicrosliceContainer {..., {1, 2, 3, 4, 5}}
     * or
     *     MicrosliceContainer {..., create_some_vector()}
     */

    const MicrosliceDescriptor& desc() { return _desc; };
    const uint8_t *content() { return _content.data(); };

private:
    MicrosliceDescriptor _desc;
    std::vector<uint8_t> _content;
};

}
