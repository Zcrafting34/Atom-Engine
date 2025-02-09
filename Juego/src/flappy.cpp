#include "../include/AtomEngine.h"


class Bird : public Spr2D {

    protected:
        float velocidad = 0.5f;

    public:
        Bird(std::string _name, AtomMath::Vector2 _position, const char* _texture) : Spr2D(_name, _position, _texture) {}
        Bird(std::string _name, const char* _texture) : Spr2D(_name, _texture) {}

        void draw(sf::RenderWindow& window) override {
            Spr2D::draw(window);
            std::cout<<"Dibujando pajaro"<<std::endl;
            this-> SetPosition(AtomMath::Vector2{this->GetPosition().x + velocidad, this->GetPosition().y});
        }

        ~Bird(){};
};
