#include "actor.h"
#include <sstream>

Actor::Actor(const std::string &name, unsigned int id, ActorType type):
            name_(name),
            id_(id),
            type_(type){}

std::string Actor::name() const{
    return name_;
}

unsigned int Actor::id() const{
    return id_;
}

Actor::ActorType Actor::type() const{
    return type_;
}

//virtual std::string Actor::victory(const Actor &other) const {}
//virtual std::string Actor::defeat(const Actor &other) const {}
