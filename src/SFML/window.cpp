#include "../../include/AtomEngine.h"
#include <SFML/Graphics/Color.hpp>


Window::Window(const char* title, unsigned int width, unsigned int height)
    : title(title), width(width), height(height) {}

Window::~Window() {}

int Window::Run(GameObject* scene) {

    sf::RenderWindow window(
        sf::VideoMode(
        {static_cast<unsigned int>(this->width), static_cast<unsigned int>(this->height)}),
        this->title
    );

    while (window.isOpen()){
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
 
        window.clear(sf::Color::White);
        scene->draw(window);
        window.display();
    }

    return 0;
}
