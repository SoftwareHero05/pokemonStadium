#include <Juego.h>
#include <GRAPHICS/BackGround.h>
#include <GRAPHICS/MusicManager.h>
#include <GRAPHICS/MoveGraphic.h>
#include <GRAPHICS/ImageLoader.h>
class JuegoGrafico
{
private:
    BackGround backGroundInitial, backGround;
    MusicManager musicManager;
    Image image1, image2, image3, image4, trainer1, trainer2;
    MoveGraphic MoveGraphic;

public:
    JuegoGrafico()
    {
    }
    ~JuegoGrafico() {}

    void Iniciar()
    {
        try
        {
            sf::RenderWindow window(sf::VideoMode(512, 384), "SFML with Classes");
            sf::Clock clock;
            sf::Clock fadeClock;
            bool fadingOut = false;
            bool gameStarted = false;
            // bucle de ventana de inicio
            backGroundInitial.setBackGround("./assets/images/FondoPokemon.png", window.getSize());
            sf::RectangleShape fadeOverlay(sf::Vector2f(window.getSize().x, window.getSize().y));
            fadeOverlay.setFillColor(sf::Color(0, 0, 0, 0)); // Negro completamente transparente
            while (window.isOpen() && !gameStarted)
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                    }

                    if (event.type == sf::Event::KeyPressed)
                    {
                        fadingOut = true; // Activa el efecto de desvanecimiento al presionar una tecla
                        fadeClock.restart();
                    }

                    if (fadingOut)
                    {
                        sf::Uint8 alpha = static_cast<sf::Uint8>(fadeClock.getElapsedTime().asMilliseconds()); // Incrementa el alfa
                        if (alpha > 255)
                            alpha = 255; // Límite superior para evitar sobrepasar 255
                        fadeOverlay.setFillColor(sf::Color(0, 0, 0, alpha));

                        if (alpha == 255)
                        { // Cuando el efecto de fade-out termina
                            gameStarted = true;
                        }
                    }
                }

                window.clear();
                backGroundInitial.draw(window);
                window.draw(fadeOverlay);
                window.display();
            }
            fadingOut = false;
            gameStarted = false;
            this->musicManager.changeMusic("./assets/music/Theme2.ogg");
            this->backGround.setBackGround("./assets/images/Bosque tarde - Zeo.png", window.getSize());
            this->trainer1.setImage("./assets/images/entrenadores.png", 1.0f, 1.0f, 0.2f, 70);
            this->trainer1.setTextureRect(sf::IntRect(0, 0, 195, 130));
            this->trainer2.setImage("./assets/images/entrenadores.png", 1.0f, 1.0f, 315, 200);
            this->trainer2.setTextureRect(sf::IntRect(195, 0, 196, 130));
            // bucle entrenadores
            while (window.isOpen() && !gameStarted)
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                }

                if (clock.getElapsedTime().asSeconds() >= 2.0f && !fadingOut)
                {
                    fadingOut = true;
                    fadeClock.restart();
                }

                if (fadingOut)
                {
                    float fadeTime = 1.0f;
                    float elapsedFade = fadeClock.getElapsedTime().asSeconds();
                    if (elapsedFade < fadeTime)
                    {
                        sf::Uint8 alpha = static_cast<sf::Uint8>(255 * (1.0f - elapsedFade / fadeTime));
                        trainer1.setColor(sf::Color(255, 255, 255, alpha));
                        trainer2.setColor(sf::Color(255, 255, 255, alpha));
                    }
                    else
                    {
                        trainer1.setColor(sf::Color(255, 255, 255, 0));
                        trainer2.setColor(sf::Color(255, 255, 255, 0));
                        trainer1.setVisibility(false);
                        trainer2.setVisibility(false);
                    }
                }

                // dibujos
                window.clear();
                this->backGround.draw(window);
                if (trainer1.getAlpha() > 0)
                    trainer1.draw(window);
                if (trainer2.getAlpha() > 0)
                    trainer2.draw(window);
                window.display();
                if (trainer1.getAlpha() < 0)
                    gameStarted = true;
            }
        }

        
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};