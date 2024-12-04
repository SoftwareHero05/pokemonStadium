#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <cmath>


class BackGround {
public:
    BackGround(const std::string& texturePath, const sf::Vector2u& windowSize) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);

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

class Pokemon {
public:
    Pokemon(const std::string& texturePath, float scaleX = 1.0f, float scaleY = 1.0f, float posX = 0.0f, float posY = 0.0f)
        : visible(true) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);
        sprite.setScale(scaleX, scaleY);
        sprite.setPosition(posX, posY);
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    void setScale(float scaleX, float scaleY) {
        sprite.setScale(scaleX, scaleY);
    }

    void setTextureRect(const sf::IntRect& rect) {
        sprite.setTextureRect(rect);
    }

    void setVisibility(bool visibility) {
        visible = visibility;
    }

    void setColor(const sf::Color& color) {
        sprite.setColor(color);
    }

    sf::Uint8 getAlpha() const {
        return sprite.getColor().a;
    }

    void draw(sf::RenderWindow& window) const {
        if (visible) {
            window.draw(sprite);
        }
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible;
};

// Clase para manejar música
class MusicManager {
public:
    MusicManager(const std::string& musicPath) {
        if (!music.openFromFile(musicPath)) {
            throw std::runtime_error("Failed to load music: " + musicPath);
        }
        music.setLoop(true);
    }

    void play() {
        music.play();
    }

private:
    sf::Music music;
};

 /////..... clase ataque.....//////
 class Ataque {
public:
    Ataque(const std::string& texturePath, float startX, float startY, float scaleX = 1.0f, float scaleY = 1.0f)
        : active(false) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);
        sprite.setPosition(startX, startY);
        sprite.setScale(scaleX, scaleY);  // Escala del ataque
    }
        void lanzar(float startX, float startY, float targetX, float targetY) {
        float offsetX = (sprite.getLocalBounds().width / 2) * sprite.getScale().x;  // Ajusta por escala
        float offsetY = (sprite.getLocalBounds().height / 2) * sprite.getScale().y; // Ajusta por escala
        sprite.setPosition(startX - offsetX, startY + 20 - offsetY); 
        //sprite.setRotation(180.0f);
        objetivoX = targetX - offsetX;
        objetivoY = targetY - offsetY;
        active = true;
    }
    void actualizar(float velocidad) {
        if (!active) return;

        sf::Vector2f pos = sprite.getPosition();
        float dx = objetivoX - pos.x;
        float dy = objetivoY - pos.y;
        float distancia = std::sqrt(dx * dx + dy * dy);  // Corregido: usar std::sqrt

        if (distancia < 0.5f) {
            active = false;  // Ataque alcanzó el objetivo
        } else {
            sprite.move(velocidad * (dx / distancia), velocidad * (dy / distancia));
        }
    }

    void draw(sf::RenderWindow& window) const {
        if (active) {
            window.draw(sprite);
        }
    }

    bool estaActivo() const {
        return active;
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool active;
    float objetivoX, objetivoY;
};



int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(512, 384), "SFML with Classes");

        // Fondo inicial
         BackGround initialBackground("./assets/images/FondoPokemon.png", window.getSize());
         BackGround background("./assets/images/Bosque tarde - Zeo.png", window.getSize());
        bool gameStarted = false;

        // Pantalla inicial antes del bucle principal del juego
        while (window.isOpen() && !gameStarted) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    gameStarted = true; // Inicia el juego al presionar cualquier tecla
                }
            }

            window.clear();
            initialBackground.draw(window); // Dibuja el fondo inicial
            window.display();
        }

        // Música y recursos del juego
        MusicManager music("./assets/music/batalla01.ogg");
        music.play();

        
        Pokemon pokeball1("./assets/images/pokeball.png", 0.5f, 0.5f, 80, 220);
        Pokemon pokeball2("./assets/images/pokeball.png", 0.5f, 0.5f, 300, 80);

        // Cargar entrenadores con recortes
        Pokemon entrenador1("./assets/images/entrenadores.png", 1.0f, 1.0f, 0.2f, 70);
        entrenador1.setTextureRect(sf::IntRect(0, 0, 195, 130)); // Primer entrenador (x, y, width, height)

        Pokemon entrenador2("./assets/images/entrenadores.png", 1.0f, 1.0f, 315, 200);
        entrenador2.setTextureRect(sf::IntRect(195, 0, 196, 130)); // Segundo entrenador

        Pokemon gardevoir("./assets/images/282.png", 1.5f, 1.5f, 75, 200);
        Pokemon garchomp("./assets/images/445.png", 1.5f, 1.5f, 300, 70);

        Ataque ataque("./assets/images/00013.png", 90, 300, 0.2f, 0.2f); 
        Ataque ataqueGarchomp("./assets/images/00011.png", 300, 70, 0.2f, 0.2f);

        bool gardevoirVisible = false;
        bool garchompVisible = false;

        sf::Clock clock;
        sf::Clock fadeClock;
        bool fadingOut = false;

        // Bucle principal del juego
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
                    if (!ataque.estaActivo()) {
                        ataque.lanzar(230, 200, 400, 110); // Desde Gardevoir a Garchomp
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
                    if (!ataqueGarchomp.estaActivo()) {
                        ataqueGarchomp.lanzar(400, 80, 85, 320); // Desde Garchomp a Gardevoir
                    }
                }
            }

            ataque.actualizar(0.2f);
            ataqueGarchomp.actualizar(0.2f);

            float elapsedTime = clock.getElapsedTime().asSeconds();
            if (elapsedTime > 3.0f) {
                gardevoirVisible = true;
            }
            if (elapsedTime > 4.0f) {
                garchompVisible = true;
            }

            if (clock.getElapsedTime().asSeconds() >= 2.0f && !fadingOut) {
                fadingOut = true;
                fadeClock.restart();
            }

            if (fadingOut) {
                float fadeTime = 1.0f;
                float elapsedFade = fadeClock.getElapsedTime().asSeconds();
                if (elapsedFade < fadeTime) {
                    sf::Uint8 alpha = static_cast<sf::Uint8>(255 * (1.0f - elapsedFade / fadeTime));
                    entrenador1.setColor(sf::Color(255, 255, 255, alpha));
                    entrenador2.setColor(sf::Color(255, 255, 255, alpha));
                } else {
                    entrenador1.setColor(sf::Color(255, 255, 255, 0));
                    entrenador2.setColor(sf::Color(255, 255, 255, 0));
                    entrenador1.setVisibility(false);
                    entrenador2.setVisibility(false);
                }
            }

            window.clear();
            background.draw(window);

            if (entrenador1.getAlpha() > 0 || entrenador2.getAlpha() > 0) {
                if (entrenador1.getAlpha() > 0) entrenador1.draw(window);
                if (entrenador2.getAlpha() > 0) entrenador2.draw(window);
            }

            if (!gardevoirVisible) {
                pokeball1.draw(window);
            } else {
                gardevoir.draw(window);
            }

            if (!garchompVisible) {
                pokeball2.draw(window);
            } else {
                garchomp.draw(window);
            }
            ataque.draw(window);
            ataqueGarchomp.draw(window);
            window.display();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}