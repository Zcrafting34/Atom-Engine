#include "../../include/AtomEngine.h"

int main() {

    Game* miJuego = new Game("Deneken", 800, 600);

    SceneManager* manager = new SceneManager("manager");

    Atom* miAtomo = new Atom("mi atomo");

    manager->SetCurrentScene(miAtomo);

    miJuego->Play(manager->GetCurrentScene());
}