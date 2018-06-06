#include <cmath>
#include "line.h"
//line::line():x1(0),x2(0),y1(0),y2(0),z1(0),z2(0) {}
line::line(): a(point()),b(point()){}
//line::line(vector v, point b)
//    : x1(b.getX()), y1(b.getY()), z1(b.getZ())
//{
//    std::cout << "Enter vector params:\n";
//    std::cin >> v;
//    x2 = v.getX();
//    y2 = v.getY();
//    z2 = v.getZ();
//}
line::line(vector v, point A)
{
    a.setX(v.getX());
    a.setY(v.getY());
    a.setZ(v.getZ());
    b.setX(A.getX());
    b.setY(A.getY());
    b.setZ(A.getZ());
}
//line::line(point a, point b)
//    : x1(a.getX()), y1(a.getY()), z1(a.getZ())
//{
//    vector v(a, b);
//    x2 = v.getX();
//    y2 = v.getY();
//    z2 = v.getZ();
//}
line::line(point A, point B)
{
    a.setX(A.getX());
    a.setY(A.getY());
    a.setZ(A.getZ());
    b.setX(B.getX());
    b.setY(B.getY());
    b.setZ(B.getZ());
}
line::~line() {}
line::line(const line & rhs)
{
    a = rhs.a;
    b = rhs.b;
}
line& line::operator=(const line & rhs)
{
    if(this!=&rhs)
    {
        a = rhs.a;
        b = rhs.b;
    }
    return *this;
}
vector line::normalVector(const line &rhs)
{
    double X = b.getX() - a.getX();
    double Y = b.getY() - a.getY();
    double Z = b.getZ() - a.getZ();
    return vector(X,Y,Z);
}
double line::angle(const line & a, const line &b)
{
    double X = b.getX() - a.getX();
    double Y = b.getY() - a.getY();
    double Z = b.getZ() - a.getZ();
    vector v1(a.x2 - a.x1, a.y2 - a.y1, a.z2 - a.z1);
    vector v2(b.x2 - b.x1, b.y2 - b.y1, b.z2 - b.z1);
    double dot = v1 * v2;
    double a_x = a.x1 - a.x2;
    double a_y = a.y1 - a.y2;
    double a_z = a.z1 - a.z2;
    double a_dist = sqrt(a_x*a_x + a_y*a_y + a_z*a_z);
    double b_x = b.x1 - b.x2;
    double b_y = b.y1 - b.y2;
    double b_z = b.z1 - b.z2;
    double b_dist = sqrt(b_x*b_x + b_y*b_y + b_z*b_z);
    double angle = dot/(a_dist*b_dist);
    angle = cos(angle);

    return angle;
}
bool line::operator+(const point &rhs)
{
    double one = (rhs.getX() - x1) / (x2 - x1);
    double two = (rhs.getY() - y1) / (y2 - y1);
    double three = (rhs.getZ() - z1) / (z2 - z1);
    return one == two == three;
}
bool line::operator||(const line&rhs)
{
    double tmp_x1 = rhs.x1 - x1;
    double tmp_x2 = rhs.x2 - x2;
    double tmp_y1 = rhs.y1 - y1;
    double tmp_y2 = rhs.y2 - y2;
    double tmp_z1 = rhs.z1 - z1;
    double tmp_z2 = rhs.z2 - z2;
    return tmp_x1 == tmp_x2 == tmp_y1 == tmp_y2 == tmp_z1 == tmp_z2;
}


std::ostream& line::ins(std::ostream &out) const
{
    std::cout << "First point: \n" << a;
    std::cout << "Second point: \n" << b;
}
std::ostream& operator << (std::ostream& lhs, const line & rhs)
{
    return rhs.ins(lhs);
}