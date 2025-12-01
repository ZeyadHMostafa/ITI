#include <iostream>
#include <vector>

class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Shape {
public:
    virtual void draw() const = 0;
};

class Line : public Shape {
public:
    Point start, end;

    Line(Point start, Point end) : start(start), end(end) {}

    void draw() const override {
		// place holder since we agreed on no library
        std::cout << "Drawing a line from (" << start.x << ", " << start.y << ") to (" << end.x << ", " << end.y << ")" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    Point top_left, bottom_right;

    Rectangle(Point top_left, Point bottom_right) : top_left(top_left), bottom_right(bottom_right) {}

    void draw() const override {
		// place holder since we agreed on no library
        std::cout << "Drawing a rectangle from (" << top_left.x << ", " << top_left.y << ") to (" << bottom_right.x << ", " << bottom_right.y << ")" << std::endl;
    }
};

class Circle : public Shape {
public:
    Point center;
    int radius;

    Circle(Point center, int radius) : center(center), radius(radius) {}

    void draw() const override {
		// place holder since we agreed on no library
        std::cout << "Drawing a circle with center (" << center.x << ", " << center.y << ") and radius " << radius << std::endl;
    }
};

class Picture {
public:
    std::vector<Shape*> shapes;

    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void draw() const {
        for (const auto& shape : shapes) {
            shape->draw();
        }
    }
};

int main() {
    Picture picture;

    Line line(Point(1, 2), Point(3, 4));
    picture.addShape(&line);

    Rectangle rectangle(Point(5, 6), Point(7, 8));
    picture.addShape(&rectangle);

    Circle circle(Point(10, 10), 5);
    picture.addShape(&circle);

    picture.draw();

    return 0;
}
