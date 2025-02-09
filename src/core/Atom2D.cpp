#include "../../include/AtomEngine.h"
#include <SFML/Graphics/RenderWindow.hpp>

Atom2D::Atom2D(std::string _name) : Atom(_name){
    this->transform = AtomMath::Transform {
        AtomMath::Vector2{0,0},
        AtomMath::Vector2{0,0},
        1.0
    };
}

Atom2D::~Atom2D() {}
Atom2D::Atom2D(std::string _name, AtomMath::Vector2 _position) : Atom(_name) {
    this->transform = AtomMath::Transform {
        _position,
        AtomMath::Vector2{0,0},
        1.0
    };
}

void Atom2D::SetPosition(AtomMath::Vector2 position) {
    this->transform.position = position;
}

void Atom2D::SetScale(AtomMath::Vector2 scale) {
    this->transform.scale = scale;
}

void Atom2D::SetRotation(float rotation) {
    this->transform.rotation = rotation;
}

AtomMath::Vector2 Atom2D::GetPosition() {
    return this->transform.position;
}

AtomMath::Vector2 Atom2D::GetScale() {
    return this->transform.scale;
}

float Atom2D::GetRotation() {
    return this->transform.rotation;
}

void Atom2D::draw(sf::RenderWindow& window) {
    for (auto child : this->childrens) {
        child->draw(window);
    }
}
