#ifndef PROJECT_VECTOR_VECTOR_H
#define PROJECT_VECTOR_VECTOR_H

#include <iostream>
#include "point.h"

class vector: public point {
public:
    vector();
    vector(double, double, double);
    vector(point, point);
    virtual ~vector();
    vector(const vector&);
    vector&operator=(const vector&);

    void setX(double);
    void setY(double);
    void setZ(double);

    double getX() const;
    double getY() const;
    double getZ() const;

    vector operator+(const vector&);
    vector operator-(const vector&);
    vector operator*(double);
    double operator*(const vector&); //skalarno pr.
    vector operator^(const vector&); //vektorno pr.

    double length() const;
    bool zeroV() const;
    bool parallel(const vector &) const;
    bool perpendicular(const vector&) const;

    virtual std::ostream& ins(std::ostream&) const;
    friend std::ostream &operator<<(std::ostream &, const vector &);

    virtual std::istream&ext(std::istream&);
    friend std::istream& operator>>(std::istream&,vector&);

private:
    point A;
    //double x,y,z;

};


#endif //PROJECT_VECTOR_VECTOR_H
