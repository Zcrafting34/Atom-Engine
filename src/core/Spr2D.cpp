#include "../../include/AtomEngine.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

Spr2D::Spr2D(std::string _name, AtomMath::Vector2 _position, const char* _texture) : Atom2D(_name, _position) {
    this->texture = new sf::Texture(_texture);
    this->sprite = new sf::Sprite(*this->texture);
    this->sprite->setPosition(sf::Vector2f(this->transform.position.x, this->transform.position.y));
}
Spr2D::Spr2D(std::string _name, const char* _texture) : Atom2D(_name) {
    this->texture = new sf::Texture(_texture);
    this->sprite = new sf::Sprite(*this->texture);
}

void Spr2D::SetSprite(const char* _texture) {
    this->sprite = nullptr;
    this->sprite = new sf::Sprite(*this->texture);
}

sf::Sprite Spr2D::GetSprite() {
    return *this->sprite;
}

void Spr2D::draw(sf::RenderWindow& window) {
    window.draw(*this->sprite);

}

void Spr2D::SetPosition(AtomMath::Vector2 position) {
    Atom2D::SetPosition(position);
    this->sprite->setPosition(sf::Vector2f(this->transform.position.x, this->transform.position.y));
}
