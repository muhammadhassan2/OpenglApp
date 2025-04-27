//
//  Camera.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 27/04/2025.
//

#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<memory>
#include "Shader.hpp"
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include "Window.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
class Camera{
    
public:
    glm::vec3 camera_position;
    glm::vec3 camera_oriantation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
    
    int width ;
    int height;
    float speed = 0.1f ;
    float sensitivity = 100.f;
    Camera(int width , int height , glm::vec3 pos);
    void Matrix(float FVOdeg , float near , float far , std::shared_ptr<Shader>& shader,const char*uniform);
    bool firstClick = true;
    void inputs(std::shared_ptr<Window>&window);
private:
    
    
};
