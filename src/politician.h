#ifndef PROJECT1_POLITICIAN_H
#define PROJECT1_POLITICIAN_H

#include "actor.h"

/**
 * Politician is basically a Actor
 */
class Politician : public Actor{

public:
    /**
     * Create new politician
     * @param id : politician Actor ID
     */
    Politician(unsigned int id);

    /**
     * Delete a politician
     */
    ~Politician();

    /**
     * message for Reporter victory over other actor
     * @param other : opponent actor
     * @return : message for victory
     */
    virtual std::string victory(const Actor &other) const;

    /**
     * message for Reporter defeat over other actor
     * @param other : opponent actor
     * @return : message for defeat
     */
    virtual std::string defeat(const Actor &other) const;

    // base name for all Reporters
    static const std::string NAME;

private:

};

#endif //PROJECT1_POLITICIAN_H
