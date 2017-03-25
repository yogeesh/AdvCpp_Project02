#ifndef PROJECT1_HERO_H
#define PROJECT1_HERO_H

#include "actor.h"

/**
 * Hero are basically Actors.
 * hero's can be either Social Justice warriors(SJW) or reporters.
 */
class Hero : public Actor{

public:
    /**
     * create new Hero
     * @param name : Hero name
     * @param id : Hero id
     * @param type : Hero type: SJW or Reporter
     */
    Hero(const std::string &name, unsigned int id, Actor::ActorType type);

    /**
     * Destroy the created Hero
     */
    ~Hero();

    /**
     * hero fights enemy
     * @param other : enemy
     * @return true if hero else false
     */
    bool defend(const Actor &other) const;

    // Chance for hero to beat cenipede
    static const int CHANCE_TO_BEAT_CENTIPEDE;

    // Chance for hero to beat politician
    static const int CHANCE_TO_BEAT_POLITICIAN;

    // Chance for hero to beat miss universe
    static const int CHANCE_TO_BEAT_MISS_UNIVERSE;

    // Chance for hero to beat the donald trump
    static const int CHANCE_TO_BEAT_THE_DONALD;


private:

};

#endif //PROJECT1_HERO_H
