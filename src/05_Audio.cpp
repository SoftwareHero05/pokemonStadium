#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <filesystem>
#include <string>

// Clase para manejar el fondo
class BackGround {
public:
    BackGround(const std::string& texturePath, const sf::Vector2u& windowSize) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);
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

// Clase para manejar un Pokémon
class Pokemon {
public:
    Pokemon(const std::string& texturePath, const sf::Vector2f& position) 
        : texturePath(texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(1.5f, 1.5f);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

    const std::string& getPath() const {
        return texturePath;
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string texturePath;
};

// Función para verificar la existencia de un archivo
bool verificarArchivo(const std::string& path) {
    return std::filesystem::exists(path);
}

// Función para verificar si un Pokémon pertenece al jugador según su terminación
bool esPokemonJugador(const std::string& path, char terminacion) {
    return path.substr(path.size() - 5, 1) == std::string(1, terminacion);
}

// Proceso de selección de Pokémon
void seleccionarPokemones(std::vector<Pokemon>& seleccion, const std::vector<std::string>& disponibles, int jugador, sf::RenderWindow& window) {
    std::vector<std::string> opcionesFiltradas;

    // Filtrar opciones según el jugador
    char terminacion = (jugador == 1) ? 'F' : 'B';
    for (const auto& path : disponibles) {
        if (esPokemonJugador(path, terminacion)) {
            opcionesFiltradas.push_back(path);
        }
    }

    if (opcionesFiltradas.empty()) {
        throw std::runtime_error("No available Pokémon for Player " + std::to_string(jugador) + ".");
    }

    int seleccionIndex = 0;
    while (seleccion.size() < 6) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                throw std::runtime_error("Selección interrumpida.");
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    seleccionIndex = (seleccionIndex + 1) % opcionesFiltradas.size();
                } else if (event.key.code == sf::Keyboard::Left) {
                    seleccionIndex = (seleccionIndex - 1 + opcionesFiltradas.size()) % opcionesFiltradas.size();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    seleccion.push_back(Pokemon(opcionesFiltradas[seleccionIndex], jugador == 1 ? sf::Vector2f(100.0f, 300.0f) : sf::Vector2f(500.0f, 100.0f)));
                    std::cout << "Jugador " << jugador << " seleccionó: " << opcionesFiltradas[seleccionIndex] << std::endl;
                }
            }
        }

        // Redibujar pantalla para mostrar selección
        window.clear();
        BackGround("./assets/images/Bosque tarde - Zeo.png", window.getSize()).draw(window);
        Pokemon preview(opcionesFiltradas[seleccionIndex], sf::Vector2f(300.0f, 200.0f));
        preview.draw(window);
        window.display();
    }
}

int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Pokemon Battle 1 vs 1");

        const std::string backgroundPath = "./assets/images/Bosque tarde - Zeo.png";
        if (!verificarArchivo(backgroundPath)) {
            throw std::runtime_error("Background texture not found: " + backgroundPath);
        }

        BackGround background(backgroundPath, window.getSize());

        // Lista de Pokémon disponibles
        std::vector<std::string> pokemonPaths = {
            "./assets/images/003B.png",  
            "./assets/images/006B.png",  
            "./assets/images/094B.png",  
            "./assets/images/143B.png",
            "./assets/images/149B.png",
            "./assets/images/245B.png",
            "./assets/images/248B.png",
            "./assets/images/282B.png",  
            "./assets/images/445B.png",
            "./assets/images/448B.png",  
            "./assets/images/003F.png",  
            "./assets/images/006F.png",  
            "./assets/images/094F.png",  
            "./assets/images/143F.png",
            "./assets/images/149F.png",
            "./assets/images/245F.png",
            "./assets/images/248F.png",
            "./assets/images/282F.png",  
            "./assets/images/445F.png",
            "./assets/images/448F.png"
        };

        std::vector<Pokemon> player1Pokemons;
        std::vector<Pokemon> player2Pokemons;

        // Selección de Pokémon por ambos jugadores
        seleccionarPokemones(player1Pokemons, pokemonPaths, 1, window);
        seleccionarPokemones(player2Pokemons, pokemonPaths, 2, window);

        // Inicia batalla con pokémones seleccionados
        int activePokemon1 = 0;
        int activePokemon2 = 0;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            background.draw(window);
            player1Pokemons[activePokemon1].draw(window);
            player2Pokemons[activePokemon2].draw(window);
            window.display();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
