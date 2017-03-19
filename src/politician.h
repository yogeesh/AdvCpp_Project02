#ifndef PROJECT1_POLITICIAN_H
#define PROJECT1_POLITICIAN_H

#include "actor.h"

class Politician : public Actor{

public:

    Politician(unsigned int id);

    virtual std::string victory(const Actor &other) const;

    virtual std::string defeat(const Actor &other) const;

    static const std::string NAME = "Politician";

private:
    unsigned int id_;

};

#endif //PROJECT1_POLITICIAN_H
