#include <iostream>

class GeoShape
{
protected:
    double dim1;
    double dim2;
public:
    GeoShape();
    GeoShape(double dim1, double dim2=0);
    ~GeoShape();
    virtual double getArea()=0;
};

class Rectangle: public GeoShape
{
public:
    Rectangle();
    Rectangle(double dim1, double dim2=0);
    double getArea();
};

class Triangle: public GeoShape
{
public:
    Triangle();
    Triangle(double base, double height=0);
    double getArea();
};

class Square: private Rectangle
{
protected:
    double get_side() const;
    void set_side(const double val);
public:
    Square();
    Square(double side);
    double getArea();
};

class Circle: private GeoShape
{
protected:
    double get_radius() const;
    void set_radius(const double val);
public:
    Circle();
    Circle(double radius);
    double getArea();
};