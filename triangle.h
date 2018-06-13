//
// Created by dpometkov on 13/6/18.
//

#ifndef PROJECT_VECTOR_TRIANGLE_H
#define PROJECT_VECTOR_TRIANGLE_H

#include "point.h"
#include <iostream>

class triangle : public point
{
public:
    triangle();
    triangle(point, point, point);
    triangle(const triangle&);
    virtual ~triangle();
    triangle&operator=(const triangle&);

    int type() const;
    double surface() const;
    double perimeter() const;
    point centroid() const;


private:
    point A, B, C;
};


#endif //PROJECT_VECTOR_TRIANGLE_H
