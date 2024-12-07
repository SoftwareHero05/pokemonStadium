#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Image
{
public:
    Image() {}
    ~Image(){}
    void setImage(const std::string &texturePath, SourceManager& manager, float scaleX , float scaleY , float posX, float posY)
    {
        this->visible = true;
        this->texture = manager.getTexture(texturePath);
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

    float getTextureSizeX(){
        return texture.getSize().x;
    }

    float getTextureSizeY(){
        return texture.getSize().x;
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