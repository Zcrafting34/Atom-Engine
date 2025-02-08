#ifndef ATOM_ENGINE_H
#define ATOM_ENGINE_H
#include <sys/types.h>
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

class GameObject;
class Window
{
private:
    const char *title;
    int width;
    int height;

public:
    Window(const char *title, unsigned int width, unsigned int height);
    ~Window();

    int Run(GameObject *scene);
};

    class GameObject
    {
        protected:
            std::string name;
            GameObject* parent;

        public:
        std::vector<GameObject*> childrens;
        virtual std::string GetName() const = 0;
        virtual GameObject* GetParent() const = 0;
        virtual void SetParent(GameObject* parent) = 0;
        virtual void AddChild(GameObject* child) = 0;
    };

    //Clase que se encarga de manejar las escenas del juego
    //Necesario para poder gestionar las escenas del juego

    class SceneManager
    {
        private:
            std::string name;
            std::vector<GameObject*> scenes;
            GameObject *currentScene;
        public:
            SceneManager(std::string _name);
            ~SceneManager();
            virtual void SetCurrentScene(GameObject *gameObject);
            virtual GameObject* GetCurrentScene();
            virtual void AddChild(GameObject *child);
    };



    //Un Atom es el obejto mas basico y primitivo de Atom Engine
    class Atom : public GameObject
    {
        public:
            Atom(std::string _name);
            ~Atom();
            virtual std::string GetName() const override;
            virtual GameObject* GetParent() const override;
            virtual void SetParent(GameObject* parent) override;
            virtual void AddChild(GameObject* child) override;

    };

    class Game
    {
        private:
            const char *title;
            int width;
            int height;
            Window* window;
            int nCmdShow;

        public:
        Game(const char *title, int width, int height);
        ~Game();

        void Play(GameObject *scene);
    };


    #endif
