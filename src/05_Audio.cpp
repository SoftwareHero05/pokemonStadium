#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <cmath>

class NuevoFondo {
public:
    NuevoFondo(const std::string& texturePath, const sf::Vector2u& windowSize) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);

        // Escala el sprite para que coincida con el tamaño de la ventana
        sf::Vector2u textureSize = texture.getSize();
        float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
        float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
        sprite.setScale(scaleX, scaleY);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

int main() {
    try {
        // Crea la ventana
        sf::RenderWindow window(sf::VideoMode(512, 384), "Juego Pokémon");

        // Inicializa el fondo ajustando su escala
        NuevoFondo nuevoFondo("./assets/images/FondoPokemon.png", window.getSize());

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            nuevoFondo.draw(window);  // Dibuja el nuevo fondo
            window.display();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}