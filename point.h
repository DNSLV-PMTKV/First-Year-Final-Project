#ifndef PROJECT_VECTOR_POINT_H
#define PROJECT_VECTOR_POINT_H

#include <iostream>
#include "element.h"

class point: public element {
public:
    point();
    point(double, double, double);
    point(const point&);
    virtual ~point();
    point&operator=(const point&);

    void setX(double);
    void setY(double);
    void setZ(double);

    double getX() const;
    double getY() const;
    double getZ() const;

    bool operator==(const point&);

    virtual std::ostream& ins(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream &, const point &);

    virtual std::istream&ext(std::istream&);
    friend std::istream& operator>>(std::istream&,point&);
private:
    double x, y, z;
};


#endif //PROJECT_VECTOR_POINT_H
