#include "tetrahedron.h"
#include <cmath>

tetrahedron::tetrahedron() : A(point()), B(point()), C(point()), D(point()){}

tetrahedron::tetrahedron(point a, point b, point c, point d) :
    A(a), B(b), C(c), D(d) {}

tetrahedron::~tetrahedron() {}
tetrahedron::tetrahedron(const tetrahedron &rhs)
{
    A = rhs.A;
    B = rhs.B;
    C = rhs.C;
    D = rhs.D;
}
tetrahedron& tetrahedron::operator=(const tetrahedron &rhs)
{
    if (this != &rhs)
    {
        A = rhs.A;
        B = rhs.B;
        C = rhs.C;
        D = rhs.D;
    }
    return *this;
}
bool tetrahedron::regular() const
{
    line AB(A,B);
    line BC(B,C);
    line CD(C,D);
    line CA(C,A);

    return (AB.length()==BC.length() && BC.length()==CD.length() && CD.length() == CA.length());
}
double tetrahedron::surface() const
{
    line AB(A, B);
    if(this->regular())
    {
        double surface_area;
        surface_area = sqrt(3)*pow(AB.length(),2);
        return surface_area;
    }
}
double tetrahedron::volume() const
{
    line AB(A, B);
    if(this->regular())
    {
        double volume;
        volume = (sqrt(2)*pow(AB.length(),3))/12;
        return volume;
    }
}
bool tetrahedron::operator<(const point &p)
{
    tetrahedron t1(p, B, C, D);
    tetrahedron t2(A, p, C, D);
    tetrahedron t3(A, B, p, D);
    tetrahedron t4(A, B, C, p);
    double v = this->volume();
    double v1 = t1.volume();
    double v2 = t2.volume();
    double v3 = t3.volume();
    double v4 = t4.volume();
    double all = v1 + v2 + v3 + v4;
    return v == all;
}
bool tetrahedron::operator>(const point &p)
{
    tetrahedron t1(p, B, C, D);
    tetrahedron t2(A, p, C, D);
    tetrahedron t3(A, B, p, D);
    tetrahedron t4(A, B, C, p);
    double v = this->volume();
    double v1 = t1.volume();
    double v2 = t2.volume();
    double v3 = t3.volume();
    double v4 = t4.volume();
    double all = v1 + v2 + v3 + v4;
    return v == all;
}
bool tetrahedron::operator==(const point & p)
{
    line AB(A, B);
    line BC(B, C);
    line CA(C, A);
    line AD(A, D);
    line BD(B, D);
    line CD(C, D);
    if(AB+p)
    {
        std::cout << "Point lies on AB.\n";
        return true;
    }
    else if(BC+p)
    {
        std::cout << "Point lies on BC.\n";
        return true;
    }
    else if(CA+p)
    {
        std::cout << "Point lies on AC.\n";
        return true;
    }
    else if(AD+p)
    {
        std::cout << "Point lies on AD.\n";
        return true;
    }
    else if(BD+p)
    {
        std::cout << "Point lies on BD.\n";
        return true;
    }
    else if(CD+p)
    {
        std::cout << "Point lies on CD.\n";
        return true;
    }
    else
    {
        std::cout << "Point doesn't lie neither side.\n";
        return false;
    }
}
std::ostream& tetrahedron::ins(std::ostream &out) const
{
    out << A << B << C << D;
    return out;
}
std::ostream& operator << (std::ostream& lhs, const tetrahedron & rhs)
{
    return rhs.ins(lhs);
}