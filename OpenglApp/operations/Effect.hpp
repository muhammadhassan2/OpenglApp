//
//  Effect.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 27/04/2025.
//
#pragma once
#define GLEW_STATIC
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Renderer/Texture.hpp"
#include "../Renderer/EBO.hpp"
#include "../Renderer/VBO.hpp"
#include "../Renderer/VAO.hpp"
#include "../Renderer/Shader.hpp"
#include <memory>
static const GLfloat vertecies1 [] = {
     
     -0.5f, -0.5f, 0.0f,        0.0f , 0.0f,  // top right    (vertex 0)
     -0.5f,  0.5f, 0.0f,        0.0f , 1.0f,  // bottom right (vertex 1)
      0.5f,  0.5f, 0.0f,        1.0f , 1.0f,  // bottom left  (vertex 2)
      0.5f, -0.5f, 0.0f,        1.0f , 0.0f   // top left     (vertex 3)
 };

const GLuint indecies1 [] = {
   0 ,2 ,1,
   0,3,2
 };

class Effect{
      
    
public:
  //  Effect(const char *fragmentShader);
    void Run(GLuint frame);
private:
    GLuint texnum;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<VBO> Vbo;
    std::shared_ptr<VAO> Vao;
    std::shared_ptr<EBO> Ebo;
    std::shared_ptr<Texture> texture;
};
