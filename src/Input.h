#ifndef INPUT_H
#define INPUT_H

#define GLEW_STATIC
#include <GLFW/glfw3.h>

class Input {
private:
    static const unsigned int GLFW_KEY_COUNT;
    static bool activeKeys[];
    static GLFWwindow *window;
public:
    static void Create(GLFWwindow *window);

    static void Update();

    static bool GetKey(int keyCode);
    static bool GetKeyDown(int keyCode);
    static bool GetKeyUp(int keyCode);
};

#endif

