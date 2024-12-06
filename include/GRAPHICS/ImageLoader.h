#pragma once
#include <SFML/Graphics.hpp>

class Image
{
public:
    Image() {}
    void setImage(const std::string &texturePath, float scaleX , float scaleY , float posX, float posY)
    {
        this->visible = true;
        if (!texture.loadFromFile(texturePath))
        {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);
        sprite.setScale(scaleX, scaleY);
        sprite.setPosition(posX, posY);
    }

    void setPosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    void setScale(float scaleX, float scaleY)
    {
        sprite.setScale(scaleX, scaleY);
    }

    void setTextureRect(const sf::IntRect &rect)
    {
        sprite.setTextureRect(rect);
    }

    void restoreTextureRect()
    {
        sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    }

    void setVisibility(bool visibility)
    {
        visible = visibility;
    }

    void setColor(const sf::Color &color)
    {
        sprite.setColor(color);
    }

    sf::Uint8 getAlpha() const
    {
        return sprite.getColor().a;
    }

    void draw(sf::RenderWindow &window) const
    {
        if (visible)
        {
            window.draw(sprite);
        }
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible;
};