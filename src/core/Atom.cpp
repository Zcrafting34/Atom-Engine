#include "../../include/AtomEngine.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


Atom::Atom(std::string _name) {
    this->name = _name;
}

GameObject* Atom::GetParent() const {
    return this->parent;
}

std::string Atom::GetName() const {
    return this->name;
}
void Atom::SetParent(GameObject* p) {
    this->parent = p;
}

void Atom::AddChild(GameObject* child) {
    childrens.push_back(std::shared_ptr<GameObject>(child));
    child->SetParent(this);
}
