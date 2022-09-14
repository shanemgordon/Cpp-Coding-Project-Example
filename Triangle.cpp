#include "Triangle.h"
#include <cmath>
float length(Vector2f p1, Vector2f p2){

    return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));

}
Triangle::Triangle(){
            color = Color::White;
            vertCount = 3;
            vertices = new Vector2f[3];
}
Triangle::~Triangle(){
            std::cout << "Deleting a Triangle's array" << std::endl;
            for(int i=0; i<3; i++){
                delete[] vertices;
            }   
}
void Triangle::setColor(const Color color){
            this->color = color;
}
void Triangle::draw(RenderTarget& window){
    ConvexShape shape;
    shape.setPointCount(3);
    for(int i=0; i<3; i++){
        shape.setPoint(i,vertices[i]);
    }
    shape.setFillColor(color);
    window.draw(shape);
}