#ifndef PROJECT1_FLOOR_H
#define PROJECT1_FLOOR_H

#include <deque>
#include "direction.h"
#include "tt_exception.h"

template <typename T>
class Floor{
public:
    Floor(unsigned int number);

    const T& front(Direction dir) const throw(TTException);

    const T& back(Direction dir) const throw(TTException);

    void insert(const T &element, Direction dir);

    void remove(Direction dir) throw(TTException);

    unsigned long size(Direction dir) const;

    unsigned int number() const;

private:
    unsigned int number_;
    std::deque<T> west_;
    std::deque<T> east_;
};

#endif //PROJECT1_FLOOR_H
