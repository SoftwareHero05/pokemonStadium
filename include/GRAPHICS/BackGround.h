#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class BackGround {
public:
    BackGround() {}

    BackGround(const std::string& texturePath,const sf::Vector2u& windowSize) {
        setBackGround(texturePath,windowSize);
    }
        
    void setBackGround(const std::string& texturePath,const sf::Vector2u& windowSize){
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        this->sprite.setTexture(texture);
        sf::Vector2u textureSize = texture.getSize();
       if (textureSize != windowSize) {  // Escala solo si las dimensiones no coinciden
            float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
            float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
            sprite.setScale(scaleX, scaleY);
        }
        
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};