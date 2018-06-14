#ifndef PROJECT_VECTOR_TETRAHEDRON_H
#define PROJECT_VECTOR_TETRAHEDRON_H

#include "point.h"
#include "line.h"
#include <iostream>

class tetrahedron
{
public:
    tetrahedron();
    tetrahedron(point, point, point, point);
    ~tetrahedron();
    tetrahedron(const tetrahedron&);
    tetrahedron&operator=(const tetrahedron&);

    bool regular()const;
    double surface()const;
    double volume() const;

    bool operator<(const point&);
    bool operator>(const point&);
    bool operator==(const point&);

    virtual std::ostream& ins(std::ostream&) const;
    friend std::ostream &operator<<(std::ostream &, const tetrahedron &);

private:
    point A, B, C, D;
};


#endif //PROJECT_VECTOR_TETRAHEDRON_H
