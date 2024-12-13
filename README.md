# Pokemon Flash

This project is a simple implementation  of the system of combats of Pokemon, using C++ and the library SMFL. This game is about two Pokemon Teams battling each other, each one is made of 6 different pokemons that can be chosen from 10 different options, once the teams are made, the battle begins where two options can be took, attack or change pokemon.
Battle until one of the teams runs out of Pokemons!!!!.

## Structure of the Project

The project is structured as follows:

- **bin**: Contains the binary files generated after compiling the code.
- **docs**: Stores project documentation.
- **include**: Contains the header files (.h and .hpp) for each class in the project.
- **src**: Contains the source files (.cpp) of the project.
- **Makefile**: Makefile to compile and run the project.
- **assets**: Cotains all the images, music, sounds etc, that the project uses.

## Class Diagram

El diagrama de clases del proyecto incluye las siguientes clases:

- **PokemonFlash**: Represents the visual part of the game, draws sprites, animations, sounds, music etc, it's what the player sees and interacts with.
- **Bridge**: Represents what connects the class PokemonFlash with the rest of classes, also helps PokemonFlash with other stuff, like gettins PokemonsDirections.
- **JuegoConsola**: Represents that class when you can play the game but on the console, it's used to test changes made in the other classes.
- **Juego**: Represents the class that contains the logic of the game, like the two PokemonsTeams, hp, execute Moves, execute Changes etc.
- **EquipoPokemon**: Represents the logic that contains the logic of a Pokemon Team, like knowing who is the pokemon who is figthing, who is fainted, who is the enemy, etc.
- **Pokemon**: Represents the logic of a single Pokemon, like his name, his move set, his hp, etc.

- **Pokemon**: Represents the logic of a single Pokemon, like his name, his move set, his hp, etc.

- **Move**: Represents the logic of a single Moven, his potency, his tipe, agains what is effective and what not, etc.



## Members:

    Jesus Antonio Baez Ortega 23310372
    Hector Manuel Castañeda Godoy 23310342
   

## Compiling and Running

To compile the project, run the following command in the terminal:

make runTestPokemonFlash

if it doesn't work, run

make clean
make runmain

You can test other parts of the Project, for that, 
write Make and next run + the name of the .cpp file, 
example: make runTestJugador

# Screenshots
![alt text](PokemonFlash1.jfif)
![alt text](PokemonFlash2.jfif)