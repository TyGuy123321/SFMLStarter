#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void onEnter(entt::registry& registry);
    virtual void onExit(entt::registry& registry);
    virtual bool handleEvent(entt::registry& registry, const sf::Window& eventSource, const sf::Event& event);
    virtual void update(entt::registry& registry, float deltaTime);
    virtual void render(entt::registry& registry, sf::RenderTarget& renderTarget);
};
