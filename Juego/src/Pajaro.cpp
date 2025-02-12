#include "../include/AtomEngine.h"

using namespace AtomMath;

class Pajaro : public Spr2D {

    protected:
        float velocidad = 0.1f;

    public:

        Pajaro(std::string _name, const char* _texture) : Spr2D(_name, _texture) {
        }

        void draw(sf::RenderWindow& window) {
            Spr2D::draw(window);

            this -> SetPosition(Vector2 {
                this -> GetPosition().x + velocidad,
                this -> GetPosition().y
            });
        }
};
