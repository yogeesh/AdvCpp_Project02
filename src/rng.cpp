#include "rng.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int RNG::state_ = 0;

void RNG::seed_rand(int seed) {
    state_ = seed;
}

bool RNG::roll_dice(const string& a, const string& b, int winning_chances) {
    int result = rand() % 100;
    cout << a << " rolls a " << result << " against " << b << endl;
    return result < winning_chances;
}

int RNG::rand() {
    int const a = 1103515245;
    int const c = 12345;
    state_ = a * RNG::state_ + c;
    return (state_ >> 16) & 0x7FFF;
}