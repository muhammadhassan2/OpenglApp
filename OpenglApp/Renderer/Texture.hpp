//
//  Texture.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include "Shader.hpp"
#include <memory>
class Texture{
    
public:
    Texture(const char* path ,GLenum texture_type , GLuint slot ,GLenum format , GLenum pixeltype );
    void bind();
    void unbind();
    void Delete();
    void texUnit(std::shared_ptr<Shader> &shader, const char* uniform, GLuint unit);
private:
    GLuint texId;
    int width , height , channels;
};
