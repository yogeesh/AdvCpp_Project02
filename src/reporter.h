#ifndef PROJECT1_REPORTER_H
#define PROJECT1_REPORTER_H

#include "hero.h"

class Reporter : public Hero{

public:
    Reporter(unsigned int id);

    virtual std::string victory(const Actor &other) const;

    virtual std::string defeat(const Actor &other) const;

    static const std::string NAME;

private:


};


#endif //PROJECT1_REPORTER_H
