#include "floor.h"
#include <string>
#include "actor.h"

template <typename T>
Floor<T>::Floor(unsigned int number):
        number_(number){}

template <typename T>
const T& Floor<T>::back(Direction dir) const throw(TTException){
    if(size(dir) == 0)
        throw TTException("Queue is empty");

    if(dir == WEST)
        return west_.back();
    else
        return east_.back();
}

template <typename T>
const T& Floor<T>::front(Direction dir) const throw(TTException){
    if (size(dir) == 0)
        throw TTException("Queue is empty");

    if(dir == WEST)
        return west_.front();
    else
        return east_.front();
}

template <typename T>
void Floor<T>::insert(const T &element, Direction dir){
    if( dir == WEST)
        west_.push_back(element);
    else
        east_.push_back(element);
}

template <typename T>
void Floor<T>::remove(Direction dir) throw(TTException){
    if (size(dir) == 0)
        throw TTException("Queue is empty");

    if( dir == WEST)
        west_.pop_front();
    else
        east_.pop_front();
}

template <typename T>
unsigned long Floor<T>::size(Direction dir) const{
    if(dir == WEST)
        return west_.size();
    else
        return east_.size();
}

template <typename T>
unsigned int Floor<T>::number() const{
    return number_;
}


template class Floor<int>;
template class Floor<std::string>;
template class Floor<Actor*>;
