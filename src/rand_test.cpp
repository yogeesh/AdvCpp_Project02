#include <cstdlib>
#include <iostream>
#include "rng.h"

using std::boolalpha;
using std::cout;
using std::endl;

/**
 * A test program for the random number generator.
 *
 * @return EXIT_SUCCESS on completion
 */
int main() {
    RNG::seed_rand(0);
    for (int i=0; i<1000; ++i) {
        cout << boolalpha << RNG::roll_dice("a", "b", 50) << endl;
    }
    return EXIT_SUCCESS;
}