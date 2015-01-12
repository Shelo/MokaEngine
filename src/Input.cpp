#include <iostream>
#include "Input.h"

const unsigned int Input::GLFW_KEY_COUNT = 348;
bool Input::activeKeys[Input::GLFW_KEY_COUNT];
GLFWwindow* Input::window = NULL;

void Input::Create(GLFWwindow *window) {
    for(int i = 0; i < Input::GLFW_KEY_COUNT; i++)
        activeKeys[i] = false;

    Input::window = window;
}

void Input::Update() {
    for(int i = 0; i < Input::GLFW_KEY_COUNT; i++)
        activeKeys[i] = Input::GetKey(i);
}

bool Input::GetKey(int keyCode) {
    if(window == NULL) {
        std::cerr << "Error: window not defined in input." << std::endl;
        return false;
    }

    return glfwGetKey(window, keyCode) == GLFW_PRESS;
}

bool Input::GetKeyDown(int keyCode) {
    return Input::GetKey(keyCode) && !activeKeys[keyCode];
}

bool Input::GetKeyUp(int keyCode) {
    return !Input::GetKey(keyCode) && activeKeys[keyCode];
}
