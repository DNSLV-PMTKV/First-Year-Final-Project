#ifndef PROJECT_VECTOR_VEXCEPTION_H
#define PROJECT_VECTOR_VEXCEPTION_H

#include <iostream>
#include <exception>

class Vexception : public std::exception
{
public:
    Vexception(double l);
    const char* what();
private:
    char* msg;
};


#endif //PROJECT_VECTOR_VEXCEPTION_H
