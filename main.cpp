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

    sf::RenderWindow window{sf::VideoMode{{config::kWidth, config::kHeight}}, config::kTitle};
    window.setFramerateLimit(config::kFps);
    window.setKeyRepeatEnabled(false);

    SceneManager sceneManager{registry};
    sceneManager.changeScene(std::make_unique<MainScene>());

    sf::Clock clock{};
    while (window.isOpen()) {
        std::optional<sf::Event> opt{};
        while ((opt = window.pollEvent()).has_value()) {
            const auto& event{opt.value()};

            sceneManager.handleEvent(window, event);
            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }

        const auto deltaTime{clock.restart().asSeconds()};
        sceneManager.update(deltaTime);

        window.clear(config::kColor);
        sceneManager.render(window);
        window.display();
    }

    sceneManager.clearScene();
    registry.clear();
    assetManager.clear();

    return EXIT_SUCCESS;
}
