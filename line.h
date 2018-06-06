#ifndef PROJECT_VECTOR_LINE_H
#define PROJECT_VECTOR_LINE_H

#include <iostream>
#include "vector.h"

class line : public vector
{
public:
    line();
    line(vector, point);
    line(point, point);
    virtual ~line();
    line(const line&);
    line&operator=(const line&);

    vector normalVector(const line&);
    double angle(const line&, const line&);

    bool operator+(const point&); //tochka v/y prava
    bool operator||(const line&); // usporedni pravi

    bool operator&&(const line&); //presichashti pravi


    virtual std::ostream& ins(std::ostream&) const;
    friend std::ostream &operator<<(std::ostream &lhs, const line &obj);

private:
    double x1, x2, y1, y2, z1, z2;
    point a, b;

};


#endif //PROJECT_VECTOR_LINE_H
