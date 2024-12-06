#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include "TextureManager.h"
class ButtonImage
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string returnValue; // Valor asociado al botón
    std::function<void()> onClick;
    bool visible;

public:
    // Configurar el botón con un valor de retorno
    ButtonImage(){}
    void setButton(const std::string& texturePath,TextureManager& textureManager, sf::Vector2f position, const std::string& value)
    {

        const sf::Texture& texture = textureManager.getTexture(texturePath);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        returnValue = value; // Asigna el valor al botón
        onClick = nullptr;   // Inicializa la acción como nula
        sprite.setColor(sf::Color(255, 255, 255, 255));
        sprite.setScale(1.0f, 1.0f);
    }

    // Manejar eventos del botón
    bool handleEvent(const sf::Event& event, sf::RenderWindow& window, std::string& result)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
            {
                result = returnValue; // Retorna el valor asociado
                if (onClick) onClick(); // Ejecuta la acción si está definida
                return true; // Indica que el botón fue presionado
            }
        }
        return false; // No se presionó este botón
    }

    // Dibujar el botón
    void draw(sf::RenderWindow& window)
    {
        if (visible)
        {
            window.draw(sprite);
        }
    }

    void setVisibility(bool visibility)
    {
        visible = visibility;
    }

    void setScale(float scaleX, float scaleY)
    {
        sprite.setScale(scaleX, scaleY);
    }
};
