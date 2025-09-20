#pragma once

#include <stdexcept>
#include <string>

class AssetNotFoundException : public std::runtime_error {
public:
    explicit AssetNotFoundException(const std::string& name) : std::runtime_error("File not found: " + name) {}
};
