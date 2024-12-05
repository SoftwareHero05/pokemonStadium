#include <Juego.h>
#include <GRAPHICS/BackGround.h>
#include <GRAPHICS/MusicManager.h>
#include <GRAPHICS/MoveGraphic.h>
#include <GRAPHICS/ImageLoader.h>
#include <GRAPHICS/ButtonImage.h>
#include <GRAPHICS/Text.h>
#include <Bridge.h>
class JuegoGrafico
{
private:
    BackGround backGroundInitial, backGround;
    MusicManager musicManager;
    Image image1, image2, image3, image4;
    MoveGraphic MoveGraphic;
    ButtonImage buttonArreglo[10];
    Text texto1, texto2,texto3;
    Bridge link;

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
            sf::Font font;
            if (!font.loadFromFile("./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf"))
            {
                std::cerr << "No se pudo cargar la fuente.\n";
            }
            bool fadingOut = false;
            bool gameStarted = false;
            sf::Event event;
            // bucle de ventana de inicio
            backGroundInitial.setBackGround("./assets/images/FondoPokemon.png", window.getSize());
            this->bucleLoadingScreen(window, gameStarted, event);
            clock.restart();
            fadeClock.restart();
            // bucle entrenadores
            gameStarted = false;
            this->musicManager.changeMusic("./assets/music/Theme2.ogg");
            this->backGround.setBackGround("./assets/images/Bosque tarde - Zeo.png", window.getSize());
            this->image1.setImage("./assets/images/entrenadores.png", 1.0f, 1.0f, 0.2f, 70);
            this->image1.setTextureRect(sf::IntRect(0, 0, 195, 130));
            this->image2.setImage("./assets/images/entrenadores.png", 1.0f, 1.0f, 315, 200);
            this->image2.setTextureRect(sf::IntRect(195, 0, 196, 130));
            this->bucleTrainersScreen(window, gameStarted, event, clock, fadeClock, fadingOut);
            clock.restart();
            fadeClock.restart();
            // bucle chooseTeam
            gameStarted = false;
            this->bucleChooseTeamScreen(window, gameStarted, event, clock, fadeClock, fadingOut, 1);
        }

        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void bucleLoadingScreen(sf::RenderWindow &window, bool &gameStarted, sf::Event &event)
    {
        while (window.isOpen() && !gameStarted)
        {

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed)
                {
                    gameStarted = true; // Inicia el juego al presionar cualquier tecla
                }
            }

            window.clear();
            this->backGroundInitial.draw(window); // Dibuja el fondo inicial
            window.display();
        }
    }

    void bucleTrainersScreen(sf::RenderWindow &window, bool &gameStarted, sf::Event &event,
                             sf::Clock &clock, sf::Clock &fadeClock, bool &fadingOut)
    {
        while (window.isOpen() && !gameStarted)
        {
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
                    image1.setColor(sf::Color(255, 255, 255, alpha));
                    image2.setColor(sf::Color(255, 255, 255, alpha));
                }
                else
                {
                    image1.setColor(sf::Color(255, 255, 255, 0));
                    image2.setColor(sf::Color(255, 255, 255, 0));
                    image1.setVisibility(false);
                    image2.setVisibility(false);
                }
            }

            // dibujos
            window.clear();
            this->backGround.draw(window);
            if (image1.getAlpha() > 0)
                image1.draw(window);
            if (image2.getAlpha() > 0)
                image2.draw(window);
            window.display();
            if (clock.getElapsedTime().asSeconds() > 3.0f)
                gameStarted = true;
        }
    }

    void bucleChooseTeamScreen(sf::RenderWindow &window, bool &gameStarted, sf::Event &event,
                               sf::Clock &clock, sf::Clock &fadeClock, bool &fadingOut, int player)
    {
        string choice;
        list<int> TeamChosen;
        int choiceInt, a = 0;
        bool ended = false;
        this->image3.setImage("./assets/images/textbox1.png", .2f, .2f, 20.0f, 150.0f);
        this->texto1.setText("Este Pokemon \nya fue escogido", "./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf", 18U, 32.0f, 170.0f);
        this->texto2.setText("fue agregado \nal equipo", "./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf", 18U, 34.0f, 188.0f);
        this->texto3.setText("x", "./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf",18U, 34.0f, 170.0f);
        this->texto1.setColor(sf::Color(0, 0, 0, 255));
        this->texto2.setColor(sf::Color(0, 0, 0, 255));
        this->texto3.setColor(sf::Color(0, 0, 0, 255));
        this->texto1.setVisibility(false);
        this->texto2.setVisibility(false);
        this->texto3.setVisibility(false);
        float x = 250.0f, y = 0.f;
        for (int i = 0; i < 5; i++)
        {
            this->buttonArreglo[i].setButton(this->link.getPokemonImageDirection(i, 2), sf::Vector2f(x, y + i * 75.0f), this->link.getSpecificPokemonName(i));
        }
        x = 400.0f;
        for (int i = 0; i < 5; i++)
        {
            this->buttonArreglo[i + 5].setButton(this->link.getPokemonImageDirection(i + 5, 2), sf::Vector2f(x, y + i * 75.0f), this->link.getSpecificPokemonName(i + 5));
        }

        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                for (auto &button : buttonArreglo)
                {
                    if (button.handleEvent(event, window, choice))
                    {
                        choiceInt = this->link.StringToNumberPokemon(choice);
                        if (this->checkPokemon(TeamChosen, choiceInt) == false)
                        {
                            TeamChosen.push_back(choiceInt);
                            a++;
                            this->texto3.setString(choice);
                            this->texto1.setVisibility(false);
                            this->texto2.setVisibility(true);
                            this->texto3.setVisibility(true);

                        }
                        else
                        {
                            this->texto2.setVisibility(false);
                            this->texto3.setVisibility(false);
                            this->texto1.setVisibility(true);
                        }
                    }
                }

                window.clear();
                backGround.draw(window);
                image3.draw(window);
                for (auto &button : buttonArreglo)
                {
                    button.draw(window);
                }
                texto1.draw(window);
                texto2.draw(window);
                texto3.draw(window);
                window.display();
                if (a == 6)
                {
                    this->link.AsignTeam(TeamChosen, player);
                    ended = true;
                }
            }
        }
    }

    bool checkPokemon(list<int> teamChosen, int opcion)
    {
        for (auto &pokemon : teamChosen)
        {
            if (pokemon == opcion)
            {
                return true;
            }
        }
        return false;
    }
};
