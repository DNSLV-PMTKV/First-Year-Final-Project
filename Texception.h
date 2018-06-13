#ifndef PROJECT_VECTOR_TEXCEPTION_H
#define PROJECT_VECTOR_TEXCEPTION_H

#include <iostream>
#include <exception>

class Texception : public std::exception
{
public:
    Texception(double l);
    const char* what();
private:
    char* msg;
};


#endif //PROJECT_VECTOR_TEXCEPTION_H
