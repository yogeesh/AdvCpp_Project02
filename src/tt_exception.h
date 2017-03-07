//
// Created by yogeesh on 3/6/17.
//

#ifndef PROJECT1_TT_EXCEPTION_H
#define PROJECT1_TT_EXCEPTION_H

#include <stdexcept>


class TTException : public std::runtime_error{
public:
    TTException(const char* msg) : runtime_error(msg){}
    virtual const char* what() const throw(){
        return std::runtime_error::what();
    }
};

#endif //PROJECT1_TT_EXCEPTION_H
