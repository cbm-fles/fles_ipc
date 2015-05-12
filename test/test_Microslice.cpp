#define BOOST_TEST_MODULE test_Microslice
#include <boost/test/unit_test.hpp>

#include "StorableMicroslice.hpp"
#include <array>

struct F {
    F()
    {
        // initialize microslice descriptor (for individual meaning cf.
        // MicrosliceDescriptor.hpp)
        desc0.hdr_id = 0xDD;
        desc0.hdr_ver = 0x01;
        desc0.sys_id = 0xFF;
        desc0.sys_ver = 1;
        desc0.eq_id = 10;
        desc0.idx = 1;
        desc0.size = static_cast<uint32_t>(data0.size());
    }

    const std::array<uint8_t, 4> data0{{7, 13, 12, 8}};

    fles::MicrosliceDescriptor desc0 = fles::MicrosliceDescriptor();
};

BOOST_FIXTURE_TEST_CASE(constructors_test, F)
{
    fles::StorableMicroslice m1(desc0, data0.data());

    std::vector<uint8_t> v{data0.begin(), data0.end()};
    fles::StorableMicroslice m2(desc0, v);

    BOOST_CHECK_EQUAL(m1.desc().eq_id, 10);
    BOOST_CHECK_EQUAL(m2.desc().eq_id, 10);
    BOOST_CHECK_EQUAL(*m1.content(), 7);
    BOOST_CHECK_EQUAL(*m2.content(), 7);
}
