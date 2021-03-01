#include "aiv-cunit.h"
#include "quad_test.h"
#include "suzanne_test.h"


CUNIT_RUNNER(
   test_quad_vertices,
   test_quad_uvs,
   test_quad_normals,
   test_quad_faces, 
   test_quad_triangle,
   test_suzanne_info
)
