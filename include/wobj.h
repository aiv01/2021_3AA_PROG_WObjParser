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
    w->normals_count = 0;
    w->faces_count = 0;
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
        }else if(strncmp(buffer, "vn ", 3)==0){
            w->normals_count += 1;
        }
        else if(strncmp(buffer, "f ", 2)==0){
            w->faces_count += 1;
        }
    }

    rewind(file);

    w->vertices_size = w->vertices_count*3;
    w->uvs_size = w->uvs_count*2;
    w->normals_size = w->normals_count*3;
    w->faces_size = w->faces_count*9;

    w->vertices = malloc(sizeof(float) * w->vertices_size);
    w->uvs = malloc(sizeof(float)*w->uvs_size);
    w->normals = malloc(sizeof(float)*w->normals_size);
    w->faces = malloc(sizeof(int)*w->faces_size);
    int vert_index = 0;
    int uv_index= 0;
    int normal_index= 0;
    int faces_index= 0;
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
        }else if(strcmp(token, "vn") == 0){
            //vertex 0
            char* norm;
            norm = strtok_s(NULL, " ", &next_token);
            float norm_val = atof(norm);
            w->normals[normal_index + 0] = norm_val;
            // vert 1
            norm = strtok_s(NULL, " ", &next_token);
            norm_val = atof(norm);
            w->normals[normal_index + 1] = norm_val;

            //vert 2
            norm = strtok_s(NULL, " ", &next_token);
            norm_val = atof(norm);
            w->normals[normal_index + 2] = norm_val;

            normal_index += 3;
        }else if(strcmp(token, "f") ==0){
            char* face;
            for (int i = 0; i < 3; i++)
            {
                face = strtok_s(NULL, "/", &next_token);
                int face_val= atoi(face);
                w->faces[faces_index + 0]= face_val;

                face = strtok_s(NULL, "/", &next_token);
                face_val= atoi(face);
                w->faces[faces_index + 1]= face_val;

                face = strtok_s(NULL, " ", &next_token);
                face_val= atoi(face);
                w->faces[faces_index + 2]= face_val;

                faces_index +=3;
            }
            
          
        }
    }

    fclose(file);

    return w;
}

void wobj_destroy(wobj* obj){

    free(obj->faces);
    free(obj->vertices);
    free(obj->normals);
    free(obj->uvs);
    free(obj);
}