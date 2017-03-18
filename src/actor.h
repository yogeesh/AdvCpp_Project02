//
// Created by yogeesh on 3/6/17.
//

#ifndef PROJECT1_ACTOR_H
#define PROJECT1_ACTOR_H

#include <string>

class Actor{
public:

    enum ActorType {
        CENTIPEDE, MISS_UNIVERSE, POLITICIAN, REPORTER,
        SOCIAL_JUSTICE_WARRIOR, THE_DONALD
    };

    Actor(const std::string &name, unsigned int id, ActorType type);

    virtual ~Actor();

    std::string name() const;

    unsigned int id() const;

    ActorType type() const;

    virtual std::string victory(const Actor &other) const = 0;

    virtual std::string defeat(const Actor &other) const = 0;

private:
    std::string name_;
    unsigned int id_;
    ActorType type_;
};

#endif //PROJECT1_ACTOR_H
