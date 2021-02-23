#pragma once
// #include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float *vertices;
    float *uvs;
    float *normals;
    int *faces;

    int vertices_count;
    int uvs_count;
    int normals_count;
    int faces_count;

} wobj;

wobj* wobj_from_file(const char* file_path)
{

wobj *w = (wobj*)malloc(sizeof(wobj));



return w;


}