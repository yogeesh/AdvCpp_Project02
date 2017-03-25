#include "hero.h"
#include "rng.h"
#include <iostream>

Hero::Hero(const std::string &name, unsigned int id, Actor::ActorType type):
        Actor(name, id, type) {}

Hero::~Hero(){}

bool Hero::defend(const Actor &other) const {
    int chanceToBeat;
    if(other.type() == Actor::THE_DONALD)
        chanceToBeat = CHANCE_TO_BEAT_THE_DONALD;
    else if(other.type() == Actor::POLITICIAN)
        chanceToBeat = CHANCE_TO_BEAT_POLITICIAN;
    else if(other.type() == Actor::MISS_UNIVERSE)
        chanceToBeat = CHANCE_TO_BEAT_MISS_UNIVERSE;
    else
        chanceToBeat = CHANCE_TO_BEAT_CENTIPEDE;

    return RNG::roll_dice(name(), other.name(), chanceToBeat);
}

const int Hero::CHANCE_TO_BEAT_CENTIPEDE = 90;

const int Hero::CHANCE_TO_BEAT_POLITICIAN = 80;

const int Hero::CHANCE_TO_BEAT_MISS_UNIVERSE = 70;

const int Hero::CHANCE_TO_BEAT_THE_DONALD = 25;

