#ifndef PROJECT1_REPORTER_H
#define PROJECT1_REPORTER_H

#include "hero.h"

/**
 * All Reporters are basically Hero's
 */
class Reporter : public Hero{

public:
    /**
     * create new reporter
     * @param id : reporter actor id
     */
    Reporter(unsigned int id);

    /**
     * Destructor for Reporter
     */
    ~Reporter();

    /**
     * message for reporter victory over other actor
     * @param other : opponent actor
     * @return : message for victory
     */
    virtual std::string victory(const Actor &other) const;

    /**
     * message for reporter defeat over other actor
     * @param other : opponent actor
     * @return : message for defeat
     */
    virtual std::string defeat(const Actor &other) const;

    // base name for all reporters
    static const std::string NAME;

private:


};


#endif //PROJECT1_REPORTER_H
