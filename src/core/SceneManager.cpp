#include "../../include/AtomEngine.h"


SceneManager::SceneManager(std::string _name) {
    this->name = _name;
}

SceneManager::~SceneManager() {
    for (auto scene : scenes) {
        delete scene;
    }
}


void SceneManager::SetCurrentScene(GameObject *scene) {
    this->currentScene = scene;
}

GameObject* SceneManager::GetCurrentScene() {
    return this->currentScene;
}

void SceneManager::AddChild(GameObject* child) {
    this->scenes.push_back(child);
}




