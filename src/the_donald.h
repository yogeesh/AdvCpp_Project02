#ifndef PROJECT1_THE_DONALD_H
#define PROJECT1_THE_DONALD_H

#include "actor.h"

/**
 * Donal is one of the main actor
 */
class TheDonald : public Actor{

public:
    /**
     * create new donald
     * @param id : donald's actor id
     */
    TheDonald(unsigned int id);

    /**
     * Destrctr for donald
     */
    ~TheDonald();

    /**
     * message for Donald victory over other actor
     * @param other : opponent actor
     * @return : message for victory
     */
    virtual std::string victory(const Actor &other) const;

    /**
     * message for Donald defeat over other actor
     * @param other : opponent actor
     * @return : message for defeat
     */
    virtual std::string defeat(const Actor &other) const;

    // base name for all
    static const std::string NAME;

private:


};


#endif //PROJECT1_THE_DONALD_H
