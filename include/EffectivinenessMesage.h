#pragma once
#include <MOVES/Move.h>
#include <Definer.h>

float EffectivenessManager(int type1, int type2, int typeAttack)
{
    float multiplier = 1;
    switch (typeAttack)
    {
    case NORMAL:
        multiplier *= T_NORMAL_effectiviness(type1);
        if (type2 != 0)
            multiplier *= T_NORMAL_effectiviness(type2);
        break;
    case FIRE:
        multiplier *= T_FIRE_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_FIRE_effectiveness(type2);
        break;
    case WATER:
        multiplier *= T_WATER_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_WATER_effectiveness(type2);
        break;
    case GRASS:
        multiplier *= T_GRASS_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_GRASS_effectiveness(type2);
        break;
    case ELECTRIC:
        multiplier *= T_ELECTRIC_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_ELECTRIC_effectiveness(type2);
        break;
    case ICE:
        multiplier *= T_ICE_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_ICE_effectiveness(type2);
        break;
    case FIGHTING:
        multiplier *= T_FIGHTING_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_FIGHTING_effectiveness(type2);
        break;
    case POISON:
        multiplier *= T_POISON_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_POISON_effectiveness(type2);
        break;
    case GROUND:
        multiplier *= T_GROUND_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_GROUND_effectiveness(type2);
        break;
    case FLYING:
        multiplier *= T_FLYING_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_FLYING_effectiveness(type2);
        break;
    case PSYCHIC:
        multiplier *= T_PSYCHICH_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_PSYCHICH_effectiveness(type2);
        break;
    case BUG:
        break;
    case ROCK:
        multiplier *= T_ROCK_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_ROCK_effectiveness(type2);
        break;
    case GHOST:
        multiplier *= T_GHOST_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_GHOST_effectiveness(type2);
        break;
    case DRAGON:
        multiplier *= T_DRAGON_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_DRAGON_effectiveness(type2);
        break;
    case DARK:
        multiplier *= T_DARK_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_DARK_effectiveness(type2);
        break;
    case STEEL:
        multiplier *= T_STEEL_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_STEEL_effectiveness(type2);
        break;
    case FAIRY:
        multiplier *= T_FAIRY_effectiveness(type1);
        if (type2 != 0)
            multiplier *= T_FAIRY_effectiveness(type2);
        break;
    }
    /*if(multiplier > 1) cout<<"Es muy Efectivo!!!"<<endl;
    else if(multiplier == 0) cout<<"No hizo efecto alguno..."<<endl;
    else if(multiplier < 1) cout<<"No es muy Efectivo...."<<endl;
    else cout<<"Es Efectivo"<<endl;
    cout<<multiplier<<endl;
    system("pause");
    system("cls");*/
    return multiplier;
}