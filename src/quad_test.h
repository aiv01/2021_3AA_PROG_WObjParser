#include "aiv-cunit.h"
#include "wobj.h"

CUNIT_TEST(test_quad_vertices)
{
    wobj *quad = wobj_from_file("resources/quad.obj");

    CUNIT_INT_EQ(12, quad->vertices_size);
    CUNIT_INT_EQ(4, quad->vertices_count);

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
    wobj_destroy(quad);
}

CUNIT_TEST(test_quad_uvs)
{
    wobj *quad = wobj_from_file("resources/quad.obj");

    CUNIT_INT_EQ(8, quad->uvs_size);
    CUNIT_INT_EQ(4, quad->uvs_count);

    CUNIT_FLOAT_EQ(1.f, quad->uvs[0]);
    CUNIT_FLOAT_EQ(1.f, quad->uvs[1]);

    CUNIT_FLOAT_EQ(0.f, quad->uvs[2]);
    CUNIT_FLOAT_EQ(1.f, quad->uvs[3]);

    CUNIT_FLOAT_EQ(0.f, quad->uvs[4]);
    CUNIT_FLOAT_EQ(0.f, quad->uvs[5]);

    CUNIT_FLOAT_EQ(1.f, quad->uvs[6]);
    CUNIT_FLOAT_EQ(0.f, quad->uvs[7]);
    wobj_destroy(quad);

}


CUNIT_TEST(test_quad_normals)
{
    wobj *quad = wobj_from_file("resources/quad.obj");

    CUNIT_INT_EQ(3, quad->normals_size);
    CUNIT_INT_EQ(1, quad->normals_count);

    CUNIT_FLOAT_EQ(0.f, quad->normals[0]);
    CUNIT_FLOAT_EQ(0.f, quad->normals[1]);
    CUNIT_FLOAT_EQ(1.f, quad->normals[2]);

    wobj_destroy(quad);
   
}

CUNIT_TEST(test_quad_faces)
{
    wobj *quad = wobj_from_file("resources/quad.obj");

    CUNIT_INT_EQ(2, quad->faces_count);
    CUNIT_INT_EQ(18, quad->faces_size);

    CUNIT_INT_EQ(4, quad->faces[0]);
    CUNIT_INT_EQ(4, quad->faces[1]);
    CUNIT_INT_EQ(1, quad->faces[2]);

    CUNIT_INT_EQ(3, quad->faces[3]);
    CUNIT_INT_EQ(3, quad->faces[4]);
    CUNIT_INT_EQ(1, quad->faces[5]);
    
    CUNIT_INT_EQ(1, quad->faces[6]);
    CUNIT_INT_EQ(2, quad->faces[7]);
    CUNIT_INT_EQ(1, quad->faces[8]);
    
    CUNIT_INT_EQ(2, quad->faces[9]);
    CUNIT_INT_EQ(1, quad->faces[10]);
    CUNIT_INT_EQ(1, quad->faces[11]);

    CUNIT_INT_EQ(4, quad->faces[12]);
    CUNIT_INT_EQ(4, quad->faces[13]);
    CUNIT_INT_EQ(1, quad->faces[14]);
    
    CUNIT_INT_EQ(1, quad->faces[15]);
    CUNIT_INT_EQ(2, quad->faces[16]);
    CUNIT_INT_EQ(1, quad->faces[17]);
    
    wobj_destroy(quad);
}

CUNIT_TEST(test_quad_triangle){
    wobj *quad = wobj_from_file("resources/quad.obj");
    CUNIT_INT_EQ(2, quad->triangles_count);

    //t1 v1
    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v1.position.x);
    CUNIT_FLOAT_EQ(-1.f, quad->triangles[0].v1.position.y);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v1.position.z);

    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v1.uv.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v1.uv.y);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v1.normal.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v1.normal.y);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v1.normal.z);

    //t1 v2
    CUNIT_FLOAT_EQ(-1.f, quad->triangles[0].v2.position.x);
    CUNIT_FLOAT_EQ(-1.f, quad->triangles[0].v2.position.y);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v2.position.z);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v2.uv.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v2.uv.y);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v2.normal.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v2.normal.y);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v2.normal.z);

    //t1 v3
    CUNIT_FLOAT_EQ(-1.f, quad->triangles[0].v3.position.x);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v3.position.y);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v3.position.z);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v3.uv.x);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v3.uv.y);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v3.normal.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[0].v3.normal.y);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[0].v3.normal.z);

    //t2 v1
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v1.position.x);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v1.position.y);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v1.position.z);

    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v1.uv.x);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v1.uv.y);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v1.normal.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v1.normal.y);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v1.normal.z);

    //t2 v2
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v2.position.x);
    CUNIT_FLOAT_EQ(-1.f, quad->triangles[1].v2.position.y);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v2.position.z);

    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v2.uv.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v2.uv.y);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v2.normal.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v2.normal.y);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v2.normal.z);

    //t2 v3
    CUNIT_FLOAT_EQ(-1.f, quad->triangles[1].v3.position.x);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v3.position.y);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v3.position.z);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v3.uv.x);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v3.uv.y);

    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v3.normal.x);
    CUNIT_FLOAT_EQ(0.f, quad->triangles[1].v3.normal.y);
    CUNIT_FLOAT_EQ(1.f, quad->triangles[1].v3.normal.z);


    wobj_destroy(quad);
}


