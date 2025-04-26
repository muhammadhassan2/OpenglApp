//
//  Window.cpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#include "Window.hpp"
#include <iostream>
Window::Window(const char *Title , GLuint width , GLuint height) :Title{Title} , width{width},height{height}{
    std::cout<<"CONSTRUCTOR/n";
    setWindowConfiguration();
    InitiateWindow();
}

State Window::InitiateWindow(){
    
    mWindow = glfwCreateWindow(width, height, Title, NULL, NULL);
    
    if(mWindow == nullptr){
        return State::FAILED;
    }
    
    glfwMakeContextCurrent(mWindow);
    glewExperimental = GL_TRUE;
    
    setViewPort(0, 0, width, height);
    return State::SUCESS;
}

void Window::setWindowConfiguration(){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
}

void Window::setViewPort(int x , int y ,GLuint width ,GLuint height){
    glViewport(x, y, width, height);
}

bool Window::shouldClose(){
    return glfwWindowShouldClose(mWindow);
}

void Window::swapBuffers() const{
    glfwSwapBuffers(mWindow);
}

void Window::destroy() const {
    
    glfwDestroyWindow(mWindow);
    glfwTerminate();
    
}

bool Window::hasCurrentContext() {
    return glfwGetCurrentContext() == mWindow;
}

void Window::bindContext(){
    glfwMakeContextCurrent(mWindow);
}

void Window::run(){
    while(!glfwWindowShouldClose(mWindow)){
            glClearColor(0.3, .43, .2, 1.0); // setting the window background color
    
            glClear(GL_COLOR_BUFFER_BIT); // clear the current buffer color to apply the new one
            glfwSwapBuffers(mWindow); // apply double buffering to swap buffers on screen
    
            glfwPollEvents();
        }
}
