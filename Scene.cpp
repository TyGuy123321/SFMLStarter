#include "Scene.h"

void Scene::onEnter(entt::registry& registry) {}

void Scene::onExit(entt::registry& registry) {}

bool handleEvent(entt::registry& registry, const sf::Event& event) {
    return false;
}

void Scene::update(entt::registry& registry, float deltaTime) {}

void Scene::render(entt::registry& registry) {}
