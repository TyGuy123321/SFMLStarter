#pragma once

#include "../Scene.h"

class MainScene : public Scene {
public:
    void onEnter(entt::registry& registry) override;
    void onExit(entt::registry& registry) override;
    void update(entt::registry& registry, float deltaTime) override;
    void render(entt::registry& registry, sf::RenderTarget& renderTarget) override;
};
