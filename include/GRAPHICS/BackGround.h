#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SourceManager.h"
class BackGround
{
public:
    BackGround() {}

    ~BackGround() {}

    BackGround(const std::string &texturePath, const sf::Vector2u &windowSize)
    {
    }

    void SetBackGround(const std::string &texturePath, SourceManager &manager, const sf::Vector2u &windowSize)
    {
        this->texture = manager.GetTexture(texturePath);
        this->sprite.setTexture(texture);
        sf::Vector2u textureSize = texture.getSize();
        if (textureSize != windowSize)
        { // Escala solo si las dimensiones no coinciden
            float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
            float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
            sprite.setScale(scaleX, scaleY);
        }
    }

    void Draw(sf::RenderWindow &window) const
    {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};
