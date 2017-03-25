#include "politician.h"

Politician::Politician(unsigned int id):
            Actor(NAME +"#"+std::to_string(id), id, Actor::POLITICIAN){}

Politician::~Politician(){}

std::string Politician::victory(const Actor &other) const{
    return name() + " buries the truth and successfully silences " + other.name();
}

std::string Politician::defeat(const Actor &other) const {
    return name() + "'s racketeering is exposed by " + other.name() + " and flees to Russia";
}

const std::string Politician::NAME = "Politician";