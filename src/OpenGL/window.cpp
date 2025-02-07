#include "../../include/AtomEngine.h"

    Window::Window(const char* title, int width, int height)
        : title(title), width(width), height(height) {}

    Window::~Window() {}

   

    int Window::Run(GameObject* scene) {
        std::cout<<"mi pinche ventana";

        return 0;
    }