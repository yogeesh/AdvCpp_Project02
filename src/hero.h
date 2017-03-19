#ifndef PROJECT1_HERO_H
#define PROJECT1_HERO_H

#include "actor.h"

class Hero{

public:
    Hero(const std::string &name, unsigned int id, Actor::ActorType type);

    bool defend(const Actor &other) const;

    static const int CHANCE_TO_BEAT_CENTIPEDE;

    static const int CHANCE_TO_BEAT_POLITICIAN;

    static const int CHANCE_TO_BEAT_MISS_UNIVERSE;

    static const int CHANCE_TO_BEAT_THE_DONALD;


private:
};

#endif //PROJECT1_HERO_H
