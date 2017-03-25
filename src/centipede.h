#ifndef PROJECT1_CENTIPEDE_H
#define PROJECT1_CENTIPEDE_H

#include "actor.h"

class Centipede : public Actor{

public:
    Centipede(unsigned int id);

    ~Centipede();

    virtual std::string victory(const Actor &other) const;

    virtual std::string defeat(const Actor &other) const;

    static const std::string NAME;

private:

};


#endif //PROJECT1_CENTIPEDE_H
