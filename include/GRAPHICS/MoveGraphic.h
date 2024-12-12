#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class MoveGraphic
{
public:
    MoveGraphic() {}
    MoveGraphic(const std::string &texturePath, float startX, float startY, float scaleX = 1.0f, float scaleY = 1.0f)
        : active(false)
    {
        if (!texture.loadFromFile(texturePath))
        {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);
        sprite.setPosition(startX, startY);
        sprite.setScale(scaleX, scaleY); // Escala del ataque
    }
    void lanzar(float startX, float startY, float targetX, float targetY)
    {
        float offsetX = (sprite.getLocalBounds().width / 2) * sprite.getScale().x;  // Ajusta por escala
        float offsetY = (sprite.getLocalBounds().height / 2) * sprite.getScale().y; // Ajusta por escala
        sprite.setPosition(startX - offsetX, startY + 20 - offsetY);
        // sprite.setRotation(180.0f);
        objetivoX = targetX - offsetX;
        objetivoY = targetY - offsetY;
        active = true;
    }
    void actualizar(float velocidad)
    {
        if (!active)
            return;

        sf::Vector2f pos = sprite.getPosition();
        float dx = objetivoX - pos.x;
        float dy = objetivoY - pos.y;
        float distancia = std::sqrt(dx * dx + dy * dy); // Corregido: usar std::sqrt

        if (distancia < 0.5f)
        {
            active = false; // Ataque alcanzó el objetivo
        }
        else
        {
            sprite.move(velocidad * (dx / distancia), velocidad * (dy / distancia));
        }
    }

    void draw(sf::RenderWindow &window) const
    {
        if (active)
        {
            window.draw(sprite);
        }
    }

    bool estaActivo() const
    {
        return active;
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool active;
    float objetivoX, objetivoY;
};
