#ifndef ISOCELESTRIANGLE_H
#define ISOCELESTRIANGLE_H
#include "Triangle.h"

class IsocelesTriangle : public Triangle{

    public:

        bool setCoordinates(const Vector2f p1, const Vector2f p2, const Vector2f p3);

};

#endif