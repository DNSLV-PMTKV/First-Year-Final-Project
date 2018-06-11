#ifndef PROJECT_VECTOR_SEGMENT_H
#define PROJECT_VECTOR_SEGMENT_H

#include <iostream>
#include "line.h"

class segment : public line
{
public:
    segment();
    segment(point, vector);
private:
    point start, end;
};


#endif //PROJECT_VECTOR_SEGMENT_H
