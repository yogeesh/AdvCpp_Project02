
#ifndef PROJECT1_SJW_H
#define PROJECT1_SJW_H

#include "hero.h"

class SJW : public Hero{

public:
    SJW(unsigned int id);

    virtual std::string victory(const Actor &other) const;

    virtual std::string defeat(const Actor &other) const;

    static const std::string NAME;

private:

};


#endif //PROJECT1_SJW_H
