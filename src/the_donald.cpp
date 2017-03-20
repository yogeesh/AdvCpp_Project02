#include "the_donald.h"

const std::string TheDonald::NAME = "The Donald";

TheDonald::TheDonald(unsigned int id = 1):
        Actor(NAME, id, Actor::ActorType::THE_DONALD){}

std::string TheDonald::victory(const Actor &other) const{
    return NAME + " makes America great again and fires " + other.name();
}

std::string TheDonald::defeat(const Actor &other) const{
    return NAME + " can't handle the high energy coming from " + other.name();
}