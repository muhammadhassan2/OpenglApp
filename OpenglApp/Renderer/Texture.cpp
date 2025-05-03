//
//  Texture.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#include "Texture.hpp"
#include "stb_image.h"
#include <iostream>
Texture::Texture(const char* path ,GLenum texture_type , GLuint slot ,GLenum format , GLenum pixeltype ){
    
    unsigned char *bytes = stbi_load(path ,&width,&height,&channels,0);
    
    glGenTextures(1, &texId);
   
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D,texId);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    
    glTexImage2D(GL_TEXTURE_2D, 0 , format, width, height , 0, format, pixeltype, bytes);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    // Deletes the image data as it is already in the OpenGL Texture object
    stbi_image_free(bytes);
    
}
void Texture::texUnit(std::shared_ptr<Shader> &shader, const char* uniform, GLuint unit)
{
    // Gets the location of the uniform
    std::cout<<"program id = "<<shader->getProgramID()<<std::endl;;
    GLuint texUni = glGetUniformLocation(shader->getProgramID(), uniform);
    // Shader needs to be activated before changing the value of a uniform
    shader->activate();
    // Sets the value of the uniform
    glUniform1i(texUni, unit);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, texId);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &texId);
}
GLuint Texture::get_id(){
    return texId;
}
