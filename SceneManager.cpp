#include "SceneManager.h"

SceneManager::SceneManager(entt::registry& registry) : registry_{registry} {
}

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    if (scene_) {
        scene_->onExit(registry_);
    }

    scene_ = std::move(scene);
    if (scene_) {
        scene_->onEnter(registry_);
    }
}

void SceneManager::clearScene() {
    changeScene(nullptr);
}

bool SceneManager::handleEvent(const sf::Event& event) {
    if (scene_) {
        return scene_->handleEvent(registry_, event);
    }
    return false;
}

void SceneManager::update(float deltaTime) {
    if (scene_) {
        scene_->update(registry_, deltaTime);
    }
}

void SceneManager::render() {
    if (scene_) {
        scene_->render(registry_);
    }
}
