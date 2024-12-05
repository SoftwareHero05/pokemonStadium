#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class Text
{
public:
    Text() : visible(true) {}

    void setText(const std::string &text, const std::string &fontPath, unsigned int fontSize = 30, float posX = 0.0f, float posY = 0.0f)
    {
        if (!font.loadFromFile(fontPath))
        {
            throw std::runtime_error("Failed to load font: " + fontPath);
        }
        this->text.setFont(font);
        this->text.setString(text);
        this->text.setCharacterSize(fontSize);
        this->text.setPosition(posX, posY);
    }

    void setPosition(float x, float y)
    {
        text.setPosition(x, y);
    }

    void setColor(const sf::Color &color)
    {
        text.setFillColor(color);
    }

    void setOutlineColor(const sf::Color &color)
    {
        text.setOutlineColor(color);
    }

    void setOutlineThickness(float thickness)
    {
        text.setOutlineThickness(thickness);
    }

    void setVisibility(bool visibility)
    {
        visible = visibility;
    }

    void setStyle(sf::Text::Style style)
    {
        text.setStyle(style);
    }

    void setString(const std::string &str)
    {
        text.setString(str);
    }

    sf::Uint8 getAlpha() const
    {
        return text.getFillColor().a;
    }

    void draw(sf::RenderWindow &window) const
    {
        if (visible)
        {
            window.draw(text);
        }
    }

private:
    sf::Font font;
    sf::Text text;
    bool visible;
};
