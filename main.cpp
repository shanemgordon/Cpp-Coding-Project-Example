
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "DoublyLinkedList.hpp"
#include "Triangle.h"
#include "ScaleneTriangle.h"
#include "IsocelesTriangle.h"
#include "EquilateralTriangle.h"
using namespace std;
int main(int argc, char* args []){

    cout << "Program Started Successfully" << endl;

    //File reception/validation
    DoublyLinkedList<Triangle*> Triangles;
    string fileName;
    ifstream inputFile;
    if(argc > 1){
        fileName = args[1]; 
    }else{
        cout << "Please enter the filename to open: ";
        cin >> fileName;
    }
    inputFile.open(fileName);
    if(inputFile.fail()){
        cout << "File failed to open" << endl;
        return 0;
    }else{
        cout << "Parsing file " << fileName << "..." << endl;
    }

    //File Parsing
    while(!inputFile.eof()){
        char type;
        double x1,x2,x3,y1,y2,y3;
        int r,g,b;
        inputFile >> type;
        inputFile >> x1;
        inputFile >> y1;
        inputFile >> x2;
        inputFile >> y2;
        inputFile >> x3;
        inputFile >> y3;
        inputFile >> g;
        inputFile >> r;
        inputFile >> b;
        Triangle* triangle;
        //Determing Triangle type/polymorphizing
        switch(type){
            case 'E':
                triangle = new EquilateralTriangle();
            break;
            case 'I':
                triangle = new IsocelesTriangle();
            break;
            case 'S':
                triangle = new ScaleneTriangle();
            break;
            default:
                cout << "ERROR: TRIANGLE TYPE \'" << type << "\' NOT RECOGNIZED" << endl;
            break;
        }
        //Storing triangle
        triangle->setColor(Color(r,g,b));
        if(triangle->setCoordinates(Vector2f(x1,y1),Vector2f(x2,y2),Vector2f(x3,y3))==0){
            cout << "Triangle is invalid: \"" << type << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << r << " " << g << " " << b << "\"" << endl;
        }
        
        Triangles.insert(Triangles.size()+1,triangle);
    }

    //Triangle Displaying
    using namespace sf;
    RenderWindow window( VideoMode(640, 640), "Drawing" );
    while(window.isOpen()){

        window.clear();

        for(int i=0; i<Triangles.size();i++){
            Triangle* triangle = Triangles.get(i);
            triangle->draw(window);
        }

        window.display();

        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                cout << "Window closing..." << endl;
                window.close();
                break;
            }
        }

    }

    cout << "Program Ended Successfully" << endl;
    return 1;
    
}