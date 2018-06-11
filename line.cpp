#include <cmath>
#include "line.h"
line::line(): a(point()),b(point()){}
line::line(vector v, point A) : b(A)
{
    a.setX(v.getX());
    a.setY(v.getY());
    a.setZ(v.getZ());
}
line::line(point A, point B) : a(A), b(B) {}
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
vector line::normalVector()
{
    vector v(a,b);
    double length = v.length();
    if (length != 0)
    {
        v.setX(v.getX()/length);
        v.setY(v.getY()/length);
        v.setZ(v.getZ()/length);
    }
    return v;
}
double line::angle(const line & rhs)
{
    vector v1(a, b);
    vector v2(rhs.a, rhs.b);
    double dot = v1 * v2;
    double a_x = v1.getX() * v1.getX();
    double a_y = v1.getY() * v1.getY();
    double a_z = v1.getZ() * v1.getZ();
    double a_dist = sqrt(a_x+ a_y + a_z);
    double b_x = v2.getX() * v2.getX();
    double b_y = v2.getY() * v2.getY();
    double b_z = v2.getZ() * v2.getZ();
    double b_dist = sqrt(b_x + b_y + b_z);
    double angle = dot/(a_dist*b_dist);
    angle = acos(angle);
    return angle;
}
bool line::operator+(const point &rhs)
{
    double one = (rhs.getX() - a.getX()) / (b.getX() - a.getX());
    double two = (rhs.getY() - a.getY()) / (b.getY() - a.getY());
    double three = (rhs.getZ() - a.getZ()) / (b.getZ() - a.getZ());
    //std::cout << one << std::endl << two << std::endl << three;
    return (one == two && two == three);
}
bool line::operator||(const line&rhs)
{
    double tmp_x1 = rhs.a.getX() - a.getX();
    double tmp_x2 = rhs.b.getX() - b.getX();
    double tmp_y1 = rhs.a.getY() - a.getY();
    double tmp_y2 = rhs.b.getY() - b.getZ();
    double tmp_z1 = rhs.a.getZ() - a.getZ();
    double tmp_z2 = rhs.b.getZ() - b.getZ();
    return (tmp_x1 == tmp_x2 && tmp_y1 == tmp_y2 && tmp_z1 == tmp_z2 && tmp_x1 == tmp_y1 && tmp_y1 == tmp_z1);

}
bool line::operator==(const line &rhs)
{
    return *this+rhs.a && *this+rhs.b;
}

bool line::operator&&(const line &rhs)
{

}
bool line::operator|(const line &rhs)
{
    vector v(a,b);
    vector u(rhs.a, rhs.b);
    return v.perpendicular(u);
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