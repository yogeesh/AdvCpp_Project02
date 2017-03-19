#include "reporter.h"

const std::string Reporter::NAME = "Reporter";

Reporter::Reporter(unsigned int id):
        Hero(NAME, id, Actor::ActorType::REPORTER){}

std::string Reporter::defeat(const Actor &other) const {
    return NAME + "headline story is outed by " + other.name() + " as being fake news";
}


std::string Reporter::victory(const Actor &other) const {
    return NAME + " successfully uploads headline story about " + other.name() + "'s infidelity";
}