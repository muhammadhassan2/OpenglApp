//
//  EBO.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#include "EBO.hpp"

EBO::EBO(GLuint *vertices , GLsizeiptr size){
    
    glGenBuffers(1,&Ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,Ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
}

void EBO::bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,Ebo);
}

void EBO::unbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
void EBO::deletebuffer(){
    glDeleteBuffers(1,&Ebo);
}
