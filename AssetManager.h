#pragma once

#include <any>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "AssetNotFoundException.h"

class AssetManager {
public:
    AssetManager() = default;

    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;

    AssetManager(AssetManager&&) = default;
    AssetManager& operator=(AssetManager&&) = default;

    template <typename T>
    const T& get(const std::string& key);
    void clear();
private:
    std::unordered_map<std::string, std::any> assets_{};
};

template <typename T>
inline const T& AssetManager::get(const std::string& key) {
    if (const auto it = assets_.find(key); it != assets_.end()) {
        return std::any_cast<const T&>(it->second);
    }

    T asset{};
    if (!asset.loadFromFile(key)) {
        throw AssetNotFoundException(key);
    }

    auto [it, _] = assets_.insert_or_assign(key, std::move(asset));
    return std::any_cast<const T&>(it->second);
}

// Specialization for sf::Font
template <>
inline const sf::Font& AssetManager::get(const std::string& key) {
    if (const auto it = assets_.find(key); it != assets_.end()) {
        return std::any_cast<const sf::Font&>(it->second);
    }

    sf::Font font{};
    if (!font.openFromFile(key)) {
        throw AssetNotFoundException(key);
    }

    auto [it, _] = assets_.insert_or_assign(key, std::move(font));
    return std::any_cast<const sf::Font&>(it->second);
}
