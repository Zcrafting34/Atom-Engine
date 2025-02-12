#include "../include/AtomEngine.h"
#include "./Pajaro.cpp"

int main() {
    Game* game = new Game("MiJuego En AtomEngine", 1080,720);
    SceneManager* manager = new SceneManager("manager");

    Atom2D* mundo = new Atom2D("mundo");
    Pajaro* pajarito = new Pajaro("sprite", "./assets/pajaraso.png");

    mundo -> AddChild(pajarito);

    manager -> SetCurrentScene(mundo);

    game ->Play(manager -> GetCurrentScene());

    return 0;
}
