#pragma once

#include <memory>

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "Scene.h"

class SceneManager {
public:
    SceneManager(entt::registry& registry);

    void changeScene(std::unique_ptr<Scene> scene);
    void clearScene();
    bool handleEvent(const sf::Window& eventSource, const sf::Event& event);
    void update(float deltaTime);
    void render(sf::RenderTarget& renderTarget);
private:
    entt::registry& registry_;
    std::unique_ptr<Scene> scene_{};
};
