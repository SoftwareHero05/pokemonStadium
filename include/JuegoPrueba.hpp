#pragma once
#include <Bridge.h>
#include <GRAPHICS/BackGround.h>
#include <GRAPHICS/SourceManager.h>
#include <GRAPHICS/ButtonImage.h>
#include <GRAPHICS/MusicManager.h>
#include <GRAPHICS/Image.h>
#include <GRAPHICS/ButtonText.h>
#include <GRAPHICS/SoundManager.h>
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
    SoundManager sound;
    sf::Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12, text13, text14, text15;
    Image image1, image2, image3, image4, image5, image6, image7, image8, image9;
    MusicManager musicManager;
    list<ButtonText> buttonsText;
    ButtonText buttonText;
    list<ButtonImage> buttons, buttons2, buttonsPokemon;
    ButtonImage button;

public:
    JuegoPrueba() : window(sf::VideoMode(1354, 770), "SFML with Classes")

    {
        // Aquí puedes inicializar otros miembros si es necesario
        this->font = manager.GetFont("pokemon-firered-leafgreen-font-recreation.ttf");
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
        text12.setFont(font);
        text13.setFont(font);
        text14.setFont(font);
        text15.setFont(font);
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
        text12.setFillColor(sf::Color(0, 0, 0, 255));
        text13.setFillColor(sf::Color(0, 0, 0, 255));
        text14.setFillColor(sf::Color(0, 0, 0, 255));
        text15.setFillColor(sf::Color(0, 0, 0, 255));
        sound.SetLoop(false);
        sound.SetVolume(50.0f);
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
            backGround.SetBackGround("FondoPokemon.png", manager, window.getSize());
            this->DrawLoadingScreen(gameStarted, event);
            clock.restart();
            fadeClock.restart();
            // bucle entrenadores
            gameStarted = false;
            this->musicManager.ChangeMusic("./assets/music/Theme2.ogg");
            this->backGround.SetBackGround("Bosque tarde - Zeo.png", manager, window.getSize());
            this->image1.SetImage("RED.png", manager, 0.35f, 0.25f, 150, 320);
            this->image2.SetImage("GOLD.png", manager, 1.0f, 1.0f, 950, 80);
            this->DrawTrainersScreen(gameStarted, event, clock, fadeClock, fadingOut);
            this->image1.SetImage("textbox1.png", manager, 0.4f, 0.4f, 20.0f, 300.0f);
            this->image1.SetColor(sf::Color(255, 255, 255, 255));
            this->image2.SetColor(sf::Color(255, 255, 255, 255));
            clock.restart();
            fadeClock.restart();
            // bucle chooseTeam
            gameStarted = false;
            this->DrawChooseTeamScreen(event, 1);
            this->DrawTeam(event, fadeClock, 1);
            this->DrawChooseTeamScreen(event, 2);
            this->DrawTeam(event, fadeClock, 2);
            this->link.Getjuego().BeginCombat();
            image3.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 3.0f, 3.0f, 300.0f, 450.0f); // POKEMONES EN BATALLA
            image4.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 3.0f, 3.0f, 850.0f, 150.0f); // POKEMONES EN BATALLA
            image5.SetImage("pokeball.png", manager, 1.0f, 1.3f, 80.0f, 220.0f);
            image6.SetImage("pokeball.png", manager, 1.0f, 1.3f, 280.0f, 20.0f);

            image9.SetImage("textBox1.png", manager, .43f, .4f, 800.0f, 500.0f);              
            this->SetText(text12, "", 18U, 150, 200);                                         
            this->SetText(text13, "", 18U, 50, 50);                                           
            this->SetText(text1, "Player 1 Sends" + link.GetPokemonActual(1), 22U, 320, 710); 
            this->SetText(text2, "Player 2 Sends" + link.GetPokemonActual(2), 22U, 850, 150); 
            this->SetText(text14, "", 25U, 830, 600);  //textos que van dentro de la caja   20U, 950.0f, 620.0f                                    
            this->SetText(text15, "", 25U, 830, 600);  //textos que van dentro de la caja                                      
            this->SetText(text7, link.GetHP(1), 22U, 350, 440);   //vida del primerp
            this->SetText(text8, link.GetHP(2), 22U, 950, 150);   //vida del segundo
            this->SetText(text9, link.GetPokemonActual(1), 22U, 400, 440);  //nombre del pokemon 1
            this->SetText(text10, link.GetPokemonActual(2), 22U, 1000, 150); //nombre del pokemon 2

            image9.SetImage("textBox1.png", manager, .4f, .4f, 800.0f, 500.0f);
            this->SetText(text12, "", 18U, 150, 200);
            this->SetText(text13, "", 18U, 50, 50);
            this->SetText(text1, "Player 1 Sends" + link.GetPokemonActual(1), 22U, 320, 710);
            this->SetText(text2, "Player 2 Sends" + link.GetPokemonActual(2), 22U, 850, 150);
            this->SetText(text14, "", 25U, 830, 600);                        // textos que van dentro de la caja   20U, 950.0f, 620.0f
            this->SetText(text15, "", 25U, 830, 600);                        // textos que van dentro de la caja
            this->SetText(text7, link.GetHP(1), 22U, 350, 440);              // vida del primerp
            this->SetText(text8, link.GetHP(2), 22U, 950, 150);              // vida del segundo
            this->SetText(text9, link.GetPokemonActual(1), 22U, 400, 440);   // nombre del pokemon 1
            this->SetText(text10, link.GetPokemonActual(2), 22U, 1000, 150); // nombre del pokemon 2

            this->SetText(text5, "Pokemon In Combat", 24U, 900.0f, 690.0f);
            this->SetText(text6, "Pokemon Fainted", 24U, 900.0f, 690.0f);
            this->SetText(text11, "x", 24U, 890.0f, 600.0f);
            musicManager.ChangeMusic("./assets/music/Theme1.ogg");
            this->DrawBattleBegins(event, fadeClock);
            this->SetText(text1, "", 18U, 150, 200); // new
            this->SetText(text2, "", 18U, 50, 50);   // new
            this->DrawCombat(event, fadeClock);
            gameStarted = false;
            this->DrawEnd(gameStarted, event);
        }

        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void DrawLoadingScreen(bool &gameStarted, sf::Event &event)
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
            this->backGround.Draw(window); // Dibuja el fondo inicial
            window.display();
        }
    }

    void DrawTrainersScreen(bool &gameStarted, sf::Event &event,
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
                    image1.SetColor(sf::Color(255, 255, 255, alpha));
                    image2.SetColor(sf::Color(255, 255, 255, alpha));
                }
                else
                {
                    image1.SetColor(sf::Color(255, 255, 255, 0));
                    image2.SetColor(sf::Color(255, 255, 255, 0));
                    image1.SetVisibility(false);
                    image2.SetVisibility(false);
                }
            }

            // dibujos
            window.clear();
            this->backGround.Draw(window);
            if (image1.GetAlpha() > 0)
                image1.Draw(window);
            if (image2.GetAlpha() > 0)
                image2.Draw(window);
            window.display();
            if (clock.getElapsedTime().asSeconds() > 4.0f)
                gameStarted = true;
        }
    }

    void DrawChooseTeamScreen(sf::Event &event, int player)
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
        this->SetText(text1, "This Pokemon\nwas already\nchosen", 30U, 50.0f, 370.0f);
        this->SetText(text2, "was added to team", 30U, 50.0f, 460.0f);
        this->SetText(text3, "x", 30U, 50.0f, 430.0f);
        this->SetText(text4, "Choose your team\nPlayer: " + convertidor.str(), 30U, 50.0f, 350.0f);
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

            button.SetButton(link.GetPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 140.0f), pokemon); //
            button.SetScale(1.8f, 1.8f);
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
                        choiceInt = this->link.ChangeStringToNumberPokemon(choice);
                        if (this->CheckPokemon(TeamChosen, choiceInt) == false)
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
            backGround.Draw(window);
            image1.Draw(window);
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

    bool CheckPokemon(list<int> teamChosen, int opcion)
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

    void DrawTeam(sf::Event &event, sf::Clock &clock, int player)
    {
        bool ended = false;
        int i = 0, a = 0;
        float x = 600.0f, y = 100.0f;
        ostringstream convertidor;
        list<string> team = this->link.GetTeamString(player);
        convertidor << player;
        buttons.clear();
        SetText(text2, "Player " + convertidor.str(), 30U, 50.0f, 370.0f);
        SetText(text1, "\t\t\t\t\t's\nTeam", 30U, 50.0f, 370.0f);
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 1000.0f;
                a = i - 3;
            }
            button.SetButton(this->link.GetPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 150.0f), this->link.GetSpecificPokemonNameOfTeamWithIndex(i));
            button.SetScale(1.8f, 1.8f);
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
            backGround.Draw(window);
            image1.Draw(window);
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

    void DrawCombat(sf::Event &event, sf::Clock &clock)
    {
        buttons.clear();
        buttons2.clear();
        string choicePlayer1, choicePlayer2;
        bool player1 = true;
        this->image1.SetImage("textbox1.png", manager, .3f, .3f, 100.0f, 50.0f);
        this->image2.SetImage("textbox1.png", manager, .3f, .3f, 900.0f, 600.0f);
        button.SetButton("attackIcon.png", manager, sf::Vector2f(980.0f, 650.0f), "attack");
        button.SetScale(0.25f, 0.25f);
        buttons.push_back(button);
        button.SetButton("changeIcon.png", manager, sf::Vector2f(1100.0f, 650.0f), "change");
        button.SetScale(.15f, .15f);
        buttons.push_back(button);
        button.SetButton("attackIcon.png", manager, sf::Vector2f(160.0f, 120.0f), "attack");
        button.SetScale(.25f, .25f);
        buttons2.push_back(button);
        button.SetButton("changeIcon.png", manager, sf::Vector2f(260.0f, 120.0f), "change");
        button.SetScale(.15f, .15f);
        buttons2.push_back(button);
        SetText(text3, "What Will you do Player 2", 20U, 140.0f, 80.0f);
        SetText(text4, "What Will you do Player 1", 20U, 950.0f, 620.0f);
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
                            this->GetChoices(event, choicePlayer1, choicePlayer2);
                            if (this->ExecuteCombat(event) == false)
                                ended = true;
                            player1 = true;
                        }
                    }
                }
            }
            this->RenderCombat(player1);
        }
    }

    void RenderCombat(bool player1)
    {
        window.clear();
        backGround.Draw(window);
        if (player1 == true)
        {
            image2.Draw(window);
            window.draw(text4);
            for (auto &actions : buttons)
            {
                actions.draw(window);
            }
        }
        else
        {
            image1.Draw(window);
            window.draw(text3);
            for (auto &actions : buttons2)
            {
                actions.draw(window);
            }
        }
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
        image3.Draw(window);
        image4.Draw(window);
        window.display();
    }

    void GetChoices(sf::Event &event, string &choicePlayer1, string &choicePlayer2)
    {
        string choice1;
        string choice2;
        if (choicePlayer1 == "change")
        {
            choice1 = this->DrawChangePokemon(event, 1, false);
            link.SetPlayerDecision(1, 2, choice1);
        }
        else
        {
            choice1 = this->DrawChooseMove(event, 1);
            link.SetPlayerDecision(1, 1, choice1);
        }

        if (choicePlayer2 == "change")
        {
            choice2 = this->DrawChangePokemon(event, 2, false);
            link.SetPlayerDecision(2, 2, choice2);
        }
        else
        {
            choice2 = this->DrawChooseMove(event, 2);
            link.SetPlayerDecision(2, 1, choice2);
        }
    }

    bool ExecuteCombat(sf::Event &event)
    {
        // new de aqui
        string pastPokemon1 = this->link.GetPokemonActual(1);
        string pastPokemon2 = this->link.GetPokemonActual(2);
        bool support;
        image7.SetImage(this->link.GetPokemonImageDirectionWithString(pastPokemon1, 1), manager, 3.0f, 3.0f, 300.0f, 450.0f);
        image8.SetImage(this->link.GetPokemonImageDirectionWithString(pastPokemon2, 2), manager, 3.0f, 3.0f, 850.0f, 150.0f);
        text1.setString(link.GetHP(1));
        text2.setString(link.GetHP(2));
        text12.setString(link.GetPokemonActual(1));
        text13.setString(link.GetPokemonActual(2));
        // pa aca
        link.ExecuteTurn();
        text7.setString(link.GetHP(1));
        text8.setString(link.GetHP(2));
        text9.setString(link.GetPokemonActual(1));
        text10.setString(link.GetPokemonActual(2));
        image3.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 3.0f, 3.0f, 300.0f, 450.0f); // pokemones conbate
        image4.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 3.0f, 3.0f, 850.0f, 150.0f); // pokemones conbate
        ExecuteAnimations(event, pastPokemon1, pastPokemon2);
        string choice;
        if (link.Getjuego().GetJugadorSpecific(1).GetPokemonInCombat().GetHP() < 1)
        {
            if (link.GetDecisionPlayer(1) != 1)
                support = true;
            else
                support = false;
            DrawFaintedPokemonAnimationPlayer1(event, fadeClock, pastPokemon1, support);
            image7.SetColor(sf::Color(255, 255, 255, 255));
            if (this->link.IsGameOver(1) == true)
            {
                return false;
            }
            else
            {
                choice = this->DrawChangePokemon(event, 1, true);
                this->link.ExecuteChange(1, choice);
                this->link.Getjuego().ApplyChangesToPlayer(1);
                text7.setString(link.GetHP(1));
                text9.setString(link.GetPokemonActual(1));
                image3.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 3.0f, 3.0f, 300.0f, 450.0f);
                DrawChangeFaintedPokemonAnimationPlayer1(event, fadeClock);
            }
        }

        if (link.Getjuego().GetJugadorSpecific(2).GetPokemonInCombat().GetHP() < 1)
        {
            if (link.GetDecisionPlayer(2) != 1)
                support = true;
            else
                support = false;
            DrawFaintedPokemonAnimationPlayer2(event, fadeClock, pastPokemon2, support);
            image8.SetColor(sf::Color(255, 255, 255, 255));
            if (this->link.IsGameOver(2) == true)
            {
                return false;
            }
            else
            {
                choice = this->DrawChangePokemon(event, 2, true);
                this->link.ExecuteChange(2, choice);
                this->link.Getjuego().ApplyChangesToPlayer(2);
                text8.setString(link.GetHP(2));
                text10.setString(link.GetPokemonActual(2));
                image4.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 3.0f, 3.0f, 850.0f, 150.0f);
                DrawChangeFaintedPokemonAnimationPlayer2(event, fadeClock);
            }
        }
        return true;
    }
    // new
    void ExecuteAnimations(sf::Event &event, string &pastPokemon1, string &pastPokemon2) // new
    {
        if (link.GetDecisionPlayer(1) != 1)
            DrawChangePokemonAnimationPlayer1(event, fadeClock, pastPokemon1);

        if (link.GetDecisionPlayer(2) != 1)
            DrawChangePokemonAnimationPlayer2(event, fadeClock, pastPokemon2);

        if (link.IsPlayer1Faster() == true)
        {
            if (link.GetDecisionPlayer(1) == 1)
                DrawMoveMessage(event, fadeClock, link.GetPokemonActual(1), 1);
            if (link.Getjuego().GetJugadorSpecific(2).GetPokemonInCombat().GetHP() > 1 && link.GetDecisionPlayer(2) == 1)
                DrawMoveMessage(event, fadeClock, link.GetPokemonActual(2), 2);
        }
        else
        {
            if (link.GetDecisionPlayer(2) == 1)
                DrawMoveMessage(event, fadeClock, link.GetPokemonActual(2), 2);
            if (link.Getjuego().GetJugadorSpecific(1).GetPokemonInCombat().GetHP() > 1 && link.GetDecisionPlayer(1) == 1)
                DrawMoveMessage(event, fadeClock, link.GetPokemonActual(1), 1);
        }
    }

    string DrawChangePokemon(sf::Event &event, int player, bool isFainted)
    {
        bool ended = false;
        int state = 0;
        int i = 0, a = 0;
        float x = 600.0f, y = 100.0f;
        string pokemon;
        string pokemonActual = this->link.GetPokemonActual(player);
        list<string> team = this->link.GetTeamString(player);
        list<string> fainted = this->link.GetFaintedPokemon(player);
        text11.setString(pokemonActual + " was fainted");
        buttonsPokemon.clear();
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 1000.0f;
                a = i - 3;
            }
            button.SetButton(this->link.GetPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 150.0f), this->link.GetSpecificPokemonNameOfTeamWithIndex(i));
            button.SetScale(1.8f, 1.8f);
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
            backGround.Draw(window);
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

    string DrawChooseMove(sf::Event &event, int player)
    {
        bool ended = false;
        int i = 0, a = 0;
        float x = 120.0f, y = 80.0f;
        string move;
        list<string> moveset = this->link.GetMoveSet(player);
        buttonsText.clear();
        for (auto &&move : moveset)
        {
            if (i > 1)
            {
                x = 270.0f;
                a = i - 2;
            }
            buttonText.SetButton(manager, move, sf::Vector2f(x, y + a * 70.0f), {150, 50}, move);
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
                    if (button.HandleEvent(event, window, move))
                    {
                        return move;
                    }
                }
            }
            window.clear();
            backGround.Draw(window);
            image1.Draw(window);
            for (auto &&buton : buttonsText)
            {
                buton.Draw(window);
            }
            window.display();
        }
        return "";
    }

    void DrawBattleBegins(sf::Event &event, sf::Clock &fadeClock) // changed
    {
        fadeClock.restart();
        bool ended = false;
        while (window.isOpen() && !ended)
        {
            while (window.pollEvent(event))
            {
            }
            window.clear();
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() < 1.2)
            {
                image6.Draw(window);
                window.draw(text2);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 1.2)
            {
                image4.Draw(window);
                window.draw(text2);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 1.8 && fadeClock.getElapsedTime().asSeconds() < 3)
            {
                image5.Draw(window);
                window.draw(text1);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 3)
            {
                image3.Draw(window);
                window.draw(text1);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 3.5)
                break;
            window.display();
        }
    }

    void DrawEnd(bool &gameStarted, sf::Event &event)
    {
        musicManager.ChangeMusic("./assets/music/victoryBattle.ogg");
        backGround.SetBackGround("ending.jpg", manager, window.getSize());
        if (link.IsGameOver(1) == true)
            SetText(text1, "Player one has no pokemon Left Player two wins", 20U, 400, 500);
        else

            SetText(text1, "Player two  has no pokemon Left Player one wins", 20U, 400, 500);

            SetText(text1, "Player two has no pokemon Left Player one wins", 20U, 400, 500);

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
            backGround.Draw(window);
            window.draw(text1);
            window.draw(text2);
            window.display();
        }
    }

    void DrawChangePokemonAnimationPlayer1(sf::Event &event, sf::Clock &fadeClock, string &pastPokemon) // new
    {
        text14.setString("Player One retires " + pastPokemon + "\n'WellDone " + pastPokemon + "'");
        text15.setString("Go " + link.GetPokemonActual(1));
        fadeClock.restart();
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() < 1.25)
            {
                window.draw(text14);
                image7.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 1.25 && fadeClock.getElapsedTime().asSeconds() < 2.0)
            {
                window.draw(text14);
                image5.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 2.0 && fadeClock.getElapsedTime().asSeconds() < 2.4)
                window.draw(text15);

            if (fadeClock.getElapsedTime().asSeconds() > 2.4 && fadeClock.getElapsedTime().asSeconds() < 3.2)
            {
                window.draw(text15);
                image5.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 3.2 && fadeClock.getElapsedTime().asSeconds() < 4.1)
            {
                window.draw(text15);
                image3.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 3.2)
                break;
            image8.Draw(window);
            window.display();
        }
    }

    void DrawChangePokemonAnimationPlayer2(sf::Event &event, sf::Clock &fadeClock, string &pastPokemon) // new
    {
        bool ended = false;
        fadeClock.restart();
        text14.setString("Player Two retires " + pastPokemon + "\n'WellDone " + pastPokemon + "'");
        text15.setString("Go " + link.GetPokemonActual(2));
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
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() < 1.25)
            {
                window.draw(text14);
                image8.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 1.25 && fadeClock.getElapsedTime().asSeconds() < 2.0)
            {
                window.draw(text14);
                image6.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 2.0 && fadeClock.getElapsedTime().asSeconds() < 2.4)
                window.draw(text15);

            if (fadeClock.getElapsedTime().asSeconds() > 2.4 && fadeClock.getElapsedTime().asSeconds() < 3.2)
            {
                window.draw(text15);
                image6.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 3.2 && fadeClock.getElapsedTime().asSeconds() < 4.1)
            {
                window.draw(text15);
                image4.Draw(window);
            }
            if (fadeClock.getElapsedTime().asSeconds() > 3.2)
                break;
            image3.Draw(window);
            window.display();
        }
    }

    void DrawFaintedPokemonAnimationPlayer1(sf::Event &event, sf::Clock &fadeClock, string &pastPokemon, bool changed)
    {
        bool ended = false;
        bool fadingOut = false;
        float elapsedFade;
        fadeClock.restart();
        float fadeTime = 1.0f;
        if (changed == true)
        {
            image7.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 3.0f, 3.0f, 300.0f, 450.0f);
            text14.setString(link.GetPokemonActual(1) + " fainted");
        }
        else
            text14.setString(pastPokemon + " fainted");
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
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() >= 2.0f && !fadingOut)
            {
                fadingOut = true;
                fadeClock.restart();
            }

            if (fadingOut)
            {
                elapsedFade = fadeClock.getElapsedTime().asSeconds();
                if (elapsedFade < fadeTime)
                {
                    sf::Uint8 alpha = static_cast<sf::Uint8>(255 * (1.0f - elapsedFade / fadeTime));
                    image7.SetColor(sf::Color(255, 255, 255, alpha));
                }
                else
                    break;
            }
            if (image7.GetAlpha() > 0)
                image7.Draw(window);
            image4.Draw(window);
            window.draw(text14);
            window.display();
        }
    }

    void DrawFaintedPokemonAnimationPlayer2(sf::Event &event, sf::Clock &fadeClock, string &pastPokemon, bool changed)
    {
        bool ended = false;
        bool fadingOut = false;
        float elapsedFade;
        fadeClock.restart();
        if (changed == true)
        {
            image8.SetImage(this->link.GetPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 3.0f, 3.0f, 850.0f, 150.0f);
            text14.setString(link.GetPokemonActual(2) + " fainted");
        }
        else
            text14.setString(pastPokemon + " fainted");
        float fadeTime = 1.0f;
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
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() >= 2.0f && !fadingOut)
            {
                fadingOut = true;
                fadeClock.restart();
            }

            if (fadingOut)
            {
                elapsedFade = fadeClock.getElapsedTime().asSeconds();
                if (elapsedFade < fadeTime)
                {
                    sf::Uint8 alpha = static_cast<sf::Uint8>(255 * (1.0f - elapsedFade / fadeTime));
                    image8.SetColor(sf::Color(255, 255, 255, alpha));
                }
                else
                    break;
            }
            if (image8.GetAlpha() > 0)
                image8.Draw(window);
            image3.Draw(window);
            window.draw(text14);
            window.display();
        }
    }

    void DrawMoveMessage(sf::Event &event, sf::Clock &fadeClock, string pokemon, int player)
    {
        string supportString = link.GetMoveName(player);
        text14.setString(pokemon + " uses: " + supportString);
        supportString = isBoostingMoveMessage(supportString);
        if (supportString == "x")
            text15.setString(link.GetMoveEffectivenes(player, link.GetMoveName(player)));
        else
            text15.setString(supportString);
        fadeClock.restart();
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() < 1.5)
                window.draw(text14);
            if (fadeClock.getElapsedTime().asSeconds() > 1.5 && fadeClock.getElapsedTime().asSeconds() < 2.5)
                window.draw(text15);
            if (fadeClock.getElapsedTime().asSeconds() > 2.5)
                break;
            image3.Draw(window);
            image4.Draw(window);
            window.display();
        }
    }

    void SetText(sf::Text &text, string message, int size, float x, float y)
    {
        text.setString(message);
        text.setCharacterSize(size);
        text.setPosition(x, y);
    }

    void DrawChangeFaintedPokemonAnimationPlayer1(sf::Event &event, sf::Clock &fadeClock)
    {
        text15.setString("Go " + link.GetPokemonActual(1));
        fadeClock.restart();
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() < 1.3)
                image5.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() > 1.3 && fadeClock.getElapsedTime().asSeconds() < 2.1)
                image3.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() > 2.1)
                break;
            image4.Draw(window);
            window.draw(text15);
            window.display();
        }
    }

    void DrawChangeFaintedPokemonAnimationPlayer2(sf::Event &event, sf::Clock &fadeClock)
    {
        text15.setString("Go " + link.GetPokemonActual(2));
        fadeClock.restart();
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            backGround.Draw(window);
            image9.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() < 1.3)
                image6.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() > 1.3 && fadeClock.getElapsedTime().asSeconds() < 2.1)
                image4.Draw(window);
            if (fadeClock.getElapsedTime().asSeconds() > 2.1)
                break;
            image3.Draw(window);
            window.draw(text15);
            window.display();
        }
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

    string isBoostingMoveMessage(string nombre)
    {
        if (nombre == "DragonDance")
            return "Speed and Attack boosted!!!";
        else if (nombre == "CalmMind")
            return "Special Attack and Special Defense \nboosted!!!";
        else if (nombre == "NastyPlot")
            return "Special Attack Super Boosted!!!";
        else if (nombre == "Curse")
            return " Attack and Defense Boosted!!!";
        else if (nombre == "Synthesis")
            return "Recovered Some HP!!!";
        else
            return "x";
    }
};
