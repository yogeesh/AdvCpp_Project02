#include "politician.h"

Politician::Politician(unsigned int id):
            Actor(NAME, id, Actor::POLITICIAN){}

std::string Politician::victory(const Actor &other) const{
    return NAME + " buries the truth and successfully silences " + other.name();
}

std::string Politician::defeat(const Actor &other) const {
    return NAME + "'s racketeering is exposed by " + other.name() + " and flees to Russia";
}

const std::string Politician::NAME = "Politician";