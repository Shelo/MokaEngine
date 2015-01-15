#ifndef INPUT_H
#define INPUT_H

#include "Display.h"
#define GLEW_STATIC
#include <GLFW/glfw3.h>

class Input {
private:
    static const unsigned int GLFW_MOUSE_COUNT;
    static const unsigned int GLFW_KEY_COUNT;
    static GLFWwindow *window;
    static bool activeMouse[];
    static bool activeKeys[];
    static bool cursorLocked;

    static double _cursorCoordX;
    static double _cursorCoordY;
    static double cursorCoordX;
    static double cursorCoordY;
public:
    /**
    * This shouldn't be called manually.
    * Creates the system.
    */
    static void Create(GLFWwindow *window);

    /**
     * This shouldn't be called manually.
     * Updates the information that we have about the input.
     */
    static void Update();

    /**
     * Returns true if the key is currently pressed.
     */
    static bool GetKey(int keyCode);

    /**
     * Returns true if the key was pressed during this frame.
     */
    static bool GetKeyDown(int keyCode);

    /**
     * Returns true if the key was released during this frame.
     */
    static bool GetKeyUp(int keyCode);

    /**
     * Returns true if the button is currently pressed.
     */
    static bool GetMouse(int buttonCode);

    /**
    * Returns true if the button was pressed during this frame.
    */
    static bool GetMouseDown(int buttonCode);

    /**
    * Returns true if the button was released during this frame.
    */
    static bool GetMouseUp(int buttonCode);

    /**
     * Returns the current cursor's X position, left to right.
     */
    static int GetCursorX() {
        return (int) cursorCoordX;
    }

    /**
    * Returns the current cursor's Y position, bottom up.
    */
    static int GetCursorY() {
        return (int) cursorCoordY;
    }

    /**
     * Returns the distance that the mouse moved in this frame.
     */
    static int GetDeltaX() {
        return (int) (cursorCoordX - _cursorCoordX);
    }

    /**
    * Returns the distance that the mouse moved in this frame.
    */
    static int GetDeltaY() {
        return (int) (cursorCoordY - _cursorCoordY);
    }

    /**
    * Sets the cursor locked, if lock is true, the mouse will be locked at the center of the screen
    * and will be hidden, this is ideal for First person shooters.
    */
    static void SetCursorLocked(bool lock) {
        cursorLocked = lock;

        if(cursorLocked)
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        else
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    /**
    * Toggles the current state of the cursor locking.
    */
    static void ToggleCursorLocked() {
        SetCursorLocked(!cursorLocked);
    }
};

#endif

