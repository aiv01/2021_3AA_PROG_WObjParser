#include "aiv-cunit.h"
#include "wobj.h"

CUNIT_TEST(test_quad_vertices)
{
    wobj *quad = wobj_from_file("resources/quad.obj");

    CUNIT_INT_EQ(12, quad->vertices_count);

    CUNIT_FLOAT_EQ(-1.f, quad->vertices[0]);
    CUNIT_FLOAT_EQ(1.f, quad->vertices[1]);
    CUNIT_FLOAT_EQ(0.f, quad->vertices[2]);

    CUNIT_FLOAT_EQ(1.f, quad->vertices[3]);
    CUNIT_FLOAT_EQ(1.f, quad->vertices[4]);
    CUNIT_FLOAT_EQ(0.f, quad->vertices[5]);

    CUNIT_FLOAT_EQ(-1.f, quad->vertices[6]);
    CUNIT_FLOAT_EQ(-1.f, quad->vertices[7]);
    CUNIT_FLOAT_EQ(0.f, quad->vertices[8]);

    CUNIT_FLOAT_EQ(1.f, quad->vertices[9]);
    CUNIT_FLOAT_EQ(-1.f, quad->vertices[10]);
    CUNIT_FLOAT_EQ(0.f, quad->vertices[11]);
}

CUNIT_TEST(test_quad_uvs)
{
    wobj *quad = wobj_from_file("resources/quad.obj");

    CUNIT_INT_EQ(8, quad->uvs_count);

    CUNIT_FLOAT_EQ(1.f, quad->uvs[0]);
    CUNIT_FLOAT_EQ(1.f, quad->uvs[1]);

    CUNIT_FLOAT_EQ(0.f, quad->uvs[2]);
    CUNIT_FLOAT_EQ(1.f, quad->uvs[3]);

    CUNIT_FLOAT_EQ(0.f, quad->uvs[4]);
    CUNIT_FLOAT_EQ(0.f, quad->uvs[5]);

    CUNIT_FLOAT_EQ(1.f, quad->uvs[6]);
    CUNIT_FLOAT_EQ(0.f, quad->uvs[7]);

}
