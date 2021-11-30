#include<iostream>
#include<math.h>
using namespace std;
class Figure{
public:
    virtual double getArea() = 0;
};
class Circle: public Figure{
protected:
    double promien;
public:
    Circle(double promien) : promien(promien) {

    }

    double getArea(){
       double a;
       a = M_PI*pow(promien,2);
       return a;
    }
};
class Rectangle: public Figure{
protected:
    double a,b;
public:
    Rectangle(double a, double b) : a(a), b(b) {

    }

    double getArea(){
double c;
c = a * b;
return c;
    }
};

int main()
{

    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
     cout << "Rectangle area: " << rectangle->getArea() << endl;


     return 0;
}

