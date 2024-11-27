#include <iostream>
#include <gtest/gtest.h>
#include <POKEMONS/Pokemon.h>
#include <POKEMONS/Charizard.h>


TEST(TEST_POKEMON, CrearPokemon){
    // Escribir codigo de prueba
    Pokemon p;
}

TEST(TEST_POKEMON, TestCharizar){
    // Prueba para verificar la creacion de charizard
    Charizard charizad;
    EXPECT_EQ(charizad.GetAtk() , 5);
    EXPECT_EQ(charizad.GetDef() , 7);
    EXPECT_EQ(charizad.getType1(), 2);
    EXPECT_EQ(charizad.getNombre(), "Charizard");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
