//
//  main.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#define GLEW_STATIC // this tells the compiler that we want to use static linking instead of dynamic linking
#include <GL/glew.h>  // Include GLEW before GLFW
#include <GLFW/glfw3.h>
#include <memory>
#include <map>

#include "Renderer/Shaders/Shaders.h"
#include "Window/Window.hpp" // for window handeling
#include "Renderer/Shader.hpp" // for shaders
#include "Renderer/VAO.hpp"
#include "Renderer/EBO.hpp"
#include "Renderer/VBO.hpp"
#include "Renderer/Texture.hpp"

// this is for glm
#include <./glm/glm.hpp>
#include <./glm/gtc/matrix_transform.hpp>
#include <./glm/gtc/type_ptr.hpp>

constexpr GLuint width = 720;
constexpr GLuint height = 720;


GLfloat vertecies [] ={
    
    -0.5f, -0.5f, 0.0f,        0.0f , 0.0f,  // top right    (vertex 0)
    -0.5f,  0.5f, 0.0f,        0.0f , 1.0f,  // bottom right (vertex 1)
     0.5f,  0.5f, 0.0f,        1.0f , 1.0f,  // bottom left  (vertex 2)
     0.5f, -0.5f, 0.0f,        1.0f , 0.0f   // top left     (vertex 3)
};

GLuint indecies [] = {
  0 ,2 ,1,
  0,3,2
};

struct textureInfo{
    const char* path;
    GLuint texturetype;
    GLuint slot;
    GLenum format;
    GLenum pixeltype;
    
    textureInfo(const char*path ,GLuint type , GLuint slot , GLenum format ,GLenum pixeltype) :path(path) ,
    slot{slot},texturetype(type),format(format),pixeltype(pixeltype){
        
    }
};

int main(int argc, const char * argv[]) {

    std::shared_ptr<Window> mWindow = std::make_shared<Window>("My Window",width,height);
    
    mWindow->bindContext(); //  just rely on the context being already active

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW initialization failed!" << std::endl;
        return -1;
    }
    std::shared_ptr<Shader> shader = std::make_shared<Shader>(defaultVertexShader , defaultFragmentShader);
    
    std::shared_ptr<VAO> Vao = std::make_shared<VAO>();
    Vao->bind();
    std::shared_ptr<VBO> Vbo = std::make_shared<VBO>(vertecies , sizeof(vertecies));
    Vbo->bind();
    std::shared_ptr<EBO> Ebo = std::make_shared<EBO>(indecies,sizeof(indecies));
    Ebo->bind();
    Vao->activate(0, 3, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void*)0);
    Vao->activate(1, 2, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void*)(3*sizeof(float)));
    // The Render LOOP
    
    
    // ================ Handel Textures =========================
    std::map<GLuint,std::pair<Texture,textureInfo>> Textures;

    const char *texturepath1 = "/Users/mohamedhassan/OpenglApp/OpenglApp/Assets/qqq.png";
    const char *texturepath2 = "/Users/mohamedhassan/OpenglApp/OpenglApp/Assets/333.jpg";
    std::shared_ptr<Texture> texture = std::make_shared<Texture>(texturepath1,GL_TEXTURE_2D,0,GL_RGBA,GL_UNSIGNED_BYTE);
    std::shared_ptr<Texture> texture2 = std::make_shared<Texture>(texturepath2,GL_TEXTURE_2D,1,GL_RGB,GL_UNSIGNED_BYTE);
    texture->bind();
    texture->texUnit(shader, "texture0", 0);
    
    texture2->bind();
    texture2->texUnit(shader, "texture1", 1);
    
    //===================================================================================================================
    
    //======== Handel Transformations ===============================
    
   // glm::mat4 
    
    
    //===============================================================
    
    while(!mWindow->shouldClose()){
        float glfwtime = glfwGetTime();

        glClearColor(0.3, .43, .2, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->activate();
        texture->bind();
        texture2->bind();
        Vao->bind();
        shader->activate();
       
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
      //glDrawArrays(GL_TRIANGLES, 0, 3);
        mWindow->swapBuffers();
        glfwPollEvents();
    }
    
    mWindow->destroy();
    glfwTerminate();
    return 0;
}
