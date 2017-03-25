#ifndef PROJECT1_THE_DONALD_H
#define PROJECT1_THE_DONALD_H

#include "actor.h"

class TheDonald : public Actor{

public:
    TheDonald(unsigned int id);

    ~TheDonald();

    virtual std::string victory(const Actor &other) const;

    virtual std::string defeat(const Actor &other) const;

    static const std::string NAME;

private:


};


#endif //PROJECT1_THE_DONALD_H
