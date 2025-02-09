#include "../include/AtomEngine.h"
#include "./flappy.cpp"

int main() {
    Game* miJuego = new Game("Juego con atom engine", 1080, 720);
    SceneManager* manejadorEscenas = new SceneManager("manager");

    Atom2D* mundo = new Atom2D("mundo");
    Bird* pajaro = new Bird("pajaro", "assets/pajaraso.png");
    mundo -> AddChild(pajaro);

    manejadorEscenas -> SetCurrentScene(mundo);

    miJuego -> Play(manejadorEscenas -> GetCurrentScene());
}
