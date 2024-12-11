#pragma once
#include "Definer.h"

float T_FIRE_effectiveness(int defender)
{
	if (defender == GRASS || defender == ICE || defender == BUG || defender == STEEL)
		return 2;
	else if (defender == FIRE || defender == WATER || defender == ROCK || defender == DRAGON)
		return .5;
	else
		return 1;
}

float T_FIGHTING_effectiveness(int defender)
{
	if (defender == NORMAL || defender == ICE || defender == ROCK || defender == DARK || defender == STEEL)
		return 2;
	else if (defender == POISON || defender == FLYING || defender == PSYCHIC || defender == BUG || defender == FAIRY)
		return .5;
	else
		return 1;
}

float T_FLYING_effectiveness(int defender)
{
	if (defender == GRASS || defender == BUG || defender == FIGHTING)
		return 2;
	else if (defender == ELECTRIC || defender == ROCK || defender == STEEL)
		return .5;
	else
		return 1;
}

float T_STEEL_effectiveness(int defender)
{
	if (defender == ICE || defender == ROCK || defender == FAIRY)
		return 2;
	else if (defender == FIRE || defender == WATER || defender == ELECTRIC || defender == STEEL)
		return .5;
	else
		return 1;
}

float T_DRAGON_effectiveness(int defender)
{
	if (defender == DRAGON)
		return 2;
	else if (defender == STEEL)
		return .5;
	else if (defender == FAIRY)
		return 0;
	else
		return 1;
}

float T_GROUND_effectiveness(int defender)
{
	if (defender == FIRE || defender == ELECTRIC || defender == POISON || defender == ROCK || defender == STEEL)
		return 2;
	else if (defender == GRASS || defender == BUG)
		return .5;
	else if (defender == FLYING)
		return 0;
	else
		return 1;
}

float T_DARK_effectiveness(int defender)
{
	if (defender == PSYCHIC || defender == GHOST)
		return 2;
	else if (defender == FIGHTING || defender == DARK || defender == FAIRY)
		return .5;
	else
		return 1;
}

float T_FAIRY_effectiveness(int defender)
{
	if (defender == DRAGON || defender == DARK || defender == FIGHTING)
		return 2;
	else if (defender == FIRE || defender == POISON || defender == STEEL)
		return .5;
	else
		return 1;
}

float T_PSYCHICH_effectiveness(int defender)
{
	if (defender == FIGHTING || defender == POISON)
		return 2;
	else if (defender == PSYCHIC || defender == STEEL)
		return .5;
	else if (defender == DARK)
		return 0;
	else
		return 1;
}
float T_GHOST_effectiveness(int defender)
{
	if (defender == PSYCHIC || defender == GHOST)
		return 2;
	else if (defender == DARK)
		return .5;
	else if (defender == NORMAL)
		return 0;
	else
		return 1;
}

float T_ICE_effectiveness(int defender)
{
	if (defender == GRASS || defender == GROUND || defender == FLYING || defender == DRAGON)
		return 2;
	else if (defender == FIRE || defender == WATER || defender == ICE || defender == STEEL)
		return .5;
	else
		return 1;
}

float T_WATER_effectiveness(int defender)
{
	if (defender == FIRE || defender == GROUND || defender == ROCK)
		return 2;
	else if (defender == WATER || defender == GRASS || defender == DRAGON)
		return .5;
	else
		return 1;
}

float T_GRASS_effectiveness(int defender)
{
	if (defender == WATER || defender == GROUND || defender == ROCK)
		return 2;
	else if (defender == FIRE || defender == GRASS || defender == POISON || defender == FLYING || defender == BUG || defender == DRAGON || defender == STEEL)
		return .5;
	else
		return 1;
}

float T_POISON_effectiveness(int defender)
{
	if (defender == GRASS || defender == FAIRY)
		return 2;
	else if (defender == POISON || defender == GROUND || defender == ROCK || defender == GHOST)
		return .5;
	else if (defender == STEEL)
		return 0;
	else
		return 1;
}

float T_ROCK_effectiveness(int defender)
{
	if (defender == FIRE || defender == FLYING || defender == ICE || defender == BUG)
		return 2;
	else if (defender == FIGHTING || defender == GROUND || defender == STEEL)
		return .5;
	else
		return 1;
}

float T_ELECTRIC_effectiveness(int defender)
{
	if (defender == WATER || defender == FLYING)
		return 2;
	else if (defender == GRASS || defender == ELECTRIC)
		return .5;
	else if (defender == GROUND)
		return 0;
	else
		return 1;
}

float T_NORMAL_effectiviness(int defender)
{

	if (defender == ROCK || defender == STEEL)
		return .5;
	else if (defender == GHOST)
		return 0;
	else
		return 1;
}
