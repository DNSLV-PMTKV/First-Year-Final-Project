//#include <cmath>
//#include "line.h"
////line::line():x1(0),x2(0),y1(0),y2(0),z1(0),z2(0) {}
//line::line(): a(point()),b(point()){}
////line::line(vector v, point b)
////    : x1(b.getX()), y1(b.getY()), z1(b.getZ())
////{
////    std::cout << "Enter vector params:\n";
////    std::cin >> v;
////    x2 = v.getX();
////    y2 = v.getY();
////    z2 = v.getZ();
////}
//line::line(vector v, point A)
//{
//    a.setX(v.getX());
//    a.setY(v.getY());
//    a.setZ(v.getZ());
//    b.setX(A.getX());
//    b.setY(A.getY());
//    b.setZ(A.getZ());
//}
////line::line(point a, point b)
////    : x1(a.getX()), y1(a.getY()), z1(a.getZ())
////{
////    vector v(a, b);
////    x2 = v.getX();
////    y2 = v.getY();
////    z2 = v.getZ();
////}
//line::line(point A, point B)
//{
//    a.setX(A.getX());
//    a.setY(A.getY());
//    a.setZ(A.getZ());
//    b.setX(B.getX());
//    b.setY(B.getY());
//    b.setZ(B.getZ());
//}
//line::~line() {}
//line::line(const line & rhs)
//{
//    a = rhs.a;
//    b = rhs.b;
//}
//line& line::operator=(const line & rhs)
//{
//    if(this!=&rhs)
//    {
//        a = rhs.a;
//        b = rhs.b;
//    }
//    return *this;
//}
//vector line::normalVector(const line &rhs)
//{
//    double X = b.getX() - a.getX();
//    double Y = b.getY() - a.getY();
//    double Z = b.getZ() - a.getZ();
//    return vector(X,Y,Z);
//}
//double line::angle(const line & rhs)
//{
//    vector v1(a, b);
//    vector v2(rhs.a, rhs.b);
//    double dot = v1 * v2;
//    double a_x = v1.getX() * v1.getX();
//    double a_y = v1.getY() * v1.getY();
//    double a_z = v1.getZ() * v1.getZ();
//    double a_dist = sqrt(a_x+ a_y + a_z);
//    double b_x = v2.getX() * v2.getX();
//    double b_y = v2.getY() * v2.getY();
//    double b_z = v2.getZ() * v2.getZ();
//    double b_dist = sqrt(b_x + b_y + b_z);
//    double angle = dot/(a_dist*b_dist);
//    angle = acos(angle);
//    return angle;
//}
//bool line::operator+(const point &rhs)
//{
//    double one = (rhs.getX() - a.getX()) / (b.getX() - a.getX());
//    double two = (rhs.getY() - a.getY()) / (b.getY() - a.getY());
//    double three = (rhs.getZ() - a.getZ()) / (b.getZ() - a.getZ());
//    std::cout << one << std::endl << two << std::endl << three;
//    return (one == two && two == three);
//}
//bool line::operator||(const line&rhs)
//{
//    double tmp_x1 = rhs.a.getX() - a.getX();
//    double tmp_x2 = rhs.b.getX() - b.getX();
//    std::cout << rhs.b.getX() << std::endl;
//    std::cout << b.getX() << std::endl;
//    std::cout << tmp_x2 << std::endl;
//    //double slope = b.
////    double tmp_y1 = rhs.y1 - y1;
////    double tmp_y2 = rhs.y2 - y2;
////    double tmp_z1 = rhs.z1 - z1;
////    double tmp_z2 = rhs.z2 - z2;
////    return tmp_x1 == tmp_x2 == tmp_y1 == tmp_y2 == tmp_z1 == tmp_z2;
//}
//
//
//std::ostream& line::ins(std::ostream &out) const
//{
//    std::cout << "First point: \n" << a;
//    std::cout << "Second point: \n" << b;
//}
//std::ostream& operator << (std::ostream& lhs, const line & rhs)
//{
//    return rhs.ins(lhs);
//}