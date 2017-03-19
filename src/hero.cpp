#include "hero.h"
#include "rng.h"
#include <iostream>

Hero::Hero(const std::string &name, unsigned int id, Actor::ActorType type):
        Actor(name, id, type){}

bool Hero::defend(const Actor &other) const {

}

static const int Hero::CHANCE_TO_BEAT_CENTIPEDE = 90;

static const int Hero::CHANCE_TO_BEAT_POLITICIAN = 70;

static const int Hero::CHANCE_TO_BEAT_MISS_UNIVERSE = 80;

static const int Hero::CHANCE_TO_BEAT_THE_DONALD = 25;

