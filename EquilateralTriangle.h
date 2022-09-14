#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H
#include "Triangle.h"
#include <cmath>
using namespace std;
class EquilateralTriangle : public Triangle{
    
    public:

        bool setCoordinates(const Vector2f p1, const Vector2f p2, const Vector2f p3);


};

#endif