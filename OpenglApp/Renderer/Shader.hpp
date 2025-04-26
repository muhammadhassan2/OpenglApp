//
//  Shader.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//
#pragma once
#include "Shaders/Shaders.h"

#define GLEW_STATIC // this tells the compiler that we want to use static linking instead of dynamic linking
#include <GL/glew.h>  // Include GLEW before GLFW
#include <GLFW/glfw3.h>

class Shader{
    
public:
    Shader();
    Shader(const char *vertexShader , const char *fragmentShader);
    void initiate();
    void activate();
    void deleteprogram();
    void changeFragmentShader(const char *newShader);
    void changeVertexShader(const char *newShader);
    GLuint vertex;
    GLuint fragment;
    GLuint getProgramID();
private:
    const char *vertex_shader ;
    const char *fragment_shader;
    GLuint programID;
};
