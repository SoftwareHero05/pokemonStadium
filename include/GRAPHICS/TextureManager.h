#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class SourceManager
{
private:
    std::map<std::string, sf::Texture> textureMap;
    std::map<std::string, sf::Font> fontMap;
public:
    // Método para obtener o cargar una fuente
    const sf::Font& getFont(const std::string& fontPath)
    {
        // Si la fuente ya está cargada, la devuelve
        auto it = fontMap.find("./assets/fonts/" + fontPath);
        if (it != fontMap.end())
        {
            return it->second;
        }

        // Si no, la carga y la almacena
        sf::Font font;
        if (!font.loadFromFile("./assets/fonts/" + fontPath))
        {
            throw std::runtime_error("Failed to load font: " + fontPath);
        }
        fontMap[fontPath] = std::move(font);
        return fontMap[fontPath];
    }

    // Método para obtener o cargar una textura
    const sf::Texture& getTexture(const std::string& texturePath)
    {
        // Si la textura ya está cargada, la devuelve
        auto it = textureMap.find("./assets/images/" + texturePath);
        if (it != textureMap.end())
        {
            return it->second;
        }

        // Si no, la carga y la almacena
        sf::Texture texture;
        if (!texture.loadFromFile("./assets/images/" + texturePath))
        {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        textureMap[texturePath] = std::move(texture);
        return textureMap[texturePath];
    }


};
