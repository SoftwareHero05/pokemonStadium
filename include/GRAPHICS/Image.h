#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Image
{
public:
    Image() {}
    ~Image(){}
    void SetImage(const std::string &texturePath, SourceManager& manager, float scaleX , float scaleY , float posX, float posY)
    {
        this->visible = true;
        this->texture = manager.GetTexture(texturePath);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
        sprite.setScale(scaleX, scaleY);
        sprite.setPosition(posX, posY);
    }

    void SetPosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    void SetScale(float scaleX, float scaleY)
    {
        sprite.setScale(scaleX, scaleY);
    }

    float GetTextureSizeX(){
        return texture.getSize().x;
    }

    float GetTextureSizeY(){
        return texture.getSize().x;
    }

    void SetTextureRect(const sf::IntRect &rect)
    {
        sprite.setTextureRect(rect);
    }

    void SetVisibility(bool visibility)
    {
        visible = visibility;
    }

    void SetColor(const sf::Color &color)
    {
        sprite.setColor(color);
    }

    sf::Uint8 GetAlpha() const
    {
        return sprite.getColor().a;
    }

    void Draw(sf::RenderWindow &window) const
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