#include "Vexception.h"
#include <iostream>

Vexception::Vexception(double l)
{
    if (l == 0) msg = "ERROR! The magnitude is 0.\n";
}
const char* Vexception::what()
{
    return msg;
}