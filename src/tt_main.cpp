#include <cstdlib>
#include <iostream>
#include "trump_tower.h"

/**
 * Program execution entry point
 * @param argc : number of arguments passed to the binary
 * @param argv : argument passed to the binary
 * @return 0 if everything went well
 */
int main (int argc, char *argv[]){
    TrumpTower(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]), std::stoi(argv[5]));
    return 0;
}