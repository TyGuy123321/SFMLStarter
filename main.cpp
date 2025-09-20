#include <cstdlib>

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

#include "scenes/MainScene.h"
#include "AssetManager.h"
#include "Config.h"
#include "SceneManager.h"

int main() {
    entt::registry registry{};
    registry.ctx().emplace<entt::dispatcher>();
    auto& assetManager{registry.ctx().emplace<AssetManager>()};
    auto& window{registry.ctx().emplace<sf::RenderWindow>(sf::VideoMode{{config::kWidth, config::kHeight}}, config::kTitle)};
    sf::View view{sf::FloatRect{{0.f, 0.f}, {config::kWidth, config::kHeight}}};
    window.setView(view);
    window.setFramerateLimit(config::kFps);
    window.setKeyRepeatEnabled(false);

    SceneManager sceneManager{registry};
    sceneManager.changeScene(std::make_unique<MainScene>());

    sf::Clock clock{};
    while (window.isOpen()) {
        std::optional<sf::Event> opt{};
        while ((opt = window.pollEvent()).has_value()) {
            const auto& event{opt.value()};

            sceneManager.handleEvent(event);
            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }

        const auto deltaTime{clock.restart().asSeconds()};
        sceneManager.update(deltaTime);

        window.clear(config::kColor);
        window.setView(view); // TODO: should this be set on a per scene basis?
        sceneManager.render();
        window.display();
    }

    sceneManager.clearScene();
    registry.clear();
    assetManager.clear();

    return EXIT_SUCCESS;
}
