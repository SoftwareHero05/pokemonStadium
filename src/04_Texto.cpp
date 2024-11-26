#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

int main()
{

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


    sf::Music music;
    if (!music.openFromFile("./assets/music/batalla01.ogg")) {
        // Error al cargar el archivo de música
        return -1;
    }

    music.setLoop(true); // Hace que la música se repita
    music.play();        // Reproducir la música

    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(512, 384), "SFML Image");

    // Cargar la imagen de fondo desde un archivo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./assets/images/Bosque tarde - Zeo.png")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    // --- ENTRENADORES ---
    sf::Texture entrenadoresTexture;
    if (!entrenadoresTexture.loadFromFile("./assets/images/entrenadores.png")) {
        return -1;
    }

    int entrenadoresWidth = entrenadoresTexture.getSize().x / 2;
    int entrenadoresHeight = entrenadoresTexture.getSize().y;

    sf::IntRect entrenador1Rect(0 * entrenadoresWidth, 0 * entrenadoresHeight, entrenadoresWidth, entrenadoresHeight); // Primer sprite
    sf::Sprite entrenador1Sprite(entrenadoresTexture);
    entrenador1Sprite.setTextureRect(entrenador1Rect);
    entrenador1Sprite.setScale(1.0f, 1.0f);
    entrenador1Sprite.setPosition(.2, 70);

    sf::IntRect entrenador2Rect(1 * entrenadoresWidth, 0 * entrenadoresHeight, entrenadoresWidth, entrenadoresHeight); // Segundo sprite
    sf::Sprite entrenador2Sprite(entrenadoresTexture);
    entrenador2Sprite.setTextureRect(entrenador2Rect);
    entrenador2Sprite.setScale(1.0f, 1.0f);
    entrenador2Sprite.setPosition(315, 200);

    // Cargar la imagen de gardevoir
    sf::Texture gardevoirTexture;
    if (!gardevoirTexture.loadFromFile("./assets/images/282.png")) {
        return -1;
    }

    // Configurar el sprite de gardevoir
    sf::Sprite gardevoirSprite(gardevoirTexture);
    gardevoirSprite.setScale(1.5f, 1.5f); // Escalar el sprite
    gardevoirSprite.setPosition(75, 200); // Posicionar a gardevoir en la ventana
    bool gardevoirVisible = false; // Control de visibilidad

    // garchomp //
    sf::Texture garchompTexture;
    if (!garchompTexture.loadFromFile("./assets/images/445.png")) {
        return -1;
    }

    sf::IntRect garchompRect(0, 0, garchompTexture.getSize().x, garchompTexture.getSize().y);
    sf::Sprite garchompSprite(garchompTexture);
    garchompSprite.setTextureRect(garchompRect);
    garchompSprite.setScale(1.5f, 1.5f); // Escalar
    garchompSprite.setPosition(300, 70); // Posicionar
    bool garchompVisible = false; // Control de visibilidad

    sf::Clock clock;
    float duration = 4.0f;
    sf::Clock fadeClock; // Reloj para el fade-out
    bool fadingOut = false; // Indicador para saber si los entrenadores están desapareciendo

    // Bucle principal
    while (window.isOpen()) {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float elapsedTime = clock.getElapsedTime().asSeconds();
        if (elapsedTime > 2.0f) { // Después de 2 segundos
            gardevoirVisible = true;
        }
        if (elapsedTime > 3.0f) { // Después de 3 segundos
            garchompVisible = true;
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el fondo
        window.draw(backgroundSprite);

        // Actualización del efecto de desvanecimiento
        if (clock.getElapsedTime().asSeconds() >= duration && !fadingOut) {
            fadingOut = true; // Inicia el desvanecimiento
            fadeClock.restart(); // Reinicia el reloj del fade-out
        }

        if (fadingOut) {
            float fadeTime = 2.0f; // Duración del efecto de fade-out (en segundos)
            float elapsedFade = fadeClock.getElapsedTime().asSeconds();
            if (elapsedFade < fadeTime) {
                // Calcula la nueva opacidad (255 a 0)
                sf::Uint8 alpha = static_cast<sf::Uint8>(255 * (1.0f - elapsedFade / fadeTime));
                entrenador1Sprite.setColor(sf::Color(255, 255, 255, alpha));
                entrenador2Sprite.setColor(sf::Color(255, 255, 255, alpha));
            } else {
                // Una vez completado el fade-out, haz completamente invisibles los entrenadores
                entrenador1Sprite.setColor(sf::Color(255, 255, 255, 0));
                entrenador2Sprite.setColor(sf::Color(255, 255, 255, 0));
            }
        }

        // Dibujar a los entrenadores (solo si no son completamente transparentes)
        if (entrenador1Sprite.getColor().a > 0 || entrenador2Sprite.getColor().a > 0) {
            window.draw(entrenador1Sprite);
            window.draw(entrenador2Sprite);
        }

        if (!gardevoirVisible) {
            window.draw(pokeballSprite1); // Pokébola de Snorlax
        } else {
            window.draw(gardevoirSprite); // Snorlax
        }

        if (!garchompVisible) {
            window.draw(pokeballSprite2); // Pokébola de Tyranitar
        } else {
            window.draw(garchompSprite); // Tyranitar
        }

        // Mostrar la ventana
        window.display();
    }

    return 0;
}