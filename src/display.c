#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "utilities.h"

typedef struct
{
    float x, y;
    float r, g, b;
} Vertice;

static const Vertice vertices[3] =
{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f }
};

static void close_callback(GLFWwindow* window);
static void error_callback(int error, const char* description);

int main(int argc, char const *argv[])
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

        // Sets a minimum context version for the OpenGL that are created
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    window = glfwCreateWindow(640, 320, extract_name(argv[0]), NULL, NULL);
    if (!window)
    {
        // OpenGL context creation failed 😟
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    // Sets the close callback for the window
    glfwSetWindowCloseCallback(window, close_callback);
    
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Destroys OpenGL context
    glfwDestroyWindow(window);
 
    // Terminates glfw before we exit the application
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

static void error_callback(int error, const char* description)
{
#ifdef _DEBUG
    write_log(description);
#endif
    exit(EXIT_FAILURE);
}

static void close_callback(GLFWwindow* window)
{
    printf("Window closed!");
}
