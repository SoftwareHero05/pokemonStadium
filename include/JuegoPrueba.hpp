#pragma once
#include <Bridge.h>
#include <GRAPHICS/BackGround.h>
#include <GRAPHICS/TextureManager.h>
#include <GRAPHICS/ButtonImage.h>
#include <GRAPHICS/MusicManager.h>
#include <GRAPHICS/Image.h>
#include <GRAPHICS/ButtonText.h>
#include <sstream>
class JuegoPrueba
{
private:
    SourceManager manager;
    Bridge link;
    sf::Font font;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Clock fadeClock;
    BackGround backGround;
    sf::Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11;
    Image image1, image2, image3, image4, image5, image6;
    MusicManager musicManager;
    list<ButtonText> buttonsText;
    ButtonText buttonText;
    list<ButtonImage> buttons, buttons2, buttonsPokemon;
    ButtonImage button;

public:
    JuegoPrueba() : window(sf::VideoMode(1354, 770), "SFML with Classes")

    {
        // Aquí puedes inicializar otros miembros si es necesario
        this->font = manager.getFont("pokemon-firered-leafgreen-font-recreation.ttf");
        text1.setFont(font);
        text2.setFont(font);
        text3.setFont(font);
        text4.setFont(font);
        text5.setFont(font);
        text6.setFont(font);
        text7.setFont(font);
        text8.setFont(font);
        text9.setFont(font);
        text10.setFont(font);
        text11.setFont(font);
        text1.setFillColor(sf::Color(0, 0, 0, 255));
        text2.setFillColor(sf::Color(0, 0, 0, 255));
        text3.setFillColor(sf::Color(0, 0, 0, 255));
        text4.setFillColor(sf::Color(0, 0, 0, 255));
        text5.setFillColor(sf::Color(0, 0, 0, 255));
        text6.setFillColor(sf::Color(0, 0, 0, 255));
        text7.setFillColor(sf::Color(0, 0, 0, 255));
        text8.setFillColor(sf::Color(0, 0, 0, 255));
        text9.setFillColor(sf::Color(0, 0, 0, 255));
        text10.setFillColor(sf::Color(0, 0, 0, 255));
        text11.setFillColor(sf::Color(0, 0, 0, 255));
    }
    ~JuegoPrueba() {}

