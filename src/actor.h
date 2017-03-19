//
// Created by yogeesh on 3/6/17.
//

#ifndef PROJECT1_ACTOR_H
#define PROJECT1_ACTOR_H

#include <string>


/**
 * Abstract Actor class
 */
class Actor{
public:

    /**
     * enum ActorType represents 6 types of actors :
     * CENTIPEDE, MISS_UNIVERSE, POLITICIAN, REPORTER,
     * SOCIAL_JUSTICE_WARRIOR, THE_DONALD
     */
    enum ActorType {
        CENTIPEDE, MISS_UNIVERSE, POLITICIAN, REPORTER,
        SOCIAL_JUSTICE_WARRIOR, THE_DONALD
    };

    /**
     * Creating new actor
     *
     * @param name name of the actor
     * @param id unqiue id of the actor
     * @param type type of the actor
     */
    Actor(const std::string &name, unsigned int id, ActorType type);

    /**
     * Destructor for actor
     */
    virtual ~Actor();

    /**
     * get the name of the actor
     *
     * @return actor's name
     */
    std::string name() const;

    /**
     * get the id of the actor
     *
     * @return id of actor
     */
    unsigned int id() const;

    /**
     * get the type of actor
     *
     * @return actor type
     */
    ActorType type() const;

    /**
     *
     * @param other
     * @return
     */
    virtual std::string victory(const Actor &other) const = 0;

    virtual std::string defeat(const Actor &other) const = 0;

private:
    /** name of the actor*/
    std::string name_;

    /** id of the actor */
    unsigned int id_;

    /** type of the actor */
    ActorType type_;
};

#endif //PROJECT1_ACTOR_H
