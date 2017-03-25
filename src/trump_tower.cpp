#include <cstdlib>
#include <iostream>
#include <string>
#include "trump_tower.h"
#include "the_donald.h"


const int TrumpTower::SEED = 0;
const unsigned int TrumpTower::ENENY_FLOOR = 13;


TrumpTower::TrumpTower(unsigned long numSJWs, unsigned long numReporters,
                       unsigned long numCentipedes, unsigned long numPoliticians,
                       unsigned long numMissUniverses):
            numSJWs_(numSJWs),
            numCentipedes_(numCentipedes),
            numReporters_(numReporters),
            numPoliticians_(numPoliticians),
            numMissUniverses_(numMissUniverses),
            enemy_(new Floor<Actor*>(13)),
            sjwId_(1),
            reporterId_(1),
            centipededsId_(1),
            politiciansId_(1),
            missUniverseId_(1){
            buildTrumpTower_();
            action();
}

TrumpTower::~TrumpTower() {

}

void TrumpTower::printStatistics_() const{
    std::cout << std::to_string(choppa_.size()) << " reporter/s made it to da choppa:" << std::endl;
    for(std::set<Actor*>::iterator iter=choppa_.begin(); iter != choppa_.end(); iter++)
        std::cout << "\t" + (*iter)->name() << std::endl;

    std::cout << std::to_string(wahmbulance_.size()) << " actor/s are healing up in the wahmbulance:" << std::endl;
    for(std::set<Actor*>::iterator iter=wahmbulance_.begin(); iter != wahmbulance_.end(); iter++)
        std::cout << "\t" + (*iter)->name() << std::endl;

    std::cout << std::to_string(enemy_->size(Direction::EAST))
                                                     << " enemy/s remain in the east hallway:" << std::endl;
    while( enemy_->size(Direction::EAST) != 0){
        std::cout << "\t" + enemy_->front(Direction::EAST)->name() << std::endl;
        enemy_->remove(Direction::EAST);
    }

    std::cout << std::to_string(enemy_->size(Direction::WEST))
              << " enemy/s remain in the east hallway:" << std::endl;
    while( enemy_->size(Direction::WEST) != 0){
        std::cout << "\t" + enemy_->front(Direction::WEST)->name() << std::endl;
        enemy_->remove(Direction::WEST);
    }

}

void TrumpTower::buildTrumpTower_() {

    // Build SJW's
    for (unsigned int i = 0; i < numSJWs_; i++)
        sjw_.push_back(new SJW(sjwId_++));
    std::cout << "Initialized safe space with " + std::to_string(numSJWs_) + " SJW/s" << std::endl;


    // Build basement
    for (unsigned int i = 0; i < numReporters_; i++)
        reporter_.push(new Reporter(reporterId_++));
    std::cout << "Initialized basement with " + std::to_string(numReporters_) + " reporter/s" << std::endl;

    // Build Enemies
    for (unsigned int i = 0; i < numCentipedes_; i++) {
        if (centipededsId_ % 2 == 0)
            enemy_->insert(new Centipede(centipededsId_++), Direction::EAST);
        else
            enemy_->insert(new Centipede(centipededsId_++), Direction::WEST);
    }

    for (unsigned int i = 0; i < numPoliticians_; i++) {
        if (politiciansId_ % 2 == 0)
            enemy_->insert(new Politician(politiciansId_++), Direction::EAST);
        else
            enemy_->insert(new Politician(politiciansId_++), Direction::WEST);
    }

    for (unsigned int i = 0; i < numMissUniverses_; i++) {
        if (politiciansId_ % 2 == 0)
            enemy_->insert(new MissUniverse(missUniverseId_++), Direction::EAST);
        else
            enemy_->insert(new MissUniverse(missUniverseId_++), Direction::WEST);
    }
    std::cout << "Initialized enemies on floor " + std::to_string(enemy_->number())
                 + " with " + std::to_string(enemy_->size(Direction::EAST))
                 + " enemies in the east hall and "
                 + std::to_string(enemy_->size(Direction::EAST))
                 + " enemies in west hall" << std::endl;
}


void TrumpTower::action() {

    const Actor* donald = new TheDonald(1);
    Actor* curReporter;
    Actor* curSJW;
    Direction curDir;
    Actor* curEnemy;
    std::map<Direction, std::string> direction = {{Direction::EAST, "east"},
                                                  {Direction::WEST, "west"}};

    curSJW = sjw_.front();
    curReporter = reporter_.top();

    std::cout << curSJW->name() + " rescues " + curReporter->name() + " from basement" << std::endl;

    if( curSJW->id() % 2 == 0 )
        curDir = Direction::EAST;
    else
        curDir = Direction::WEST;

    if( enemy_->size(curDir) > 0 )
        curEnemy = enemy_->front(curDir);
    else
        std::cout << "No enemies are left in the " + direction[curDir] + " hallway" << std::endl;

    if( (enemy_->size(curDir) == 0) || (((Hero*)curSJW)->defend(*curEnemy)) ) {
        if(enemy_->size(curDir) > 0){
            std::cout << ((Hero*)curSJW)->victory(*curEnemy) << std::endl;
            wahmbulance_.insert(curEnemy);
            enemy_->remove(curDir);
        }

        std::cout << curReporter->name() + " encounters " + donald->name() + " on the roof!" << std::endl;
        if( ((Hero*)curReporter)->defend(*donald)) {
            std::cout << curReporter->victory(*donald) << std::endl;
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

    printStatistics_();

}