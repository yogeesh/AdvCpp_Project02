#include "sjw.h"

const std::string SJW::NAME = "SJW";

SJW::SJW(unsigned int id):
        Hero(NAME, id, Actor::ActorType::SOCIAL_JUSTICE_WARRIOR){}

std::string SJW::defeat(const Actor &other) const {
    return NAME + " deletes all social media accounts after being humiliated by " + other.name();
}

std::string SJW::victory(const Actor &other) const {
    return NAME + " rips " + other.name() +" a new one on social media";
}
