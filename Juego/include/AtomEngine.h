#ifndef ATOM_ENGINE_H
#define ATOM_ENGINE_H
#include <SFML/Graphics/Sprite.hpp>
#include <sys/types.h>
#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../../include/SFML/Audio.hpp"
#include "../../include/SFML/Graphics.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>
#include "AtomMath.h"

class GameObject;
class Window {
private:
    const char *title;
    int width;
    int height;

public:
    Window(const char *title, unsigned int width, unsigned int height);
    ~Window();

    int Run(GameObject *scene);
};

class GameObject {
    protected:
        std::string name;
        GameObject* parent;

    public:
    std::vector<std::shared_ptr<GameObject>> childrens;
    virtual std::string GetName() const = 0;
    virtual GameObject* GetParent() const = 0;
    virtual void SetParent(GameObject* parent) = 0;
    virtual void AddChild(GameObject* child) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~GameObject() = default;
};

class ObjectDrawable {
    public:
        virtual ~ObjectDrawable() = default;
        virtual void draw(sf::RenderWindow&) = 0;
};

//Clase que se encarga de manejar las escenas del juego
//Necesario para poder gestionar las escenas del jueg
class SceneManager {
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
class Atom : public GameObject {
    public:
        Atom(std::string _name);
        ~Atom(){};
        virtual std::string GetName() const override;
        virtual GameObject* GetParent() const override;
        virtual void SetParent(GameObject* parent) override;
        virtual void AddChild(GameObject* child) override;
        virtual void draw(sf::RenderWindow& window) override {};
};

class Atom2D : public Atom , public ObjectDrawable {
    protected:
        AtomMath::Transform transform;
    public:
        //Constructor por defecto para objetos en 2D sin un transform inicial
        Atom2D(std::string _name);
        //Constructor con un transform inicial para Objetos en 2D
        Atom2D(std::string _name, AtomMath::Vector2 position);
        ~Atom2D();
        //Establece la posicion de un Atom2D
        void SetPosition(AtomMath::Vector2 position);
        //Establece la escala de un Atomo2D
        void SetScale(AtomMath::Vector2 scale);
        //Establece la rotacion de un Atomo2D
        void SetRotation(float rotation);
        //Obten la posicion actual de un Atomo2D
        AtomMath::Vector2 GetPosition();
        //Obten la escala actual de un Atomo2D
        AtomMath::Vector2 GetScale();
        //Obten la rotacion actual de un Atomo2D
        float GetRotation();
        void draw(sf::RenderWindow& window) override;
    };

class Spr2D : public Atom2D  {
    private:
        sf::Texture* texture = nullptr;
        sf::Sprite* sprite = nullptr;
    public:
        Spr2D(std::string _name, const char* _texture);
        Spr2D(std::string _name, AtomMath::Vector2 _position, const char* _texture);

        sf::Sprite GetSprite();
        sf::Texture GetTexture();
        void SetPosition(AtomMath::Vector2 position);
        void SetSprite(const char* _texture);
        void draw(sf::RenderWindow& window) override;
        ~Spr2D(){};
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
