#include "the_donald.h"

const std::string TheDonald::NAME = "The Donald";

TheDonald::TheDonald(unsigned int id = 1):
        Actor(NAME + "#" + std::to_string(id), id, Actor::ActorType::THE_DONALD){}

TheDonald::~TheDonald() {}

std::string TheDonald::victory(const Actor &other) const{
    return name() + " makes America great again and fires " + other.name();
}

std::string TheDonald::defeat(const Actor &other) const{
    return name() + " can't handle the high energy coming from " + other.name();
}