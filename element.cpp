#include "element.h"
#include <iostream>

std::ostream& element::ins(std::ostream &out) const
{
    return out << "ELEMENT: ";
}