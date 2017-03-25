#ifndef PROJECT1_MISS_UNIVERSE_H
#define PROJECT1_MISS_UNIVERSE_H

#include "actor.h"

class MissUniverse : public Actor{
public:
    MissUniverse(unsigned int id);

    ~MissUniverse();

    virtual std::string victory(const Actor &other) const;

    virtual std::string defeat(const Actor &other) const;

    static const std::string NAME;

private:


};

#endif //PROJECT1_MISS_UNIVERSE_H
