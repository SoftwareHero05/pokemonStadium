#pragma once
#include <SFML/Graphics.hpp>
#include <Juego.h>
#include <GRAPHICS/Screen.h>
#include <GRAPHICS/PantallaCarga.h>
#include <vector>
#include <memory>

class JuegoGrafico
{
private:
    Juego juego;
    list<Pokemon> pokemons;
    list<Pokemon> equipoActual;
    list<Move> moveSetActual;
    int DPlayer1, DPlayer2;
    string OP1, OP2, pokemonName;
    int fasterPlayer, slowerPlayer;
    string OPfaster, OpSlower;
    TextureManager manager;
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Clock fadeClock;
    sf::Font font;
    std::vector<std::shared_ptr<Pantalla>> pantallas; // Pantallas del juego
    int pantallaActual; // Índice de la pantalla actual

public:
    JuegoGrafico() : window(sf::VideoMode(512, 384), "SFML with Classes"), pantallaActual(0) 
    {
        if (!font.loadFromFile("path/to/font.ttf")) {
            std::cerr << "Error al cargar la fuente" << std::endl;
        }

        // Inicializamos las pantallas
        pantallas.push_back(std::make_shared<PantallaCarga>(window, manager));
    }

    void iniciar()
    {
        while (window.isOpen()) {
            pantallas[pantallaActual]->mostrar(window);
            pantallaActual = pantallas[pantallaActual]->siguientePantalla(); // Obtener la siguiente pantalla
        }
    }
};