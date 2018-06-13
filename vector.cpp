#include "vector.h"
#include <exception>
#include <cmath>
#include <iostream>

vector::vector():A(point(0,0,0)){}
vector::vector(double x, double y, double z): A(point(x,y,z)){}
vector::vector(point a, point b)
: A(point(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ())) {}
vector::~vector() {}
vector::vector(const vector & rhs)
{
    A.setX(rhs.A.getX());
    A.setY(rhs.A.getY());
    A.setZ(rhs.A.getZ());
}
vector& vector::operator=(const vector &rhs)
{
    if(this!=&rhs)
    {
        point::operator=(rhs);
        A.setX(rhs.A.getX());
        A.setY(rhs.A.getY());
        A.setZ(rhs.A.getZ());
    }
    return *this;
}
void vector::setX(double a) { A.setX(a); }
void vector::setY(double a) { A.setY(a); }
void vector::setZ(double a) { A.setZ(a); }
double vector::getX() const {return A.getX();}
double vector::getY() const {return A.getY();}
double vector::getZ() const {return A.getZ();}
vector vector::operator+(const vector & rhs)
{
    vector tmp(A.getX() + rhs.A.getX(), A.getY() + rhs.A.getY(), A.getZ() + rhs.A.getZ());
    return tmp;
}
vector vector::operator-(const vector &rhs)
{
    vector tmp(A.getX() - rhs.A.getX(), A.getY() - rhs.A.getY(), A.getZ() - rhs.A.getZ());
    return tmp;
}
vector vector::operator*(double num)
{
    vector tmp(A.getX()*num, A.getY()*num, A.getZ()*num);
    return tmp;
}
double vector::operator*(const vector & rhs)
{
    return A.getX()*rhs.A.getX()+A.getY()*rhs.A.getY()+A.getZ()*rhs.A.getZ();
}
vector vector::operator^(const vector & rhs)
{
    double x = A.getY()*rhs.getZ() - A.getZ()*rhs.getY();
    double y = A.getZ()*rhs.getX() - A.getX()*rhs.getZ();
    double z = A.getX()*rhs.getY() - A.getY()*rhs.getX();
    return vector(x,y,z);
}
double  vector::operator()(const vector & lhs, const vector & rhs) const {
    double a = getX()*lhs.getY()*rhs.getZ();
    double b = getY()*lhs.getZ()*rhs.getX();
    double c = getZ()*lhs.getX()*rhs.getY();
    double first = a + b + c;
    double d = getZ()*lhs.getY()*rhs.getX();
    double e = getX()*lhs.getZ()*rhs.getY();
    double f = getY()*lhs.getX()*rhs.getZ();
    double second = d + e + f;
    return fabs(first - second);
}
double vector::length() const
{
    double v = sqrt(A.getX()*A.getX() + A.getY()*A.getY() + A.getZ()*A.getZ());
    return fabs(v);
}
bool vector::zeroV() const
{
    return A.getX() == A.getY() && A.getY() == A.getZ() && A.getZ() == 0;
}
vector vector::projection(const vector &rhs) const
{
    double projection = (getX()*rhs.getX() + getY()*rhs.getY() + getZ()*rhs.getZ());
    double div = (projection/pow(rhs.length(), 2));
    return vector(div*rhs.getX(),div*rhs.getY(),div*rhs.getZ());
}
vector vector::direction() const
{
    try
    {
        if(length() == 0) throw Vexception(length());
    }
    catch (Vexception &e)
    {
        std::cerr << e.what();
    }
    return vector(getX()/length(),getY()/length(),getZ()/length());
}
bool vector::parallel(const vector &rhs) const
{
    try{
        if(length() == 0) throw Vexception(length());
        if(rhs.length() == 0) throw Vexception(rhs.length());
    }
    catch (Vexception &e)
    {
        std::cerr << e.what();
        return 0;
    }
    double tmpX = A.getX() - rhs.A.getX();
    double tmpY = A.getY() - rhs.A.getY();
    double tmpZ = A.getZ() - rhs.A.getZ();
    return (tmpX == tmpY && tmpY == tmpZ);
}
bool vector::perpendicular(const vector & rhs) const
{
    try{
        if(length() == 0) throw Vexception(length());
        if(rhs.length() == 0) throw Vexception(rhs.length());
    }
    catch (Vexception &e)
    {
        std::cerr << e.what();
        return 0;
    }
    return (A.getX()*rhs.A.getX() + A.getY()*rhs.A.getY() + A.getZ()*rhs.A.getZ() == 0);
}
std::ostream& vector::ins(std::ostream &out) const
{
    return out << "Vector"<< " X: " << A.getX() <<" Y: " << A.getY() << " Z: " << A.getZ() << "\n";
}
std::ostream& operator << (std::ostream& lhs, const vector & rhs)
{
    return rhs.ins(lhs);
}
std::istream& vector::ext(std::istream& in)
{
    double x,y,z;
    std::cout<<"Insert x:"; in>>x; A.setX(x);
    std::cout<<"Insert y:"; in>>y; A.setY(y);
    std::cout<<"Insert z:"; in>>z; A.setZ(z);
    return in;

}
std::istream& operator>>(std::istream &lhs, vector &rhs)
{
    return rhs.ext(lhs);
}