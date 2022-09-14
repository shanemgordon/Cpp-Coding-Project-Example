#include "EquilateralTriangle.h"
/**
 * @brief Set the coordinates for an isoceles triangle only if the given vertices match the correct profile
 * 
 * @param p1 The first point
 * @param p2 The second point
 * @param p3 The third point
 * @return true if the side lengths are all equal and are not zero
 * @return false if the above is not satisfied
 */
bool EquilateralTriangle::setCoordinates(const Vector2f p1, const Vector2f p2, const Vector2f p3){

            float l1 = length(p1,p2);
            float l2 = length(p2, p3);
            float l3 = length(p3,p1);
            //A tolerance of 1 is given since floating point arithmetic is rarely precise
            //Check if the difference between any two sides is greater than one, then if any of the sides is zero
            if(!((abs(l2-l1)<=1) && (abs(l3-l1)<=1) && (abs(l3-l1)<=1) && l1!=0 && l2!=0 && l3!=0)) return false;
            //Otherwise store the points and return true
            vertices[0] = p1;
            vertices[1] = p2;
            vertices[2] = p3;
            return true;
}