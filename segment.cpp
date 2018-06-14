#include "segment.h"
#include <cmath>
segment::segment() : t1(point()), t2(point())
{
    for (int i = 0; i < 2; ++i) t[i] = 0;
}
segment::segment(point p, vector v, int arr[2])
{
    t1.setX(p.getX() + v.getX()*arr[0]);
    t1.setY(p.getY() + v.getY()*arr[0]);
    t1.setZ(p.getZ() + v.getZ()*arr[0]);
    t2.setX(p.getX() + v.getX()*arr[1]);
    t2.setY(p.getY() + v.getY()*arr[1]);
    t2.setZ(p.getZ() + v.getZ()*arr[1]);
}
segment::segment(const segment &rhs)
{
    t1 = rhs.t1;
    t2 = rhs.t2;
}
segment::~segment() {}
segment& segment::operator=(const segment &rhs)
{
    if(this!=&rhs)
    {
        t1 = rhs.t1;
        t2 = rhs.t2;
    }
    return *this;
}
double segment::length()
{
    double x = t2.getX()-t1.getX();
    double y = t2.getY()-t1.getY();
    double z = t2.getZ()-t1.getZ();
    double dist = sqrt(x*x + y*y + z*z);
    return fabs(dist);
}
point segment::mid() const
{
    double x = (t1.getX()+t2.getX())/2;
    double y = (t1.getY()+t2.getY())/2;
    double z = (t1.getZ()+t2.getZ())/2;
    return point(x,y,z);
}
bool segment::operator==(const point&rhs)
{
    double one = (rhs.getX() - t1.getX()) / (t2.getX() - t1.getX());
    double two = (rhs.getY() - t1.getY()) / (t2.getY() - t1.getY());
    double three = (rhs.getZ() - t1.getZ()) / (t2.getZ() - t1.getZ());
    return (one == two && two == three);
}
std::ostream& segment::ins(std::ostream &out) const
{
    std::cout << "First point: \n" << t1;
    std::cout << "Second point: \n" << t1;
}
std::ostream& operator << (std::ostream& lhs, const segment & rhs)
{
    return rhs.ins(lhs);
}