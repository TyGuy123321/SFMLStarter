#pragma once

#include "../Scene.h"

class MainScene : public Scene {
public:
    void onEnter(entt::registry& registry) override;
    void onExit(entt::registry& registry) override;
    void update(entt::registry& registry, float deltaTime) override;
    void render(entt::registry& registry) override;

    // A tag used to mark an entity as being part of the MainScene.
    // This is to ensure cleanup of MainScene entities is simple.
    struct MainSceneTag {};
};
