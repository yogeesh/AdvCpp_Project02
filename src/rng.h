#ifndef RNG_H
#define RNG_H

#include <string>

/**
 * A pseudo random number generator that uses a simple linear congruential
 * generator:
 *
 * https://rosettacode.org/wiki/Linear_congruential_generator
 *
 * @author Sean Strout @ RIT CS
 */
class RNG {
public:
    /**
     * Seed the random number generator so roll_dice has predictable output.
     *
     * @param seed seed value
     */
    static void seed_rand(int seed);

    /**
     * a rolls the dice against b, with a's chance to defeat b as
     * 0..winning_chances-1.  It prints out the message where {result} is
     * between 0..99 inclusively.
     *
     * {a} rolls a {result} against {b}
     *
     * @param a the dice roller
     * @param b who the dice roller is rolling against
     * @param winning_chances a value between 0 and 100, inclusively, as a's
     * chance to beat b
     * @return whether a beat b or not
     */
    static bool roll_dice(const std::string& a, const std::string& b, int winning_chances);

private:

    /**
     * Generates the next random number, 0..max_int-1, inclusively
     *
     * @return the next random number
     */
    static int rand();

    /** stores the previous rand() call in order to generate next random number */
    static int state_;
}; // RNG

#endif // RNG_H
