#include "aiv-cunit.h"
#include "wobj.h"

CUNIT_TEST(test_example) {
    CUNIT_INT_EQ(0, 1 - 1);
    CUNIT_FLOAT_EQ(0.f,  1.001f - 1.f);
    CUNIT_IS_TRUE(1);
}
