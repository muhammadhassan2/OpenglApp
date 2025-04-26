//
//  VAO.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#include "VAO.hpp"

VAO::VAO(){
    glGenVertexArrays(1,&Vao);
}

void VAO::bind(){
    glBindVertexArray(Vao);
}

void VAO::unbind(){
    glBindVertexArray(0);
}
void VAO::activate(GLuint layout , GLuint size , GLenum type , GLboolean normalize , GLuint stride ,void* start){
    
    glVertexAttribPointer(layout , size , type , normalize , stride , start);
    glEnableVertexAttribArray(layout);
}
