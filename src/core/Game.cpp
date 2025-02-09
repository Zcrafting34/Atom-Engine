#include "../../include/AtomEngine.h"


    Game::Game(const char *title, int width, int height)
        : title(title), width(width), height(height){}

    Game::~Game() {
        if (window) {
            delete window;
        }
    }

    void Game::Play(GameObject *scene) {
        window = new Window(this->title, this->width, this->height);

        window->Run(scene);
    }
