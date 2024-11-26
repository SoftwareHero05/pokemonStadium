#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
using namespace std;

class Pokemon
{
private:
    string path;

public:
    Pokemon(){

    }

    void CargarImagen(string pathImagen)
    {
        // Cargar la imagen de Tyranitar
        sf::Texture tyranitarTexture;
        if (!tyranitarTexture.loadFromFile(pathImagen))
        {
            throw new exception();
        }
        sf::Sprite tyranitarSprite(tyranitarTexture);
        tyranitarSprite.setScale(1.5f, 1.5f);
        tyranitarSprite.setPosition(300, 80); // Misma posición que su Pokébola
        bool tyranitarVisible = false;        // Control de visibilidad
    }
};

int main()
{
    Pokemon ejemplo;
    ejemplo.CargarImagen("./assets/images/248.png");

    Pokemon srnorlax;
    srnorlax.CargarImagen("aqui la ruta");







    sf::Music music;
    if (!music.openFromFile("./assets/music/batalla01.ogg")) {
        return -1; // Error al cargar la música
    }
    music.setLoop(true);
    music.play();

    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(512, 384), "SFML Animation");

    // Cargar la imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./assets/images/Bosque tarde - Zeo.png")) {
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Cargar la imagen de las Pokébolas
    sf::Texture pokeballTexture;
    if (!pokeballTexture.loadFromFile("./assets/images/pokeball.png")) {
        return -1;
    }

    // Configurar las Pokébolas
    sf::Sprite pokeballSprite1(pokeballTexture);
    pokeballSprite1.setScale(0.5f, 0.5f);
    pokeballSprite1.setPosition(80, 220); // Posición para Snorlax

    sf::Sprite pokeballSprite2(pokeballTexture);
    pokeballSprite2.setScale(0.5f, 0.5f);
    pokeballSprite2.setPosition(300, 80); // Posición para Tyranitar

    // Cargar la imagen de Snorlax
    sf::Texture snorlaxTexture;
    if (!snorlaxTexture.loadFromFile("./assets/images/143.png")) {
        return -1;
    }
    sf::Sprite snorlaxSprite(snorlaxTexture);
    snorlaxSprite.setScale(1.5f, 1.5f);
    snorlaxSprite.setPosition(80, 220); // Misma posición que su Pokébola
    bool snorlaxVisible = false; // Control de visibilidad



    // Reloj para controlar el tiempo
    sf::Clock clock;

    // Bucle principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Actualizar animaciones
        float elapsedTime = clock.getElapsedTime().asSeconds();
        if (elapsedTime > 2.0f) { // Después de 2 segundos
            snorlaxVisible = true;
        }
        if (elapsedTime > 3.0f) { // Después de 3 segundos
            tyranitarVisible = true;
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar elementos
        window.draw(backgroundSprite); // Fondo
        if (!snorlaxVisible) {
            window.draw(pokeballSprite1); // Pokébola de Snorlax
        } else {
            window.draw(snorlaxSprite); // Snorlax
        }

        if (!tyranitarVisible) {
            window.draw(pokeballSprite2); // Pokébola de Tyranitar
        } else {
            window.draw(tyranitarSprite); // Tyranitar
        }

        // Mostrar la ventana
        window.display();
    }

    return 0;
}