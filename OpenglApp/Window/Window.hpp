//
//  Window.hpp
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//



#ifndef WINDOW_HPP
#define WINDOW_HPP
#define GLFW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
enum class State{SUCESS ,FAILED};

class Window{
    
public:
    Window(const char *Title , GLuint width , GLuint Height);
    
    State InitiateWindow();
    void setViewPort(int x ,int y , GLuint width , GLuint height);
    bool shouldClose() ;
    void destroy() const;
    void swapBuffers() const;
    bool hasCurrentContext();
    void bindContext();
    GLFWwindow* getGLFWwindow() const { return mWindow; }
    void run();
private:
    void setWindowConfiguration();
    const char *Title ;
    GLuint width ;
    GLuint height;
    GLFWwindow *mWindow ;
};

#endif
