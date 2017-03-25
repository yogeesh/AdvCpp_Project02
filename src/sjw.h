
#ifndef PROJECT1_SJW_H
#define PROJECT1_SJW_H

#include "hero.h"

/**
 * All SJW's are basically Hero's
 */
class SJW : public Hero{

public:
    /**
     * create new SJW Hero
     * @param id : SJW id
     */
    SJW(unsigned int id);

    /**
     * Destructor for SJW
     */
    ~SJW();

    /**
     * message for SJW hero victory over other actor
     * @param other : opponent actor
     * @return : message for victory
     */
    virtual std::string victory(const Actor &other) const;

    /**
     * message for SJW hero defeat over other actor
     * @param other : opponent actor
     * @return : message for defeat
     */
    virtual std::string defeat(const Actor &other) const;

    // base name for all SJW hero
    static const std::string NAME;

private:

};


#endif //PROJECT1_SJW_H
