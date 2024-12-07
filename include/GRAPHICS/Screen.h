#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "ButtonImage.h"
#include "Screen.h"
#include "BackGround.h"
#include <memory>

class Pantalla
{
protected:
    sf::RenderWindow &window;
    TextureManager &manager;

public:
    Pantalla(sf::RenderWindow &w, TextureManager &m) : window(w), manager(m) {}
    virtual ~Pantalla() {}

    virtual void mostrar(sf::RenderWindow &window) = 0;
    virtual int siguientePantalla() = 0; // Retorna el índice de la siguiente pantalla
}
;
