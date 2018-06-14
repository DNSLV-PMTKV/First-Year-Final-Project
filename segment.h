#ifndef PROJECT_VECTOR_SEGMENT_H
#define PROJECT_VECTOR_SEGMENT_H

#include <iostream>
#include "line.h"

class segment : public line
{
public:
    segment();
    segment(point, vector, int[2]);
    segment(const segment&);
    ~segment();
    segment&operator=(const segment&);

    double length();
    point mid() const ;

    bool operator==(const point &);

    virtual std::ostream& ins(std::ostream&) const;
    friend std::ostream &operator<<(std::ostream &, const segment &);

private:
    point t1, t2;
    int t[2];
};


#endif //PROJECT_VECTOR_SEGMENT_H
