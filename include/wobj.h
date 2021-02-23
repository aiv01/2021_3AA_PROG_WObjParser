#pragma once
// #include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

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
    w->vertices_count = 0;
    w->uvs_count = 0;
    FILE* file = fopen(file_path, "r");
    if(file == NULL){
        return NULL;
    }

    //read to populate array size (vertex, uv...)
    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), file)){
        if(strncmp(buffer, "v ", 2)){
            w->vertices_count += 1;
        }
    }

    rewind(file);

    w->vertices = malloc(sizeof(float) * w->vertices_count);
    int vert_index = 0;
    while(fgets(buffer, sizeof(buffer), file)){
        char* next_token;
        char* token = strtok_s(buffer, " ", &next_token); //v 1.0000 -1.0000 0.0000\n
        if(strcmp(token, "v") == 0){
            //vertex 0
            char* vert;
            vert = strtok_s(NULL, " ", &next_token);
            float vert_val = atof(vert);
            w->vertices[vert_index + 0] = vert_val;
            // vert 1
            vert = strtok_s(NULL, " ", &next_token);
            vert_val = atof(vert);
            w->vertices[vert_index + 1] = vert_val;

            //vert 2
            vert = strtok_s(NULL, " ", &next_token);
            vert_val = atof(vert);
            w->vertices[vert_index + 2] = vert_val;

            vert_index += 3;
        }
    }

    fclose(file);

    return w;
}