
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

/**
 * Trump Tower is were all the work happens, hero's fight enemies to rescue reporters,
 * reporters fight donald trump. All winning reporters all taken by chopper and other
 * loosing reporters with heros are sent to wahambulance.
 */
class TrumpTower{
public:
    // Initial seed for randomness
    static const int SEED;
    // Enemies floor location
    static const unsigned int ENENY_FLOOR;

    /**
     * Construct TrumpTower with heros, reporters, enemies and donald trump
     * @param numSJWs : number of SJW heros to be initiated
     * @param numReporters : number of Reporters to be initiated
     * @param numCentipedes : number of enemy centipedes to be initiated
     * @param numPoliticians : number of enemy politicians to be initiated
     * @param numMissUniverses : number of enemy miss universes to be initiated
     */
    TrumpTower(unsigned long numSJWs, unsigned long numReporters,
                unsigned long numCentipedes, unsigned long numPoliticians,
                unsigned long numMissUniverses);

    /**
     * Kill(Delete) everyone inside trump tower.
     * delete all heros, reporters, enemies.
     */
    virtual ~TrumpTower ();

    /**
     * Once all the actors are ready, the movie acton starts
     */
    void action();

private:
    // number of SJW heros
    unsigned long numSJWs_;
    // number of reporters
    unsigned long numReporters_;
    // Number of enemy centipedes
    unsigned long numCentipedes_;
    // number of enemy politicians
    unsigned long numPoliticians_;
    // number of enemey miss universe
    unsigned long numMissUniverses_;

    // id of SJW
    unsigned long sjwId_;
    // id of reporters
    unsigned long reporterId_;
    // id of centipedes
    unsigned long centipededsId_;
    // id of politicians
    unsigned long politiciansId_;
    // id of miss universe
    unsigned long missUniverseId_;

    /**
     * Wahmbulance compator helps seat the actors in alphabetical order
     */
    class WahmbulanceCmp{
    public:
        /**
         * compares the actors alphabetically
         * @param one : first Actor
         * @param two : second Actor
         * @return true in first Actor is alphabetically palced before second actor
         */
        bool operator()(Actor* one, Actor* two);
    };

    // double ended queue for Hero SJW's
    std::deque<Actor*> sjw_;
    // stack for reporters
    std::stack<Actor*> reporter_;
    // set for actors who enter wahmbulance with comparator Wahmbulance
    std::set<Actor*, WahmbulanceCmp> wahmbulance_;
    // queue of actors in choppa
    std::queue<Actor*> choppa_;
    // enemy's structure and order in Floor
    Floor<Actor*>* enemy_;

    /**
     * builds entire trump tower with all heros, enemies, reporters and donald
     */
    void buildTrumpTower_();
    /**
     * After action of the movies, this prints statistics of actors in wahmbulance,
     * enemies in east and west hallway
     * reporters left in the basement
     * SJW's hero still chilling in safe space
     */
    void printStatistics_();

};


#endif //PROJECT1_TRUMP_TOWER_H
