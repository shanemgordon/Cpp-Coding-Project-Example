#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H
#include "Triangle.h"

class ScaleneTriangle : public Triangle {
    public: 
        bool setCoordinates(const Vector2f p1, const Vector2f p2, const Vector2f p3);
};
#endif