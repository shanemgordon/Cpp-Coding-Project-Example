#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <SFML/Graphics.hpp>

//For debugging purposes
#include <iostream>
using namespace sf;
/*
Begin by creating an abstract Triangle class. The class will have the following members and corresponding implementations:

public
default constructor - sets the color to white, specifies the number of vertices as 3, allocates the list to have three elements (if necessary)
destructor - deallocates the list (if necessary)
void setColor(const Color color) - sets the private color data member
void draw(RenderTarget& window) - creates a ConvexShape, sets the points for each coordinate, sets the fill color, draws it to the provided window
a pure virtual bool setCoordinates() function that accepts the (x, y) coordinate for three vertices
protected
the number of vertices making up the triangle as an integer
a list of (x, y) coordinates
private
the color of the triangle as an SFML Color object
*/
float length(const Vector2f p1, const Vector2f p2);
class Triangle{
    public:
        Triangle();
        ~Triangle();
        void setColor(const Color color);
        void draw(RenderTarget& window);
        virtual bool setCoordinates(const Vector2f p1, const Vector2f p2, const Vector2f p3) = 0;
        protected:
            unsigned int vertCount;
            Vector2f* vertices;
        private:
            Color color;
};
#endif