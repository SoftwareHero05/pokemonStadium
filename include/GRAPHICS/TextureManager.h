#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager
{
private:
    std::map<std::string, sf::Texture> textureMap;

public:
    const sf::Texture& getTexture(const std::string& texturePath)
    {
        // Si la textura ya está cargada, la devuelve
        auto it = textureMap.find(texturePath);
        if (it != textureMap.end())
        {
            return it->second;
        }

        // Si no, la carga y la almacena
        sf::Texture texture;
        if (!texture.loadFromFile(texturePath))
        {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        textureMap[texturePath] = std::move(texture);
        return textureMap[texturePath];
    }
};
