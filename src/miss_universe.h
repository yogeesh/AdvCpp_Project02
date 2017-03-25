#ifndef PROJECT1_MISS_UNIVERSE_H
#define PROJECT1_MISS_UNIVERSE_H

#include "actor.h"

/**
 * Miss Universe is one of enemies of hero's but basically
 * miss universe are actors.
 */
class MissUniverse : public Actor{
public:
    /**
     * Create new miss universe
     * @param id : miss universe actor id
     */
    MissUniverse(unsigned int id);

    /**
     * Destructor for miss universe
     */
    ~MissUniverse();

    /**
     * message for miss universe winning over other actor
     * @param other : opponent actor
     * @return victory message
     */
    virtual std::string victory(const Actor &other) const;

    /**
     * message for miss universe defeat over actor actor
     * @param other : opponent actor
     * @return defeat message
     */
    virtual std::string defeat(const Actor &other) const;

    // Base name for miss universe
    static const std::string NAME;

private:


};

#endif //PROJECT1_MISS_UNIVERSE_H
