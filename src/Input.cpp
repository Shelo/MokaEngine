#include <iostream>
#include "Input.h"

const unsigned int Input::GLFW_KEY_COUNT = 348;
const unsigned int Input::GLFW_MOUSE_COUNT = 5;

bool Input::activeKeys[Input::GLFW_KEY_COUNT];
bool Input::activeMouse[Input::GLFW_MOUSE_COUNT];
bool Input::cursorLocked = false;

GLFWwindow* Input::window = NULL;

double Input::_cursorCoordX = -1;
double Input::_cursorCoordY = -1;
double Input::cursorCoordX  = -1;
double Input::cursorCoordY  = -1;

void Input::Create(GLFWwindow *window) {
    for(int i = 0; i < Input::GLFW_KEY_COUNT; i++)
        activeKeys[i] = false;

    for(int i = 0; i < Input::GLFW_MOUSE_COUNT; i++)
        activeMouse[i] = false;

    Input::window = window;
}

void Input::Update() {
    for(int i = 0; i < Input::GLFW_KEY_COUNT; i++)
        activeKeys[i] = Input::GetKey(i);

    for(int i = 0; i < Input::GLFW_MOUSE_COUNT; i++)
        activeMouse[i] = Input::GetMouse(i);

    _cursorCoordX = cursorCoordX;
    _cursorCoordY = cursorCoordY;
    glfwGetCursorPos(window, &cursorCoordX, &cursorCoordY);

    if(_cursorCoordX == -1)
        _cursorCoordX = cursorCoordX;

    if(_cursorCoordY == -1)
        _cursorCoordY = cursorCoordY;

    if(cursorLocked) {
        glfwSetCursorPos(window, Display::GetWidth() / 2, Display::GetHeight() / 2);
        _cursorCoordX = Display::GetWidth() / 2;
        _cursorCoordY = Display::GetHeight() / 2;
    }
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

bool Input::GetMouse(int buttonCode) {
    return glfwGetMouseButton(window, buttonCode) == GLFW_PRESS;
}

bool Input::GetMouseDown(int buttonCode) {
    return GetMouse(buttonCode) && !activeMouse[buttonCode];
}

bool Input::GetMouseUp(int buttonCode) {
    return !GetMouse(buttonCode) && activeMouse[buttonCode];
}