#include "vector.h"
#include <cmath>
#include <iostream>
vector::vector():x(0),y(0),z(0) {}
vector::vector(double a, double b, double c): x(a),y(b),z(c){}
vector::vector(point A, point B)
{
    x = B.getX() - A.getX();
    y = B.getY() - A.getY();
    z = B.getZ() - A.getZ();
}
vector::~vector() {}
vector::vector(const vector & rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}
vector& vector::operator=(const vector &rhs)
{
    if(this!=&rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    return *this;
}
void vector::setX(double a) { x = a; }
void vector::setY(double a) { y = a; }
void vector::setZ(double a) { z = a; }
double vector::getX() const {return x;}
double vector::getY() const {return y;}
double vector::getZ() const {return z;}

vector vector::operator+(const vector & rhs)
{
    vector tmp(x + rhs.x, y + rhs.y, z + rhs.z);
    return tmp;
}
vector vector::operator-(const vector &rhs)
{
    vector tmp(x - rhs.x, y - rhs.y, z - rhs.z);
    return tmp;
}
vector vector::operator*(double rhs)
{
    vector tmp(x*rhs, y*rhs, z*rhs);
    return tmp;
}
double vector::operator*(const vector & rhs)
{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}
vector vector::operator^(const vector & rhs)
{
    vector tmp(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
    return tmp;
}
double vector::length() const
{
    double v = sqrt(x*x + y*y + z*z);
    return fabs(v);
}
bool vector::zeroV() const
{
    if((x && y && z) == 0)
        return true;
    return false;
}
bool vector::parallel(const vector &rhs) const
{
    double tmpX = x - rhs.x;
    double tmpY = y - rhs.y;
    double tmpZ = z - rhs.z;
    if (tmpX == tmpY && tmpY == tmpZ) return true;
    else return false;
}
bool vector::perpendicular(const vector & rhs) const
{
    if(x*rhs.x + y*rhs.y + z*rhs.z == 0) return true;
    return false;
}

std::ostream& vector::ins(std::ostream &out) const
{
    element::ins(out);
    return out << "Vector"<< "\nX: " << x <<"\nY: " << y << "\nZ: " << z << "\n";
}
std::ostream& operator << (std::ostream& lhs, const vector & rhs)
{
    return rhs.ins(lhs);
}
std::istream& vector::ext(std::istream& in)
{
    std::cout<<"Insert x:"; in>>x;
    std::cout<<"Insert y:"; in>>y;
    std::cout<<"Insert z:"; in>>z;
    return in;
}
std::istream& operator>>(std::istream &lhs, vector &rhs)
{
    return rhs.ext(lhs);
}