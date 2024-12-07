#pragma once
#include "Screen.h"

class PantallaCarga : public Screen
{
private:
    Fondo fondo;
    Texto texto;
    Boton botonInicio;

public:
    PantallaCarga(sf::RenderWindow &w, TextureManager &m) : Pantalla(w, m) {
        fondo.setBackGround("./assets/images/FondoPokemon.png", window.getSize());
        texto.setText("Press any key to start", 18U, 50.0f, 150.0f);
        botonInicio.setButton("./assets/images/startButton.png", manager, sf::Vector2f(200.0f, 250.0f), "Start");
    }

    void mostrar(sf::RenderWindow &window) override
    {
        sf::Event event;
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    return; // Avanzamos a la siguiente pantalla
                }
            }

            window.clear();
            fondo.draw(window);
            texto.draw(window);
            botonInicio.draw(window);
            window.display();
        }
    }

    int siguientePantalla() override {
        return 1; // Cambio a la pantalla de entrenadores
    }
};
