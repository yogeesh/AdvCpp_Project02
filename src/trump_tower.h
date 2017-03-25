
#ifndef PROJECT1_TRUMP_TOWER_H
#define PROJECT1_TRUMP_TOWER_H

#include <queue>
#include <set>
#include <stack>
#include <deque>
#include "actor.h"
#include "centipede.h"
#include "floor.h"
#include "miss_universe.h"
#include "politician.h"
#include "reporter.h"
#include "rng.h"
#include "sjw.h"

class TrumpTower{
public:
    static const int SEED;
    static const unsigned int ENENY_FLOOR;

    TrumpTower(unsigned long numSJWs, unsigned long numReporters,
                unsigned long numCentipedes, unsigned long numPoliticians,
                unsigned long numMissUniverses);

    virtual ~TrumpTower ();

    void action();

private:
    unsigned long numSJWs_;
    unsigned long numReporters_;
    unsigned long numCentipedes_;
    unsigned long numPoliticians_;
    unsigned long numMissUniverses_;

    unsigned long sjwId_;
    unsigned long reporterId_;
    unsigned long centipededsId_;
    unsigned long politiciansId_;
    unsigned long missUniverseId_;

    class WahmbulanceCmp{
    public:
        bool operator()(Actor* one, Actor* two);
    };

    std::deque<Actor*> sjw_;
    std::stack<Actor*> reporter_;
    std::set<Actor*, WahmbulanceCmp> wahmbulance_;
    std::queue<Actor*> choppa_;
    Floor<Actor*>* enemy_;

    void buildTrumpTower_();
    void printStatistics_();

};


#endif //PROJECT1_TRUMP_TOWER_H
