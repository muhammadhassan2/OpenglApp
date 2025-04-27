//
//  Camera.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 27/04/2025.
//

#include "Camera.hpp"
#include <iostream>
#include <math.h>
Camera::Camera(int width , int height , glm::vec3 pos) :width(width),height(height),camera_position(pos) {
    
    
}
void Camera::Matrix(float FVOdeg , float near , float far , std::shared_ptr<Shader>& shader ,const char*uniform){
    
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);
    
    
    view = glm::lookAt(camera_position, camera_position + camera_oriantation, camera_up);
    proj = glm::perspective(glm::radians(FVOdeg), float(width / height), near, far);
    

    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), uniform),1 , GL_FALSE,glm::value_ptr(proj * view));
}

void Camera::inputs(std::shared_ptr<Window>&window){
    
    if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_W) == GLFW_PRESS)
        {
            camera_position += speed * camera_oriantation;
        }
        if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_A) == GLFW_PRESS)
        {
            camera_position += speed * -glm::normalize(glm::cross(camera_oriantation, camera_up));
        }
        if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_S) == GLFW_PRESS)
        {
            camera_position += speed * -camera_oriantation;
        }
        if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_D) == GLFW_PRESS)
        {
            camera_position += speed * glm::normalize(glm::cross(camera_oriantation, camera_up));
        }
        if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            camera_position += speed * camera_up;
        }
        if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        {
            camera_position += speed * -camera_up;
        }
        if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            speed = 0.4f;
        }
        else if (glfwGetKey(window->getGLFWwindow(), GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
        {
            speed = 0.1f;
        }


        // Handles mouse inputs
        if (glfwGetMouseButton(window->getGLFWwindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            // Hides mouse cursor
            glfwSetInputMode(window->getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

            // Prevents camera from jumping on the first click
            if (firstClick)
            {
                glfwSetCursorPos(window->getGLFWwindow(), (width / 2), (height / 2));
                firstClick = false;
            }

            // Stores the coordinates of the cursor
            double mouseX;
            double mouseY;
            // Fetches the coordinates of the cursor
            glfwGetCursorPos(window->getGLFWwindow(), &mouseX, &mouseY);

            // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
            // and then "transforms" them into degrees
            float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
            float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

             //Calculates upcoming vertical change in the Orientation
            glm::vec3 newOrientation = glm::rotate(camera_oriantation, glm::radians(-rotX), glm::normalize(glm::cross(camera_oriantation, camera_up)));

            // Decides whether or not the next vertical Orientation is legal or not
            if (abs(glm::angle(newOrientation, camera_up) - glm::radians(90.0f)) <= glm::radians(85.0f))
            {
                camera_oriantation = newOrientation;
            }

           //  Rotates the Orientation left and right
            camera_oriantation = glm::rotate(camera_oriantation, glm::radians(float(-rotY)), camera_up);
            
            // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
            glfwSetCursorPos(window->getGLFWwindow(), (width / 2), (height / 2));
        }
        else if (glfwGetMouseButton(window->getGLFWwindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
        {
            // Unhides cursor since camera is not looking around anymore
            glfwSetInputMode(window->getGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            // Makes sure the next time the camera looks around it doesn't jump
            firstClick = true;
        }
    
}
