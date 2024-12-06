#pragma once
#include <Juego.h>
#include <sstream>
#include <GRAPHICS/BackGround.h>
#include <GRAPHICS/MusicManager.h>
#include <GRAPHICS/MoveGraphic.h>
#include <GRAPHICS/ImageLoader.h>
#include <GRAPHICS/ButtonImage.h>
#include <GRAPHICS/Text.h>
#include <Bridge.h>
#include <GRAPHICS/TextureManager.h>


class JuegoGrafico
{
private:
    BackGround backGroundInitial, backGround;
    MusicManager musicManager;
    Image trainerImage1, trainerImage2, image1, image2, image3, image4;
    ButtonImage buttonArregloPokemons[10];
    Text texto1, texto2, texto3, texto4;
    TextureManager manager;
    Bridge link;

public:
    JuegoGrafico()
        : texto1("./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf"),
          texto2("./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf"),
          texto3("./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf"),
          texto4("./assets/fonts/pokemon-firered-leafgreen-font-recreation.ttf")
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
            this->trainerImage1.setImage("./assets/images/entrenadores.png", manager,1.0f, 1.0f, 0.2f, 70);
            this->trainerImage1.setTextureRect(sf::IntRect(0, 0, 195, 130));
            this->trainerImage2.setImage("./assets/images/entrenadores.png", manager,1.0f, 1.0f, 315, 200);
            this->trainerImage2.setTextureRect(sf::IntRect(195, 0, 196, 130));
            this->bucleTrainersScreen(window, gameStarted, event, clock, fadeClock, fadingOut);
            clock.restart();
            fadeClock.restart();
            // bucle chooseTeam
            gameStarted = false;
            this->bucleChooseTeamScreen(window, event, 1);
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
                    trainerImage1.setColor(sf::Color(255, 255, 255, alpha));
                    trainerImage2.setColor(sf::Color(255, 255, 255, alpha));
                }
                else
                {
                    trainerImage1.setColor(sf::Color(255, 255, 255, 0));
                    trainerImage2.setColor(sf::Color(255, 255, 255, 0));
                    trainerImage1.setVisibility(false);
                    trainerImage2.setVisibility(false);
                }
            }

            // dibujos
            window.clear();
            this->backGround.draw(window);
            if (trainerImage1.getAlpha() > 0)
                trainerImage1.draw(window);
            if (trainerImage2.getAlpha() > 0)
                trainerImage2.draw(window);
            window.display();
            if (clock.getElapsedTime().asSeconds() > 4.0f)
                gameStarted = true;
        }
    }

    void bucleChooseTeamScreen(sf::RenderWindow &window, sf::Event &event, int player)
    {
        string choice;
        list<int> TeamChosen;
        int choiceInt, a = 0;
        bool ended = false;
        ostringstream convertidor;
        convertidor << player;
        this->image1.setImage("./assets/images/textbox1.png", manager,.2f, .2f, 20.0f, 150.0f);
        this->texto1.setText("This Pokemon\nwas already\nchosen", 18U, 32.0f, 170.0f);
        this->texto2.setText("was added\nto team", 18U, 34.0f, 188.0f);
        this->texto3.setText("x", 18U, 34.0f, 170.0f);
        this->texto4.setText("Choose your team\nPlayer: " + convertidor.str(), 20U, 37.0f, 90.0f);
        this->texto1.setColor(sf::Color(0, 0, 0, 255));
        this->texto2.setColor(sf::Color(0, 0, 0, 255));
        this->texto3.setColor(sf::Color(0, 0, 0, 255));
        this->texto4.setColor(sf::Color(0, 0, 0, 255));
        this->texto1.setVisibility(false);
        this->texto2.setVisibility(false);
        this->texto3.setVisibility(false);
        float x = 250.0f, y = 0.f;
        
        for (int i = 0; i < 5; i++)
        {
            this->buttonArregloPokemons[i].setButton(this->link.getPokemonImageDirectionWithInt(i, 2),manager, sf::Vector2f(x, y + i * 75.0f), this->link.getSpecificPokemonNameWithInt(i));
        }
        x = 400.0f;
        for (int i = 0; i < 5; i++)
        {
            this->buttonArregloPokemons[i + 5].setButton(this->link.getPokemonImageDirectionWithInt(i + 5, 2),manager, sf::Vector2f(x, y + i * 75.0f), this->link.getSpecificPokemonNameWithInt(i + 5));
        }
        
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                for (auto &button : buttonArregloPokemons)
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
            }

                window.clear();
                backGround.draw(window);
                image1.draw(window);
                for (auto &button : buttonArregloPokemons)
                {
                    button.draw(window);
                }
                texto4.draw(window);
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
