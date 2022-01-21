/*#include <iostream>
#include <vector>


using namespace std;
class Stop {
private:
    long id;
    string name;
    double latitude;
    double longitude;

public:
    Stop(long id, const string &name, double latitude, double longitude);

    Stop() {};

    void print();
};
class Line {
private:
    string number;
    string direction;
    vector<Stop *> stops;

public:
    Line(const string &number, const string &direction);

    void addStop(Stop * stop);

    void print();

};
Stop::Stop(long id, const string &name, double latitude, double longitude) : id(id), name(name), latitude(latitude),
                                                                             longitude(longitude) {}

void Stop::print() {
    cout<< id << endl << name << endl << latitude << " " << longitude << endl;

}

int main() {
    vector<Stop> stops;
    stops.reserve(10);
    stops.emplace_back(1, "Politechnika", 50.1, 50.2);
    stops.emplace_back(2, "Nowy Kleparz", 50.2, 50.2);
    stops.emplace_back(3, "Plac Inwalidów", 50.2, 50.2);
    stops.emplace_back(4, "Urzędnicza", 50.2, 50.2);
    stops.emplace_back(5, "Biprostal", 50.2, 50.2);
    stops.emplace_back(6, "Uniwersytet Pedagogiczny", 50.2, 50.2);

    Line l1("P", "Podchorążych");
    l1.addStop(&stops[0]);
    l1.addStop(&stops[1]);
    l1.addStop(&stops[2]);
    l1.addStop(&stops[3]);
    l1.addStop(&stops[4]);
    l1.addStop(&stops[5]);

    l1.print();

    cout << "---------------------------------------" << endl;
    stops.emplace_back(7, "Bratysławska", 50.2, 50.2);
    stops.emplace_back(8, "Teatr Bagatela", 50.2, 50.2);
    stops.emplace_back(9, "Stary Kleparz", 50.2, 50.2);
    stops.emplace_back(10, "Teatr Słowackiego", 50.2, 50.2);
    stops.emplace_back(11, "Teatr Słowackiego1", 50.2, 50.2);
    stops.emplace_back(12, "Teatr Słowackiego2", 50.2, 50.2);
    stops.emplace_back(13, "Teatr Słowackiego3", 50.2, 50.2);

    l1.print();

    cout << "---------------------------------------" << endl;
    stops[0].print();
    stops[1].print();
    stops[2].print();

    return 0;
}
/*#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void simpleVector() {
    vector<int> vect;
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void smarterVector() {
    vector<int> vect;
    vect.reserve(20);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void simpleVectorNoCout() {
    vector<int> vect;

    vect.push_back(1);

    vect.push_back(1);

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    vect.pop_back();

    vect.pop_back();

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    vect.shrink_to_fit();
}

void smarterVectorNoCout() {
    vector<int> vect;
    vect.reserve(20);

    vect.push_back(1);

    vect.push_back(1);

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);

    vect.pop_back();

    vect.pop_back();

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();

    vect.shrink_to_fit();
}

int main()
{
    simpleVector();

    cout << endl << endl;
    smarterVector();

    cout << endl << endl;
    auto start = chrono::steady_clock::now();
    for(int i =0; i < 1000; ++i)
        simpleVectorNoCout();
    auto end = chrono::steady_clock::now();

    auto start1 = chrono::steady_clock::now();
    for(int i =0; i < 1000; ++i)
        smarterVectorNoCout();
    auto end1 = chrono::steady_clock::now();

    cout << "Simple vector called 1000x time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    cout << "Smarter vector called 1000x time: " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect;
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    return 0;
}

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
 */
#include <iostream>

using namespace std;

class Vehicle {
protected:
    unsigned short amountOfWheels;

public:
    Vehicle(unsigned short amountOfWheels) : amountOfWheels(amountOfWheels) {

    }

    unsigned short getAmountOfWheels() const {
        return amountOfWheels;
    }

    virtual void printAllData () = 0;
};

class Car: public Vehicle {
protected:
    unsigned short amountOfDoors;

public:
    Car(unsigned short amountOfWheels, unsigned short amountOfDoors) : Vehicle(amountOfWheels),

                                                                       amountOfDoors(amountOfDoors) {}
    void printAllData () {
        cout << "Im Car" << endl;
    }

    void run() {
        cout << "run " << endl;
    }

    void breaking() {
        cout << "Break" << endl;
    }
};

class Motor: public Vehicle {
protected:
    double engineVolume;

public:
    Motor(unsigned short amountOfWheels, double engineVolume) : Vehicle(amountOfWheels), engineVolume(engineVolume) {}

    void printAllData () {
        cout << "Im Motor" << endl;
    }

};

class Task {
public:
    virtual void run() = 0;
};

class TaskFunction: public Task {
private:
    void (*function)();

public:
    void run() {
        function();
    }
};

class TaskTemplateClass {
public:
    virtual void execute() = 0;
};

class TaskClass: public Task {
private:
    TaskTemplateClass *taskClass;

public:
    void run() {
        taskClass->execute();
    }
};



int main() {
//    Vehicle v(2);
//
//    Car c1(4, 5);
//
//    v.printAllData();
//    c1.printAllData();

    Vehicle *v = new Car(5,5);
    Vehicle *v1 = new Motor(5,5);

    Vehicle *vTab[5];
    vTab[0] = new Car(6,6);
    vTab[1] = new Motor(6,6);


    Task *tasks[10];
    //Dodawanie tasków
    tasks[0] = new TaskFunction ...;
    tasks[1] = new TaskClass ... ;
    for(int i = 0; i < 10; ++i) {
        tasks[i]->run();
    }
    return 0;
}