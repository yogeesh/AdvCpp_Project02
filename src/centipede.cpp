#include "centipede.h"

const std::string Centipede::NAME = "Centipede";

Centipede::Centipede(unsigned int id):
        Actor(NAME, id, Actor::ActorType::MISS_UNIVERSE){};

std::string Centipede::defeat(const Actor &other) const {
    return NAME + " gets called out by " + other.name() + " for vote manipulation and has their reddit account suspended";
}

std::string Centipede::victory(const Actor &other) const {
    return NAME + " successfully brigades subreddit and gets " + other.name() + " to resign as moderator";
}