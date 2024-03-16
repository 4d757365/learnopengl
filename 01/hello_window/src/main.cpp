#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "config.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main(void)
{
    // initalize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // create window
    GLFWwindow *window = glfwCreateWindow(800, 600, "Hello Window", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // check if GLAD is initalized
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to intialize GLAD" << std::endl;
    }

    // rendering window
    glViewport(0, 0, 800, 600);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // check for input
        processInput(window);
        // render color
        glClearColor(0.2f, 0.3f, 0.8f, 0.2f);
        glClear(GL_COLOR_BUFFER_BIT);
        // swap color buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // terminate glfw
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}