    void Iniciar()
    {
        try
        {
            bool fadingOut = false;
            bool gameStarted = false;
            sf::Event event;
            // bucle de ventana de inicio
            backGround.setBackGround("FondoPokemon.png", manager, window.getSize());
            this->bucleLoadingScreen(window, gameStarted, event);
            clock.restart();
            fadeClock.restart();
            // bucle entrenadores
            gameStarted = false;
            this->musicManager.changeMusic("./assets/music/Theme2.ogg");
            this->backGround.setBackGround("Bosque tarde - Zeo.png", manager, window.getSize());
            this->image1.setImage("RED.png", manager, 0.35f, 0.25f, 150, 320);
            this->image2.setImage("GOLD.png", manager, 1.0f, 1.0f, 950, 80);
            this->bucleTrainersScreen(window, gameStarted, event, clock, fadeClock, fadingOut);
            this->image1.setImage("textbox1.png", manager, .4f, .4f, 15.0f, 300.0f);  // cuadro blanco
            this->image1.setColor(sf::Color(255, 255, 255, 255));
            this->image2.setColor(sf::Color(255, 255, 255, 255));
            clock.restart();
            fadeClock.restart();
            // bucle chooseTeam
            gameStarted = false;
            this->bucleChooseTeamScreen(window, event, 1);
            this->drawTeam(window, event, fadeClock, 1);
            this->bucleChooseTeamScreen(window, event, 2);
            this->drawTeam(window, event, fadeClock, 2);
            this->link.Getjuego().BeginCombat();
            image3.setImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 3.0f, 3.0f, 300.0f, 450.0f);  //POKEMONES EN BATALLA
            image4.setImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 3.0f, 3.0f, 850.0f, 150.0f);  // POKEMONES EN BATALLA
            this->textManger(text7, link.GetHP(1), 18U, 250, 300);
            this->textManger(text8, link.GetHP(2), 18U, 950, 300);
            this->textManger(text9, link.GetPokemonActual(1), 18U, 200, 250);
            this->textManger(text10, link.GetPokemonActual(2),  18U, 900, 250);
            this->textManger(text5, "Pokemon In Combat", 24U, 600.0f, 50.0f);
            this->textManger(text6, "Pokemon Fainted",  24U, 600.0f, 100.0f);
            this->textManger(text11, "x", 24U, 35.0f, 170.0f);
            fadeClock.restart();
            musicManager.changeMusic("./assets/music/Theme1.ogg");
            this->bucleChooseAction(window, event, fadeClock);
            gameStarted = false;
            this->bucleEnd(window, gameStarted,event);
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
            this->backGround.draw(window); // Dibuja el fondo inicial
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
            if (clock.getElapsedTime().asSeconds() > 4.0f)
                gameStarted = true;
        }
    }

    void bucleChooseTeamScreen(sf::RenderWindow &window, sf::Event &event, int player)
    {
        string choice = "";
        list<int> TeamChosen;
        int choiceInt, a = 0;
        int members = 0;
        bool ended = false;
        bool pokemonChosen = true;
        ostringstream convertidor;
        convertidor << player;
        buttons.clear();
        this->textManger(text1, "This Pokemon\nwas already\nchosen", 30U, 50.0f, 370.0f);
        this->textManger(text2, "was added to team", 30U, 50.0f, 460.0f);
        this->textManger(text3, "x", 30U, 50.0f, 430.0f);
        this->textManger(text4, "Choose your team\nPlayer: " + convertidor.str(), 30U, 50.0f, 350.0f);
        float x = 600.0f;
        float y = 50.0f;
        int i = 0;
        for (auto &&pokemon : this->link.GetAllPokemonsNamesString())
        {
            if (i > 4)
            {
                x = 1000.0f;
                a = i - 5;
            }

            button.setButton(link.GetPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 140.0f), pokemon); //
            button.setScale(1.8f , 1.8f);
            buttons.push_back(button);
            a++;
            i++;
        }
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                for (auto &button : buttons)
                {
                    if (button.handleEvent(event, window, choice))
                    {
                        choiceInt = this->link.StringToNumberPokemon(choice);
                        if (this->checkPokemon(TeamChosen, choiceInt) == false)
                        {
                            text3.setString(choice);
                            TeamChosen.push_back(choiceInt);
                            members++;
                            pokemonChosen = true;
                        }
                        else
                            pokemonChosen = false;
                    }
                }
            }

            window.clear();
            backGround.draw(window);
            image1.draw(window);
            for (auto &button : buttons)
            {
                button.draw(window);
            }
            if (pokemonChosen == true)
            {
                window.draw(text3);
                window.draw(text2);
                window.draw(text4);
            }
            else
                window.draw(text1);
            window.display();
            if (members == 6)
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

    void drawTeam(sf::RenderWindow &window, sf::Event &event, sf::Clock &clock, int player)
    {
        bool ended = false;
        int i = 0, a = 0;
        float x = 600.0f, y = 100.0f;
        ostringstream convertidor;
        list<string> team = this->link.GetTeamString(player);
        convertidor << player;
        buttons.clear();
        textManger(text2, "Player " + convertidor.str(), 30U, 50.0f, 370.0f);
        textManger(text1, "\t\t\t\t\t's\nTeam", 30U, 50.0f, 370.0f);
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 1000.0f;
                a = i - 3;
            }
            button.setButton(this->link.GetPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 150.0f), this->link.GetSpecificPokemonNameOfTeamWithIndex(i));
            button.setScale(1.8f, 1.8f);
            buttons.push_back(button);
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
            window.draw(text1);
            window.draw(text2);

            for (auto &&buton : buttons)
            {
                buton.draw(window);
            }
            window.display();
            if (clock.getElapsedTime().asSeconds() > 2.3f)
                ended = true;
        }
    }

    void bucleChooseAction(sf::RenderWindow &window, sf::Event &event, sf::Clock &clock)
    {
        buttons.clear();
        buttons2.clear();
        string choicePlayer1, choicePlayer2;
        bool player1 = true;
        this->image1.setImage("textbox1.png", manager, .3f, .3f, 100.0f, 50.0f);
        this->image2.setImage("textbox1.png", manager, .3f, .3f, 900.0f, 600.0f);
        button.setButton("attackIcon.png", manager, sf::Vector2f(600.0f, 680.0f), "attack");
        button.setScale(0.25f, 0.25f);
        buttons.push_back(button);
        button.setButton("changeIcon.png", manager, sf::Vector2f(700.0f, 680.0f), "change");
        button.setScale(.15f, .15f);
        buttons.push_back(button);
        button.setButton("attackIcon.png", manager, sf::Vector2f(1100.0f, 100.0f), "attack");
        button.setScale(.25f, .25f);                              
        buttons2.push_back(button);
        button.setButton("changeIcon.png", manager, sf::Vector2f(1200.0f, 100.0f), "change");
        button.setScale(.15f, .15f);
        buttons2.push_back(button);
        textManger(text1, this->link.GetPokemonActual(1), 1, 200.0f, 50.0f);
        textManger(text2, this->link.GetPokemonActual(2), 1, 900.0f, 50.0f);
        textManger(text3, "What Will you do \nPlayer 1", 20U, 100.0f, 50.0f);
        textManger(text4, "What Will you do \nPlayer 2", 1, 900.0f, 600.0f);
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

                for (auto &button : buttons)
                {
                    if (button.handleEvent(event, window, choicePlayer1))
                    {
                        player1 = false;
                    }
                }

                for (auto &button : buttons2)
                {
                    if (button.handleEvent(event, window, choicePlayer2))
                    {
                        if (player1 == false)
                        {
                            this->GetChoices(window, event, choicePlayer1, choicePlayer2);
                            if (this->BucleExecuteAction(window, event) == false)
                                ended = true;
                            player1 = true;
                        }
                    }
                }
            }
            this->renderCombat(window, player1);
        }
    }

    void renderCombat(sf::RenderWindow &window, bool player1)
    {
        window.clear();
        backGround.draw(window);
        if (player1 == true)
        {
            image2.draw(window);
            window.draw(text2);
            window.draw(text4);
            for (auto &actions : buttons)
            {
                actions.draw(window);
            }
        }
        else
        {
            image1.draw(window);
            window.draw(text3);
            window.draw(text4);
            for (auto &actions : buttons2)
            {
                actions.draw(window);
            }
        }
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
        image3.draw(window);
        image4.draw(window);
        window.display();
    }

    void GetChoices(sf::RenderWindow &window, sf::Event &event, string &choicePlayer1, string &choicePlayer2)
    {
        string choice1;
        string choice2;
        if (choicePlayer1 == "change")
        {
            choice1 = this->BucleChangePokemon(window, event, 1, false);
            link.setPlayerDecision(1, 2, choice1);
        }
        else
        {
            choice1 = this->BucleChooseMove(window, event, 1);
            link.setPlayerDecision(1, 1, choice1);
        }

        if (choicePlayer2 == "change")
        {
            choice2 = this->BucleChangePokemon(window, event, 2, false);
            link.setPlayerDecision(2, 2, choice2);
        }
        else
        {
            choice2 = this->BucleChooseMove(window, event, 2);
            link.setPlayerDecision(2, 1, choice2);
        }
    }

    bool BucleExecuteAction(sf::RenderWindow &window, sf::Event &event)
    {
        link.ExecuteTurn();
        string choice;
        if (this->link.IsGameOver(1) == true)
        {
            return false;
        }

        if (link.Getjuego().GetJugadorSpecific(1).GetPokemonInCombat().GetHP() < 1)
        {
            choice = this->BucleChangePokemon(window, event, 1, true);
            this->link.ExecuteChange(1, choice);
            this->link.Getjuego().ApplyChangesToPlayer(1);
        }
        if (this->link.IsGameOver(2) == true)
        {
            return false;
        }
        if (link.Getjuego().GetJugadorSpecific(2).GetPokemonInCombat().GetHP() < 1)
        {
            if (this->link.IsGameOver(2) == true)
            {
                return false;
            }
            else
            {
                choice = this->BucleChangePokemon(window, event, 2, true);
                this->link.ExecuteChange(2, choice);
                this->link.Getjuego().ApplyChangesToPlayer(2);
            }
        }
        text7.setString(link.GetHP(1));
        text8.setString(link.GetHP(2));
        text9.setString(link.GetPokemonActual(1));
        text10.setString(link.GetPokemonActual(2));
        image3.setImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 3.0f, 3.0f, 300.0f, 450.0f); //pokemones conbate 
        image4.setImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 3.0f, 3.0f, 850.0f, 150.0f); //pokemones conbate
        return true;
    }

    string BucleChangePokemon(sf::RenderWindow &window, sf::Event &event, int player, bool isFainted)
    {
        bool ended = false;
        int state = 0;
        int i = 0, a = 0;
        float x = 600.0f, y = 100.0f;
        string pokemon;
        string pokemonActual = this->link.GetPokemonActual(player);
        list<string> team = this->link.GetTeamString(player);
        list<string> fainted = this->link.GetFaintedPokemon(player);
        text11.setString(pokemonActual + "was fainted");
        buttonsPokemon.clear();
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 1000.0f;
                a = i - 3;
            }
            button.setButton(this->link.GetPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 150.0f), this->link.GetSpecificPokemonNameOfTeamWithIndex(i));
            button.setScale(1.8f, 1.8f);
            buttonsPokemon.push_back(button);
            i++;
            a++;
        }
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                for (auto &button : buttonsPokemon)
                {
                    if (button.handleEvent(event, window, pokemon))
                    {
                        if (pokemon == pokemonActual)
                            state = 1;
                        else if (this->CheckFaintedPokemons(pokemon, fainted) == false)
                            state = 2;
                        else
                            return pokemon;
                    }
                }
            }
            window.clear();
            backGround.draw(window);
            if (state == 1)
                window.draw(text5);
            if (state == 2)
                window.draw(text6);
            for (auto &&buton : buttonsPokemon)
            {
                buton.draw(window);
            }
            if (isFainted == true)
                window.draw(text11);
            window.display();
        }
        return "";
    }

    string BucleChooseMove(sf::RenderWindow &window, sf::Event &event, int player)
    {
        bool ended = false;
        int i = 0, a = 0;
        float x = 270.0f, y = 0.0f;
        string move;
        list<string> moveset = this->link.GetMoveSet(player);
        buttonsText.clear();
        for (auto &&move : moveset)
        {
            if (i > 1)
            {
                x = 400.0f;
                a = i - 1;
            }
            buttonText.setButton(manager, move, sf::Vector2f(x, y + a * 120.0f), {150, 50}, move);
            buttonsText.push_back(buttonText);
            i++;
            a++;
        }
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                for (auto &button : buttonsText)
                {
                    if (button.handleEvent(event, window, move))
                    {
                        return move;
                    }
                }
            }
            window.clear();
            backGround.draw(window);
            image1.draw(window);
            for (auto &&buton : buttonsText)
            {
                buton.draw(window);
            }
            window.display();
        }
        return "";
    }

    void bucleEnd(sf::RenderWindow &window, bool &gameStarted, sf::Event &event)
    {
        if(link.IsGameOver(1) == true) textManger(text1,"Player one has no pokemon Left\nPlayer 2 wins",50U,600,350);
        else textManger(text1,"Player one has no pokemon Left\nPlayer 2 wins",50U,600,250);
        textManger(text2,"Thanks for playing\nMade by\nJesus Baez 23310372\nHector",50U,600,400);
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
                    gameStarted = true; 
                }
            }

            window.clear();
            backGround.draw(window); 
            window.draw(text1);
            window.draw(text2);
            window.display();
        }
        
    }

    void textManger(sf::Text &text, string message, int size, float x, float y)
    {
        text.setString(message);
        text.setCharacterSize(size);
        text.setPosition(x, y);
    }

    bool CheckFaintedPokemons(string choice, list<string> fainted)
    {
        for (auto &pokemon : fainted)
        {
            if (pokemon == choice)
                return false;
        }
        return true;
    }
};
