#include "../../include/AtomEngine.h"



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
    this->childrens.push_back(child);
}


