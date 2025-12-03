#include "shapes.h"

GeoShape::GeoShape() {this->dim1=1.0; this->dim2=1.0;}

GeoShape::GeoShape(double dim1, double dim2)
{
    // quick validation
    if (dim1 >0 && dim2>0){
        this->dim1=dim1;
        this->dim2=dim2;
    }
    else{
        this->dim1 = 1.0;
        this->dim2 = 1.0;
    }
}

GeoShape::~GeoShape(){}

Rectangle::Rectangle():GeoShape(){}
Rectangle::Rectangle(double dim1, double dim2):GeoShape(dim1,dim2){}
double Rectangle::getArea(){return dim1*dim2;}

Triangle::Triangle():GeoShape(){}
Triangle::Triangle(double base, double height):GeoShape(base,height){}
double Triangle::getArea(){return 0.5*dim1*dim2;}

Square::Square():Rectangle(){}
Square::Square(double side):Rectangle(side,side){}
double Square::getArea(){return dim1*dim1;}

Circle::Circle():GeoShape(){}
Circle::Circle(double radius):GeoShape(radius,radius){}
double Circle::getArea(){return (22.0/7)*dim1*dim1;}