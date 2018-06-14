#ifndef PROJECT_VECTOR_TRIANGLE_H
#define PROJECT_VECTOR_TRIANGLE_H

#include "point.h"
#include "line.h"
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

    bool operator<(const point&);
    bool operator>(const point&);
    bool operator==(const point&);

    virtual std::ostream& ins(std::ostream&) const;
    friend std::ostream &operator<<(std::ostream &, const triangle &);
private:
    point A, B, C;
};


#endif //PROJECT_VECTOR_TRIANGLE_H
