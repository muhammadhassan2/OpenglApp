//
//  VBO.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#include "VBO.hpp"

VBO::VBO(GLfloat *vertices , GLsizeiptr size){
    
    glGenBuffers(1,&Vbo);
    glBindBuffer(GL_ARRAY_BUFFER,Vbo);
    glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
}

void VBO::bind(){
    glBindBuffer(GL_ARRAY_BUFFER,Vbo);
}

void VBO::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
void VBO::deletebuffer(){
    glDeleteBuffers(1,&Vbo);
}
