#include "miss_universe.h"

MissUniverse::MissUniverse(unsigned int id):
        Actor(NAME + "#"+ std::to_string(id), id, Actor::ActorType::MISS_UNIVERSE){}

MissUniverse::~MissUniverse(){}

std::string MissUniverse::defeat(const Actor &other) const {
    return name() + "'s mascara begins to run as she bawls in defeat to " + other.name();
}

std::string MissUniverse::victory(const Actor &other) const {
    return name() + " tips her tiara in glorious victory over " + other.name();
}

const std::string MissUniverse::NAME = "MissUniverse";