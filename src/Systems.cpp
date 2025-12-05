#include "Systems.h"

#include "Components.h"

namespace {

float getAxis(sf::Keyboard::Scancode negative, sf::Keyboard::Scancode positive) {
    float axis = 0.0f;

    if (sf::Keyboard::isKeyPressed(negative)) {
        axis -= 1.f;
    }

    if (sf::Keyboard::isKeyPressed(positive)) {
        axis += 1.f;
    }

    return axis;
}

}

// TODO
