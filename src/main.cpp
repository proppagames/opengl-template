#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "App.h" 
#include "ResourceManager.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

unsigned int defaultScreenWidth = 800;
unsigned int defaultScreenHeight = 450;
App* app = new App(defaultScreenWidth, defaultScreenHeight);

int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(defaultScreenWidth, defaultScreenHeight, "app", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std:: cout << "glad failed init " << std::endl;
    }

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    app->initialize();
    float prevTime = 0.0f;
    float dt = 0.0f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        float currTime = glfwGetTime();
        dt = currTime - prevTime;
        prevTime = currTime;

        /* Poll for and process events */
        glfwPollEvents();

        app->update(dt);

        /* Render here */
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        app->render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

    }

    ResourceManager::deleteResources();
    delete app;

    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {

}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {

}
