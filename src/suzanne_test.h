#include "aiv-cunit.h"
#include "wobj.h"

CUNIT_TEST(test_suzanne_info)
{
    wobj *obj = wobj_from_file("resources/suzanne.obj");

    CUNIT_INT_EQ(511, obj->vertices_count);
    CUNIT_INT_EQ(1533, obj->vertices_size);
    CUNIT_INT_EQ(590, obj->uvs_count);
    CUNIT_INT_EQ(1180, obj->uvs_size);
    CUNIT_INT_EQ(507, obj->normals_count);
    CUNIT_INT_EQ(1521, obj->normals_size);
    CUNIT_INT_EQ(968, obj->faces_count);
    CUNIT_INT_EQ(8712, obj->faces_size);
    CUNIT_INT_EQ(968, obj->triangles_count);
  
    wobj_destroy(obj);
}

