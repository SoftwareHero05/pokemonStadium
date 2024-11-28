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
    if (!music.openFromFile("./assets/music/batalla01.ogg")){
        // Error al cargar el archivo de música
        return -1;
    }
    
    music.setLoop(true); // hace que la musica se repita 
    // Reproducir la música
    music.play();


    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(512, 384), "SFML Image");

    // Cargar la imagen de fondo desde un archivo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./assets/images/Bosque tarde - Zeo.png"))
    {
        return -1;
    }

    // Crear un sprite para el fondo y asignarle la textura
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

    // Cargar la imagen de dragonite
   
      sf::Texture flameTexture;
    if (!flameTexture.loadFromFile("./assets/images/00011.png")) // Usamos tu imagen subida
    {
        return -1;
    }

    ///////---dragonite---//////
     sf::Texture dragoniteTexture;
    if (!dragoniteTexture.loadFromFile("./assets/images/149.png"))
    {
        return -1;
    }

    // Dimensiones de cada sprite individual (4x4 sprites)
    int spriteWidth = dragoniteTexture.getSize().x / 4;  // Ancho de una celda
    int spriteHeight = dragoniteTexture.getSize().y / 4; // Alto de una celda

    // --- dragonite ---
    // Seleccionar la celda dedragonite (espalda: 3ª fila, 1ª columna)
    sf::IntRect dragoniteRect(0 * spriteWidth, 3 * spriteHeight, spriteWidth, spriteHeight);
    sf::Sprite dragoniteSprite(dragoniteTexture);
    dragoniteSprite.setTextureRect(dragoniteRect);
    dragoniteSprite.setScale(5.0f, 5.0f); // Escalar a doble tamaño
    dragoniteSprite.setPosition(80, 220); // Posición en la ventana
    bool dragoniteVisible = false; // Control de visibilidad

    sf::Sprite flameSprite(flameTexture);
    flameSprite.setScale(0.2f, 0.2f); 
    flameSprite.setPosition(140, 240); // Posición inicial de la flama
    flameSprite.setColor(sf::Color(255, 255, 255, 0)); // Hacemos invisible la flama al inicio

    sf::Vector2f flameStartPos(140, 240); // Posición inicial de la flama (dragonite)
    sf::Vector2f flameEndPos(300, 80);   // Posición final de la flama (Lucario)
    sf::Clock flameMoveClock;            // Reloj para medir el tiempo del movimiento
    float flameMoveDuration = 0.5f;      // Duración del movimiento (en segundos)
    bool flameMoving = false;            // Indicador de animación de movimiento
 
   
    sf::Clock animationClock; 
    int currentFrame = 0; 
    bool animating = false; 
    float frameDuration = 0.2f; 

    std::vector<sf::IntRect> animationFrames = {
        {0 * spriteWidth, 3 * spriteHeight, spriteWidth, spriteHeight},
        {1 * spriteWidth, 3 * spriteHeight, spriteWidth, spriteHeight},
        {2 * spriteWidth, 3 * spriteHeight, spriteWidth, spriteHeight},
        {3 * spriteWidth, 3 * spriteHeight, spriteWidth, spriteHeight}
    };

    dragoniteSprite.setTextureRect(animationFrames[0]);
    
    
    
    // --- GENGAR ---
      // Cargar la imagen de gengar
    sf::Texture gengarTexture;
    if (!gengarTexture.loadFromFile("./assets/images/094.png"))
    {
        return -1;
    }

   
    // Seleccionar la celda de gengar (frente: 4ª fila, 1ª columna)
    sf::IntRect gengarRect(0 * spriteWidth, 0 * spriteHeight, spriteWidth, spriteHeight);
    sf::Sprite gengarSprite(gengarTexture);
    gengarSprite.setTextureRect(gengarRect);
    gengarSprite.setScale(2.0f, 2.0f); // Escalar a doble tamaño
    gengarSprite.setPosition(300, 80); // Posición en la ventana
    bool gengarVisible = false; // Control de visibilidad




    sf::Clock clock;
    float duration = 4.0f; 
    sf::Clock fadeClock; // Reloj para el fade-out
    bool fadingOut = false; // Indicador para saber si los entrenadores están desapareciendo
    

    // Bucle principal
    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
            animating = true;
            currentFrame = 0;
            animationClock.restart();
            flameSprite.setColor(sf::Color(255, 255, 255, 255)); // Hacemos visible la flama
            flameMoving = true; // Iniciar movimiento de la flama
            flameMoveClock.restart(); // Reiniciar el reloj para el movimiento
            }
            
        }
        float elapsedTime = clock.getElapsedTime().asSeconds();
        if (elapsedTime > 2.0f) { // Después de 2 segundos
            dragoniteVisible = true;
        }
        if (elapsedTime > 3.0f) { // Después de 3 segundos
            gengarVisible = true;
        }

         if (animating)
        {
            if (animationClock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame++;
                if (currentFrame >= animationFrames.size())
                {
                    animating = false; 
                    currentFrame = 0; 
                    flameSprite.setColor(sf::Color(255, 255, 255, 0)); // Ocultamos la flama
                }
                else
                {
                    dragoniteSprite.setTextureRect(animationFrames[currentFrame]);
                }
                animationClock.restart();
            }
        }

        if (flameMoving) {
             float elapsedTime = flameMoveClock.getElapsedTime().asSeconds();
                if (elapsedTime < flameMoveDuration) {
                // Interpolación lineal entre la posición inicial y final
                float t = elapsedTime / flameMoveDuration; // Normalizar el tiempo (0 a 1)
                flameSprite.setPosition(
                flameStartPos.x + t * (flameEndPos.x - flameStartPos.x),
                flameStartPos.y + t * (flameEndPos.y - flameStartPos.y)
                                        );
    } else {
        // Finalizar el movimiento
        flameMoving = false;
        flameSprite.setPosition(flameEndPos); // Asegurar posición final exacta
    }
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


    
    if (animating || flameMoving) {
    window.draw(flameSprite);
}

        if (!dragoniteVisible) {
            window.draw(pokeballSprite1); // Pokébola de Snorlax
        } else {
            window.draw(dragoniteSprite); // Snorlax
        }

        if (!gengarVisible) {
            window.draw(pokeballSprite2); // Pokébola de Tyranitar
        } else {
            window.draw(gengarSprite); // Tyranitar
        }


        // Mostrar la ventana
        window.display();
    }

    return 0;
}