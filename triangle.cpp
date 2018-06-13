#include "triangle.h"
#include <cmath>

triangle::triangle() : A(point()), B(point()), C(point()) {}
triangle::triangle(point a, point b, point c) : A(a), B(b), C(c) {}
triangle::triangle(const triangle & rhs)
{
    A = rhs.A;
    B = rhs.B;
    C = rhs.C;
}
triangle::~triangle() {}
triangle& triangle::operator=(const triangle &rhs)
{
    if (this != &rhs)
    {
        A = rhs.A;
        B = rhs.B;
        C = rhs.C;
    }
    return *this;
}
int triangle::type() const
{
    double AB = fabs(sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2) + pow(A.getZ() - B.getZ(), 2)));
    double BC = fabs(sqrt(pow(B.getX() - C.getX(), 2) + pow(B.getY() - C.getY(), 2) + pow(B.getZ() - C.getZ(), 2)));
    double CA = fabs(sqrt(pow(C.getX() - A.getX(), 2) + pow(C.getY() - A.getY(), 2) + pow(C.getZ() - A.getZ(), 2)));

    double low = std::min(AB, std::min(BC, CA));
    double mid = std::max(std::min(AB, BC), std::min(BC, CA));
    double high = std::max(AB, std::max(BC, CA));

    if(AB == BC && BC == CA) std::cout << "Equilateral triange and \n";
    else if(AB == BC || BC == CA || CA == AB) std::cout << "Isosceles triangle and \n";
    else std::cout << "Scalane triangle and \n.";

    if(pow(low,2) + pow(mid,2) == pow(high, 2))
    {
        std::cout << "right angled.\n";
    }
    else if(pow(low,2) + pow(mid,2) > pow(high, 2))
    {
        std::cout << "obtuse.\n";
    }
    else  std::cout << "acute(sharp).\n";
    return 0;
}
double triangle::surface() const
{
    double AB = fabs(sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2) + pow(A.getZ() - B.getZ(), 2)));
    double BC = fabs(sqrt(pow(B.getX() - C.getX(), 2) + pow(B.getY() - C.getY(), 2) + pow(B.getZ() - C.getZ(), 2)));
    double CA = fabs(sqrt(pow(C.getX() - A.getX(), 2) + pow(C.getY() - A.getY(), 2) + pow(C.getZ() - A.getZ(), 2)));

    double area = sqrt(fabs(AB*AB)*fabs(CA*CA) - AB*CA)/2;
    return area;


}
double triangle::perimeter() const
{
    double AB = fabs(sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2) + pow(A.getZ() - B.getZ(), 2)));
    double BC = fabs(sqrt(pow(B.getX() - C.getX(), 2) + pow(B.getY() - C.getY(), 2) + pow(B.getZ() - C.getZ(), 2)));
    double CA = fabs(sqrt(pow(C.getX() - A.getX(), 2) + pow(C.getY() - A.getY(), 2) + pow(C.getZ() - A.getZ(), 2)));
    double perimeter = AB+BC+CA;
    return perimeter;
}
point triangle::centroid() const
{
    double a = (A.getX() + A.getY() + A.getZ())/3;
    double b = (B.getX() + B.getY() + B.getZ())/3;
    double c = (C.getX() + C.getY() + C.getZ())/3;
    point p(a,b,c);
    return p;
}
bool triangle::operator<(const point &p)
{
    double A = this->surface();

    triangle t1(this->A,this->B, p);
    double A1 = t1.surface();

    triangle t2(this->A, p, this->C);
    double A2 = t2.surface();

    triangle t3(p, this->B, this->C);
    double A3 = t3.surface();

    double all = A1 + A2 +  A3;
    return A == all;
}
bool triangle::operator>(const point &p)
{
    double A = this->surface();

    triangle t1(this->A,this->B, p);
    double A1 = t1.surface();

    triangle t2(this->A, p, this->C);
    double A2 = t2.surface();

    triangle t3(p, this->B, this->C);
    double A3 = t3.surface();

    double all = A1 + A2 +  A3;
    return A < all;
}
bool triangle::operator==(const point &p)
{
    line AB(A,B);
    line BC(B,C);
    line CA(C,A);
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
        std::cout << "Point lies on AC/\n";
        return true;
    }
    else
    {
        std::cout << "Point doesn't lie neither side.\n";
        return false;
    }
}

std::ostream& triangle::ins(std::ostream &out) const
{
    out << A << B << C;
    return out;
}
std::ostream& operator << (std::ostream& lhs, const triangle & rhs)
{
    return rhs.ins(lhs);
}