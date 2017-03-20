#include <cstdlib>
#include <iostream>
#include <string>
#include "trump_tower.h"
#include "the_donald.h"


const unsigned int TrumpTower::ENENY_FLOOR = 13;
const unsigned TrumpTower::SEED = 0;

TrumpTower::TrumpTower(unsigned long numSJWs, unsigned long numReporters,
                       unsigned long numCentipedes, unsigned long numPoliticians,
                       unsigned long numMissUniverses):
            numSJWs_(numSJWs),
            numCentipedes_(numCentipedes),
            numReporters_(numReporters),
            numPoliticians_(numPoliticians),
            numMissUniverses_(numMissUniverses),
            enemy_(13),
            sjwId_(1),
            reporterId_(1),
            centipededsId_(1),
            politiciansId_(1),
            missUniverseId_(1){

            buildTrumpTower_();
}

TrumpTower::~TrumpTower() {

}

void TrumpTower::buildTrumpTower_() {

    // Build SJW's
    for (int i = 0; i < numSJWs_; i++)
        sjw_.push_back(new SJW(sjwId_++));
    std::cout << "Initialized safe space with " + std::to_string(numSJWs_) + " SJW/s" << std::endl;


    // Build basement
    for (int i = 0; i < numReporters_; i++)
        reporter_.push(new Reporter(reporterId_++));
    std::cout << "Initialized basement with " + std::to_string(numReporters_) + " reporter/s" << std::endl;

    // Build Enemies
    for (int i = 0; i < numCentipedes_; i++) {
        if (centipededsId_ % 2 == 0)
            enemy_.insert(new Centipede(centipededsId_++), Direction::EAST);
        else
            enemy_.insert(new Centipede(centipededsId_++), Direction::WEST);
    }

    for (int i = 0; i < numPoliticians_; i++) {
        if (politiciansId_ % 2 == 0)
            enemy_.insert(new Politician(politiciansId_++), Direction::EAST);
        else
            enemy_.insert(new Politician(politiciansId_++), Direction::WEST);
    }

    for (int i = 0; i < numMissUniverses_; i++) {
        if (politiciansId_ % 2 == 0)
            enemy_.insert(new MissUniverse(missUniverseId_++), Direction::EAST);
        else
            enemy_.insert(new MissUniverse(missUniverseId_++), Direction::WEST);
    }
    std::cout << "Initialized enemies on floor " + std::to_string(enemy_.number())
                 + " with " + std::to_string(enemy_.size(Direction::EAST))
                 + " enemies in the east hall and "
                 + std::to_string(enemy_.size(Direction::EAST))
                 + " enemies in west hall" << std::endl;
}


void TrumpTower::action() {

    TheDonald *donald = new TheDonald(1);
    Reporter* curReporter;
    SJW* curSJW;
    Direction curDir;
    Actor* curEnemy;
    std::map<Direction, std::string> direction = {{Direction::EAST, "east"},
                                                  {Direction::WEST, "west"}};

    curSJW = sjw_.front();
    curReporter = reporter_.top();

    std::cout << curSJW->NAME + " rescues " + curReporter->NAME + " from basement" << std::endl;

    if( curSJW->id() % 2 == 0 )
        curDir = Direction::EAST;
    else
        curDir = Direction::WEST;

    curEnemy = enemy_.front(curDir);

    if( enemy_.size(curDir) == 0 )
        std::cout << "No enemies are left in the " + direction[curDir] + "hallway";
    else {
        if( curSJW->defend(*curEnemy) ) {
            curSJW->victory(*curEnemy);
            wahmbulance_.insert(curEnemy);
            enemy_.remove(curDir);

            std::cout << "{reporter's name} encounters {The Donald's name} on the roof!" << std::endl;
            if( curReporter->defend(*donald)) {
                choppa_.insert(curReporter);
                std::cout << curReporter->name() + " gets to da choppa!" << std::endl;
            }
            else
                wahmbulance_.insert(curReporter);
        }
        else{
            curEnemy->victory(*curSJW);
            wahmbulance_.insert(curSJW);
            wahmbulance_.insert(curReporter);
            sjw_.pop_front();
            reporter_.pop();


        }

    }
}