#include <GRAPHICS/Image.h>
#include <GRAPHICS/BackGround.h> // Asegúrate de incluir SFML
#include <GRAPHICS/SourceManager.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    Image image;
    BackGround backGround;
    SourceManager manager;
    sf::RenderWindow window(sf::VideoMode(512, 384), "SFML with Classes");

    try
    {
        backGround.SetBackGround("./assets/images/Bosque tarde - Zeo.png", manager, window.getSize());
        image.SetImage("./assets/images/003.png", manager, 1.0f, 1.0f, 0.2f, 70);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            { // Procesa los eventos
                if (event.type == sf::Event::Closed)
                {
                    window.close(); // Cierra la ventana
                }
            }

            window.clear();          // Limpia la ventana
            backGround.Draw(window); // Dibuja el fondo
            image.Draw(window);      // Dibuja la imagen
            window.display();        // Muestra el contenido en pantalla
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
