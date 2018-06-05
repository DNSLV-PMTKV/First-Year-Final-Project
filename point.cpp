#include "point.h"
#include <iostream>

point::point() : x(0),y(0),z(0) {}
point::point(double a, double b, double c):x(a),y(b),z(c) {}
point::point(const point &rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}
point::~point() {}
point& point::operator=(const point &rhs)
{
    if(this!=&rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    return *this;
}
void point::setX(double a) { x = a; }
void point::setY(double a) { y = a; }
void point::setZ(double a) { z = a; }
double point::getX() const {return x;}
double point::getY() const {return y;}
double point::getZ() const {return z;}

bool point::operator==(const point &rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}
std::ostream& point::ins(std::ostream &out) const
{
    element::ins(out);
    return out << "Point" << "\nX: " << x <<"\nY: " << y << "\nZ: " << z << "\n";
}
std::ostream& operator << (std::ostream& lhs, const point & rhs)
{
    return rhs.ins(lhs);
}
std::istream& point::ext(std::istream& in)
{
    std::cout<<"Insert x:"; in>>x;
    std::cout<<"Insert y:"; in>>y;
    std::cout<<"Insert z:"; in>>z;
    return in;
}
std::istream& operator>>(std::istream &lhs, point &rhs)
{
    return rhs.ext(lhs);
}
