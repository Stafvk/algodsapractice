#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "A::show()" << endl;
    }
};

class B : public A {
public:
    void show() {
        cout << "B::show()" << endl;
    }
};

int main() {
    A* obj = new B();
    /*
    You’re storing a pointer to the base class, but the object is of derived type
The method called depends on whether the base class method is virtual
Enables polymorphism*/

    
    // B obj;
    obj->show(); // ⚠️ What will this print?
    return 0;
}
