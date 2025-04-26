//
//  Shader.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#include "Shader.hpp"
#include <iostream>
Shader::Shader(){
    this->vertex_shader = defaultVertexShader;
    this->fragment_shader = defaultFragmentShader;
    
    this->initiate();

}

Shader::Shader(const char *vertexshader , const char *framgentshader){
    this->vertex_shader = vertexshader;
    std::cout<<vertexshader;
    this->fragment_shader = framgentshader;
    this->initiate();
}

void Shader::initiate(){
    this->vertex = glCreateShader(GL_VERTEX_SHADER);
    this->fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertex , 1,&this->vertex_shader,NULL);
    glShaderSource(fragment,1,&this->fragment_shader,NULL);
    
    glCompileShader(vertex);
    glCompileShader(fragment);
    
    int success;
    char infoLog[512];
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    
    programID = glCreateProgram();
    
    glAttachShader(programID , vertex);
    glAttachShader(programID,fragment);
    
    glLinkProgram(programID);
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::changeFragmentShader(const char *newShader){
    
    this->fragment_shader = newShader;
    deleteprogram();
    initiate();
}
void Shader::changeVertexShader(const char *newShader){
    this->vertex_shader = newShader;
    deleteprogram();
    initiate();
}

void Shader::activate(){
    glUseProgram(programID);
}

void Shader::deleteprogram(){
    glDeleteProgram(programID);
}

GLuint Shader::getProgramID(){
    return programID;
}
