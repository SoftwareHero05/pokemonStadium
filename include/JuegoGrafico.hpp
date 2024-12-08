#pragma once
#include <Bridge.h>
#include <GRAPHICS/BackGround.h>
#include <GRAPHICS/TextureManager.h>
#include <GRAPHICS/ButtonImage.h>
#include <GRAPHICS/MusicManager.h>
#include <GRAPHICS/ImageLoader.h>
#include <sstream>
class JuegoGrafico
{
private:
    SourceManager manager;
    Bridge link;
    sf::Font font;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Clock fadeClock;
    BackGround backGround;
    sf::Text text1, text2, text3, text4,text5,text6,text7,text8;
    Image image1, image2,image3,image4,image5,image6;
    MusicManager musicManager;
    list<ButtonImage> buttons, buttons2,buttonsPokemon;
    ButtonImage button;
    

public:
    JuegoGrafico() : window(sf::VideoMode(1024, 600), "SFML with Classes")
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
        text1.setFillColor(sf::Color(0, 0, 0, 255));
        text2.setFillColor(sf::Color(0, 0, 0, 255));
        text3.setFillColor(sf::Color(0, 0, 0, 255));
        text4.setFillColor(sf::Color(0, 0, 0, 255));
        text5.setFillColor(sf::Color(0, 0, 0, 255));
        text6.setFillColor(sf::Color(0, 0, 0, 255));
        text7.setFillColor(sf::Color(0, 0, 0, 255));
        text8.setFillColor(sf::Color(0, 0, 0, 255));
    }
    ~JuegoGrafico() {}

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
            this->image1.setImage("RED.png", manager, 1.0f, 1.0f, 0.2f, 70);
            this->image2.setImage("GOLD.png", manager, 1.0f, 1.0f, 315, 200);
            this->bucleTrainersScreen(window, gameStarted, event, clock, fadeClock, fadingOut);
            this->image1.setImage("textbox1.png", manager, .2f, .2f, 20.0f, 300.0f);
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
            image3.setImage(this->link.getPokemonImageDirectionWithString(this->link.GetPokemonActual(1), 1), manager, 2.2f, 1.5f, 70.0f, 210.0f);
            image4.setImage(this->link.getPokemonImageDirectionWithString(this->link.GetPokemonActual(2), 2), manager, 2.0f, 1.3f, 280.0f, 20.0f);
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
        this->textManger(text1, "This Pokemon\nwas already\nchosen", 18U, 32.0f, 170.0f);
        this->textManger(text2, "was added\nto team", 18U, 34.0f, 188.0f);
        this->textManger(text3, "x", 18U, 34.0f, 170.0f);
        this->textManger(text4, "Choose your team\nPlayer: " + convertidor.str(), 20U, 37.0f, 90.0f);
        float x = 200.0f;
        float y = 100.0f;
        int i = 0;
        for (auto &&pokemon : this->link.getAllPokemonsNamesString())
        {
            if(i > 4){
                x = 400.0f;
                a = i - 5;
            }
            
            button.setButton(link.getPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 120.0f), pokemon);
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
                        else pokemonChosen = false;
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
            if(pokemonChosen == true) {
                window.draw(text3);
                window.draw(text2);
                window.draw(text4);
            }
            else window.draw(text1);
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
        float x = 270.0f, y = 0.0f;
        ostringstream convertidor;
        list <string> team = this->link.getTeamString(player);
        convertidor << player;
        buttons.clear();
        textManger(text2, "Player " + convertidor.str(), 24U, 35.0f, 170.0f);
        textManger(text1, "\t\t\t\t\t's\nTeam", 24U, 35.0f, 170.0f);
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 400.0f;
                a = i - 3;
            }
            button.setButton(this->link.getPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 120.0f), this->link.getSpecificPokemonNameWithIntTeam(i));
            button.setScale(1.3f, 1.3f);
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
        string choicePlayer1,choicePlayer2;
        bool player1 = true;
        this->image1.setImage("textbox1.png", manager, .3f, .3f, 50.0f, 10.0f);
        this->image2.setImage("textbox1.png", manager, .3f, .3f, 280.0f, 230.0f);
        button.setButton("attackIcon.png", manager, sf::Vector2f(320.0f, 255.0f), "attack");
        button.setScale(1.0f,1.0f);
        buttons.push_back(button);
        button.setButton("changeIcon.png", manager, sf::Vector2f(400.0f, 255.0f), "change");
        button.setScale(.15f,.15f);
        buttons.push_back(button);
        button.setButton("attackIcon.png", manager, sf::Vector2f(30.0f, 40.0f), "attack");
        button.setScale(.25f,.25f);
        buttons2.push_back(button);
        button.setButton("changeIcon.png", manager, sf::Vector2f(110.0f, 40.0f), "change");
        button.setScale(.15f,.15f);
        buttons2.push_back(button);
        textManger(text1,this->link.GetPokemonActual(1), 1, 320.0f, 240.0f);
        textManger(text2,this->link.GetPokemonActual(2), 1, 320.0f, 240.0f);
        textManger(text3,"What Will you do \nPlayer 1", 20U, 110.0f, 240.0f);
        textManger(text4,"What Will you do \nPlayer 2", 1, 320.0f, 240.0f);
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
                        cout<<choicePlayer1<<endl;
                        player1 = false;
                    }
                }

                for (auto &button : buttons2)
                {
                    if (button.handleEvent(event, window, choicePlayer2))
                    {
                        if(player1 == false) {
                            cout<<choicePlayer2<<endl;
                            this->ExecuteAction(window,event,choicePlayer1,choicePlayer2);
                            player1 = true;
                        }
                    }
                }
         }
         this->renderCombat(window, player1);
     }
    }

     void renderCombat(sf::RenderWindow &window,bool player1)
     {
         window.clear();
        backGround.draw(window);
        if(player1 == true)
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
        image3.draw(window);
        image4.draw(window);
         window.display();
     }

     void ExecuteAction(sf::RenderWindow &window, sf::Event &event, string &choicePlayer1, string &choicePlayer2){
        if(choicePlayer1 == "change") this->BucleChangePokemon(window,event,choicePlayer1,1);
        else cout<<"xd"<<endl;
         if(choicePlayer2 == "change") this->BucleChangePokemon(window,event,choicePlayer2,2);
        else cout<<"xd"<<endl;
     }

     string BucleChangePokemon(sf::RenderWindow &window, sf::Event &event, string &choicePlayer,int player){
        bool ended = false;
        int state = 0;
        int i = 0, a = 0;
        float x = 270.0f, y = 0.0f;
        string pokemon;
        list <string> team = this->link.getTeamString(player);
        buttonsPokemon.clear();
        textManger(text5, "Pokemon Ya en combate" , 24U, 35.0f, 170.0f);
        textManger(text6, "Pokemon Ya debilitado" , 24U, 35.0f, 170.0f);
        for (auto &&pokemon : team)
        {
            if (i > 2)
            {
                x = 400.0f;
                a = i - 3;
            }
            button.setButton(this->link.getPokemonImageDirectionWithString(pokemon, 2), manager, sf::Vector2f(x, y + a * 120.0f), this->link.getSpecificPokemonNameWithIntTeam(i));
            button.setScale(1.3f, 1.3f);
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
                        cout<<pokemon<<endl;
                        if(pokemon == this->link.GetPokemonActual(player)) state = 1; 
                        else return pokemon;
                    }
                }
            }
            window.clear();
            backGround.draw(window);
            if(state == 1)window.draw(text5);
            if(state == 2)window.draw(text6);
            for (auto &&buton : buttonsPokemon)
            {
                buton.draw(window);
            }
            window.display();
        }
        return "";
     }

    void textManger(sf::Text &text, string message, int size, float x, float y)
    {
        text.setString(message);
        text.setCharacterSize(size);
        text.setPosition(x, y);
    }
};
