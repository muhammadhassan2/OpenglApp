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
#include "Renderer/Camera.hpp"
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

GLfloat vertecies2[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
    -0.5f, 0.0f,  0.5f,       0.0f, 0.0f,
    -0.5f, 0.0f, -0.5f,       5.0f, 0.0f,
     0.5f, 0.0f, -0.5f,        0.0f, 0.0f,
     0.5f, 0.0f,  0.5f,       5.0f, 0.0f,
     0.0f, 0.8f,  0.0f,        2.5f, 5.0f
};

// Indices for vertices order
GLuint indecies2[] =
{
    0, 1, 2,
    0, 2, 3,
    0, 1, 4,
    1, 2, 4,
    2, 3, 4,
    3, 0, 4
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
    std::shared_ptr<VBO> Vbo = std::make_shared<VBO>(vertecies2 , sizeof(vertecies2));
    Vbo->bind();
    std::shared_ptr<EBO> Ebo = std::make_shared<EBO>(indecies2,sizeof(indecies2));
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
    
    //======== Handel Transformations MVP matrix ===============================
    float rotation = glfwGetTime();
    

    
    glEnable(GL_DEPTH_TEST);
    

    
    
    //++++++++++++++++ CAMERA
    glm::vec3 camera_pos = glm::vec3(0.0f , 0.0f,2.0f);
    std::shared_ptr<Camera> camera = std::make_shared<Camera>(int(width) , int(height) ,camera_pos);
    
    
    //===============================================================
    
    while(!mWindow->shouldClose()){
        float glfwtime = glfwGetTime();
        
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);
        
        model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f,1.0f,0.0f));
        
        view = glm::translate(view, glm::vec3(0.0f,-.5f ,-2.0f));
        
        proj = glm::perspective(glm::radians(45.f), float(width/height), .1f, 100.0f);   
        
        int model_location = glGetUniformLocation(shader->getProgramID(),"model");
        int view_location = glGetUniformLocation(shader->getProgramID(),"view");
        int proj_location = glGetUniformLocation(shader->getProgramID(),"proj");
        
        glUniformMatrix4fv(model_location,1,GL_FALSE ,glm::value_ptr(model));
        glUniformMatrix4fv(view_location,1,GL_FALSE ,glm::value_ptr(view));
        glUniformMatrix4fv(proj_location,1,GL_FALSE ,glm::value_ptr(proj));
        
        
        
        camera->inputs(mWindow);
        camera->Matrix(45.0f, .1f, 100.f, shader, "camera");
        
        
        
        glClearColor(0.3, .43, .2, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader->activate();
        texture->bind();
        texture2->bind();
        Vao->bind();
        shader->activate();
       
        glDrawElements(GL_TRIANGLES, sizeof(indecies2) / sizeof(int), GL_UNSIGNED_INT, 0);
      //glDrawArrays(GL_TRIANGLES, 0, 3);
        mWindow->swapBuffers();
        glfwPollEvents();
    }
    
    mWindow->destroy();
    glfwTerminate();
    return 0;
}
