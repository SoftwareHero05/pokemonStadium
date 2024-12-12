#pragma once
#include <SFML/Graphics.hpp>
#include <GRAPHICS/SourceManager.h>
#include <functional>
#include <string>

class ButtonText
{
private:
    sf::Text text;                 // El texto del botón
    sf::Font font;                 // Fuente para el texto
    std::string returnValue;       // Valor asociado al botón
    std::function<void()> onClick; // Acción al hacer clic
    bool visible;                  // Visibilidad del botón
    sf::RectangleShape background; // Fondo del botón

public:
    ButtonText()
        : visible(true), onClick(nullptr) {}

    // Configurar el botón con texto
    void SetButton(SourceManager &fontManager, const std::string &buttonText, sf::Vector2f position, sf::Vector2f size, const std::string &value)
    {
        // Cargar la fuente
        // Configurar el texto
        text.setFont(fontManager.GetFont("pokemon-firered-leafgreen-font-recreation.ttf"));
        text.setString(buttonText);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(position);

        // Centrar el texto dentro del botón
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);

        // Configurar el fondo del botón
        background.setSize(size);
        background.setPosition(position);
        background.setFillColor(sf::Color(0, 0, 0, 0)); // Fondo azul por defecto

        returnValue = value;
    }

    // Manejar eventos del botón
    bool HandleEvent(const sf::Event &event, sf::RenderWindow &window, std::string &result)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (background.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            {
                result = returnValue; // Retorna el valor asociado
                if (onClick)
                    onClick(); // Ejecuta la acción si está definida
                return true;   // Indica que el botón fue presionado
            }
        }
        return false; // No se presionó este botón
    }

    // Dibujar el botón
    void Draw(sf::RenderWindow &window)
    {
        if (visible)
        {
            window.draw(background);
            window.draw(text);
        }
    }

    void SetVisibility(bool visibility)
    {
        visible = visibility;
    }

    void SetBackgroundColor(const sf::Color &color)
    {
        background.setFillColor(color);
    }

    void SetTextColor(const sf::Color &color)
    {
        text.setFillColor(color);
    }

    void SetOnClick(const std::function<void()> &action)
    {
        onClick = action;
    }
};
