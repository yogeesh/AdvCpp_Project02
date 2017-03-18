
#ifndef PROJECT1_TRUMP_TOWER_H
#define PROJECT1_TRUMP_TOWER_H


class TrumpTower{
public:
    static const int SEED = 0;
    static const unsigned int ENENY_FLOOR = 13;

    TrumpTower (unsigned long numSJWs, unsigned long numReporters,
                unsigned long numCentipedes, unsigned long numPoliticians,
                unsigned long numMissUniverses);

    virtual ~TrumpTower ();

    void action();

private:

};

#endif //PROJECT1_TRUMP_TOWER_H
