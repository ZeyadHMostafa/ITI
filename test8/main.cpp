#include "shapes.h"
using namespace std;

int main(){
    Rectangle r(1,2);
    Triangle t(1,2);
    Square s(5);
    Circle c(7);
    cout << "rect(1,2) area = " << r.getArea() << endl;
    cout << "tri(1,2)  area = " << t.getArea() << endl;
    cout << "square(5) area = " << s.getArea() << endl;
    cout << "circle(5) area = " << c.getArea() << endl;
    return 0;
}