#include <Juego.h>
#include <sstream>
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
    Image trainerImage1, trainerImage2, image1, image2, image3, image4;
    MoveGraphic MoveGraphic;
    ButtonImage buttonArregloPokemons[10], buttonArregloAction1[2], buttonArregloAction2[2];
    Text texto1, texto2, texto3, texto4;
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
            this->trainerImage1.setImage("./assets/images/entrenadores.png", 1.0f, 1.0f, 0.2f, 70);
            this->trainerImage1.setTextureRect(sf::IntRect(0, 0, 195, 130));
            this->trainerImage2.setImage("./assets/images/entrenadores.png", 1.0f, 1.0f, 315, 200);
            this->trainerImage2.setTextureRect(sf::IntRect(195, 0, 196, 130));
            this->bucleTrainersScreen(window, gameStarted, event, clock, fadeClock, fadingOut);
            clock.restart();
            fadeClock.restart();
            // bucle chooseTeam
            gameStarted = false;
            this->bucleChooseTeamScreen(window, event, 1);
            this->drawTeam(window, event, fadeClock, 1);
            this->bucleChooseTeamScreen(window, event, 2);
            this->drawTeam(window, event, fadeClock, 2);
            this->link.Getjuego().BeginCombat();
            image1.setImage(this->link.getPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), 2.2f, 1.5f, 70.0f, 210.0f);
            image2.setImage(this->link.getPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), 2.0f, 1.3f, 280.0f, 20.0f);
            image1.setVisibility(true);
            image2.setVisibility(true);
            fadeClock.restart();
            musicManager.changeMusic("./assets/music/Theme1.ogg");
            this->bucleChooseAction(window, event, fadeClock);
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
        this->image1.setImage("./assets/images/textbox1.png", .2f, .2f, 20.0f, 150.0f);
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
            this->buttonArregloPokemons[i].setButton(this->link.getPokemonImageDirectionWithInt(i, 2), sf::Vector2f(x, y + i * 75.0f), this->link.getSpecificPokemonNameWithInt(i));
        }
        x = 400.0f;
        for (int i = 0; i < 5; i++)
        {
            this->buttonArregloPokemons[i + 5].setButton(this->link.getPokemonImageDirectionWithInt(i + 5, 2), sf::Vector2f(x, y + i * 75.0f), this->link.getSpecificPokemonNameWithInt(i + 5));
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

    void drawTeam(sf::RenderWindow &window, sf::Event &event, sf::Clock &clock, int player)
    {
        bool ended = false;
        int i = 0, a = 0;
        float x = 270.0f, y = 0.0f;
        ostringstream convertidor;
        list<string> team = this->link.getTeamString(player);
        convertidor << player;
        texto2.setText("Player " + convertidor.str(), 24U, 35.0f, 170.0f);
        texto1.setText("\t\t\t\t\t's\nTeam", 24U, 35.0f, 170.0f);
        texto1.setVisibility(true);
        texto2.setVisibility(true);
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 400.0f;
                a = i - 3;
            }
            this->buttonArregloPokemons[i].setButton(this->link.getPokemonImageDirectionWithString(pokemon, 2), sf::Vector2f(x, y + a * 120.0f), this->link.getSpecificPokemonNameWithInt(i));
            this->buttonArregloPokemons[i].setScale(1.3f, 1.3f);
            i++;
            a++;
        }
        clock.restart();
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
            window.clear();
            backGround.draw(window);
            image1.draw(window);
            texto2.draw(window);
            texto1.draw(window);

            for (int j = 0; j < 6; j++)
            {
                buttonArregloPokemons[j].draw(window);
            }
            window.display();
            if (clock.getElapsedTime().asSeconds() > 2.3f)
                ended = true;
        }
    }

    void bucleChooseAction(sf::RenderWindow &window, sf::Event &event, sf::Clock &clock)
    {
        this->image3.setImage("./assets/images/textbox1.png", .15f, .2f, 50.0f, 10.0f);
        this->image4.setImage("./assets/images/textbox1.png", .17f, .2f, 280.0f, 230.0f);
        this->buttonArregloAction1[0].setButton("./assets/images/attackIcon.png", sf::Vector2f(320.0f, 255.0f), "attack");
        this->buttonArregloAction1[1].setButton("./assets/images/changeIcon.png", sf::Vector2f(400.0f, 255.0f), "change");
        this->buttonArregloAction2[0].setButton("./assets/images/attackIcon.png", sf::Vector2f(30.0f, 40.0f), "attack");
        this->buttonArregloAction2[1].setButton("./assets/images/changeIcon.png", sf::Vector2f(110.0f, 40.0f), "change");
        this->texto1.setText(this->link.GetPokemonActual(1), 1, 320.0f, 240.0f);
        this->texto2.setText(this->link.GetPokemonActual(2), 1, 320.0f, 240.0f);
        this->texto3.setText("What Will you do \nPlayer 1", 20U, 110.0f, 240.0f);
        this->texto4.setText(this->link.GetPokemonActual(2), 1, 320.0f, 240.0f);
        this->texto1.setVisibility(false);
        this->texto2.setVisibility(false);
        this->texto3.setVisibility(false);
        this->texto4.setVisibility(false);
        this->image3.setVisibility(false);
        this->image4.setVisibility(false);
        for (int i = 0; i < 2; i++)
        {
            this->buttonArregloAction1[i].setVisibility(false);
            this->buttonArregloAction1[i].setScale(.15f - i * .05f, .15f - i * .05f);
            this->buttonArregloAction2[i].setVisibility(false);
            this->buttonArregloAction2[i].setScale(.15f - i * .05f, .15f - i * .05f);
        }
        int player = 1;
        bool ended = false;
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
            this->UpdateStateCombat(player);
            this->renderCombat(window);
        }
    }

    void UpdateStateCombat(int player)
    {
        if (player == 1)
        {
            image3.setVisibility(false);
            texto2.setVisibility(false);
            image4.setVisibility(true);
            texto1.setVisibility(true);
            for (int i = 0; i < 2; i++)
            {

                buttonArregloAction1[i].setVisibility(true);
                buttonArregloAction2[i].setVisibility(false);
            }
        }
        else
        {
            texto1.setVisibility(false);
            texto2.setVisibility(true);
            image3.setVisibility(true);
            image4.setVisibility(false);
            for (int i = 0; i < 2; i++)
            {
                buttonArregloAction1[i].setVisibility(false);
                buttonArregloAction2[i].setVisibility(true);
            }
        }
    }

    void setVisibilityButtons(ButtonImage buttons[], int size, bool visibility)
    {
        for (int i = 0; i < size; i++)
        {
            buttons[i].setVisibility(visibility);
        }
    }

    void renderCombat(sf::RenderWindow &window)
    {
        window.clear();
        backGround.draw(window);
        image1.draw(window);
        image2.draw(window);
        image3.draw(window);
        image4.draw(window);
        texto1.draw(window);
        texto2.draw(window);
        for (int i = 0; i < 2; i++)
        {
            buttonArregloAction1[i].draw(window);
            buttonArregloAction2[i].draw(window);
        }
        window.display();
    }
};
