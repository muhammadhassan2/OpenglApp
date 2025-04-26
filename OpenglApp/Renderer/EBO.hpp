//
//  EBO.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//
#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
class EBO{
    
public:
    EBO(GLuint *vertices ,GLsizeiptr size);
    void bind();
    void unbind();
    void deletebuffer();
    
private:
    
    GLuint Ebo;
};
