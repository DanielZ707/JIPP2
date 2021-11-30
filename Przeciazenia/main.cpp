#include<iostream>
#include<math.h>
using namespace std;

class Vector{
private:
    double x, y;

public:
    Vector();
    friend void print(const Vector &V1);
    Vector(double x, double y) : x(x), y(y) {}

    double length() {
        return sqrt(x * x + y * y);
    }
bool operator>(const Vector &rhs){
    return((x*x+y*y)>(rhs.x*rhs.x+rhs.y*rhs.y));
    }
    bool operator<(const Vector &rhs){
        return((x*x+y*y)<(rhs.x*rhs.x+rhs.y*rhs.y));
    }
    bool operator==(const Vector &rhs){
        return((x*x+y*y)>(rhs.x*rhs.x+rhs.y*rhs.y));
    }
    bool operator!=(const Vector &rhs){
        return((x*x+y*y)>(rhs.x*rhs.x+rhs.y*rhs.y));
    }
    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }
    Vector operator-(const Vector &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
    Vector operator*(const double &rhs) const {
        return {x * rhs, y * rhs};
    }

    Vector operator!( Vector V) {
        return V;
    }
};
void print(const Vector &V1){
    cout<<"wektor:"<<endl;
    cout << "x = " << V1.x << " y =" << V1.y << endl;
}
Vector::Vector(): x(0), y(0) {}

int main()
{
    Vector V1(10,13), V2(12,14), V3, V4, V5, V6, V7, V8;
    V3 = V1.operator + (V2);
    V4 = V1.operator - (V2);
    V5 = V1.przeciwny(V1);
    V6 = V1.operator*(2);


    print(V3);
    print(V4);
    print(V5);
    print(V6);
    print(V7);
    print(V8);

    return 0;
}