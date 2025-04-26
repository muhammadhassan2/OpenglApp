//
//  VBO.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

class VBO{
    
public:
    VBO(GLfloat *vertices ,GLsizeiptr size);
    void bind();
    void unbind();
    void deletebuffer();
    
private:
    
    GLuint Vbo;
};
