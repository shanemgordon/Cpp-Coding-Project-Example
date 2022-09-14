#include "IsocelesTriangle.h"
/**
 * @brief Set the coordinates for an isoceles triangle only if the given vertices match the correct profile
 * 
 * @param p1 The first point
 * @param p2 The second point
 * @param p3 The third point
 * @return true if two side lengths are equal and none are equal to zero
 * @return false if the above is not satisfied
 */
bool IsocelesTriangle::setCoordinates(const Vector2f p1, const Vector2f p2, const Vector2f p3){

    float l1 = length(p1,p2);
    float l2 = length(p2, p3);
    float l3 = length(p3,p1);

    if(l1!=l2&&l2!=l3&&l1!=l3) return false;

    if(!(l1 + l2 > l3 && l2 + l3 > l1 && l3 + l1 > l2 && l1*l2*l3 != 0)) return false;
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    return true;

}