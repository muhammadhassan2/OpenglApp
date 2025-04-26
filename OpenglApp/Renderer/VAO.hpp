//
//  VAO.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//
#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
class VAO{
    
    
public:
    VAO();
    void bind();
    void unbind();
    void activate(GLuint layout , GLuint size , GLenum type , GLboolean normalize , GLuint stride ,void* start);
    
private:
    
    GLuint Vao;
};
