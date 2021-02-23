#pragma once
// #include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    float *vertices;
    float *uvs;
    float *normals;
    int *faces;

    int vertices_size;
    int vertices_count;
    int uvs_size;
    int uvs_count;
    int normals_size;
    int normals_count;
    int faces_size;
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
        if(strncmp(buffer, "v ", 2) ==0){
            w->vertices_count += 1;
        }else if(strncmp(buffer, "vt ", 3)==0){
            w->uvs_count += 1;
        }
    }

    rewind(file);

    w->vertices_size = w->vertices_count*3;
    w->uvs_size = w->uvs_count*2;
    w->vertices = malloc(sizeof(float) * w->vertices_size);
    w->uvs = malloc(sizeof(float)*w->uvs_size);
    int vert_index = 0;
    int uv_index= 0;
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
        }else if (strcmp(token, "vt") == 0 ){
            char* uv; 
            uv = strtok_s(NULL, " ", &next_token);
            float uv_val = atof(uv);
            w->uvs[uv_index + 0] = uv_val;

            uv = strtok_s(NULL, " ", &next_token);
            uv_val = atof(uv);
            w->uvs[uv_index + 1] = uv_val;

            uv_index +=2;
        }
    }

    fclose(file);

    return w;
}