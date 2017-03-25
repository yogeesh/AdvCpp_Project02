//
// Created by yogeesh on 3/6/17.
//

#ifndef PROJECT1_TT_EXCEPTION_H
#define PROJECT1_TT_EXCEPTION_H

#include <stdexcept>

/**
 * Exception class from run time error
 */
class TTException : public std::runtime_error{
public:
    /**
     * create a execption class with the message
     * @param msg : exception message
     */
    TTException(const char* msg) : runtime_error(msg){}

    /**
     * Exception message throwable
     * @return : exception message
     */
    virtual const char* what() const throw(){
        return std::runtime_error::what();
    }
};

#endif //PROJECT1_TT_EXCEPTION_H
