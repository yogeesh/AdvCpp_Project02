#include "centipede.h"

const std::string Centipede::NAME = "Centipede";

Centipede::Centipede(unsigned int id):
        Actor(NAME + "#" + std::to_string(id), id, Actor::ActorType::CENTIPEDE){};

Centipede::~Centipede(){}

std::string Centipede::defeat(const Actor &other) const {
    return name() + " gets called out by " + other.name() + " for vote manipulation and has their reddit account suspended";
}

std::string Centipede::victory(const Actor &other) const {
    return name() + " successfully brigades subreddit and gets " + other.name() + " to resign as moderator";
}