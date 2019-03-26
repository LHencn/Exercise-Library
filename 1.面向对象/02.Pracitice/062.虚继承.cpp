#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct A
{
    int data;
    
    A() : data(345) {
        cout << "A()" << endl;
    }
    A(int theData)
        :data{ theData }
    {
    }
};

struct B : virtual A
{
    B() :A{ 1 }
    {
        cout << data << "B()"<< endl;
    }
};

struct C : A
{
    C() :A{ 2 }
    {
        cout << data << "C()" << endl;
    }
};

struct D : B, C
{
    D() : A { 789 } {
        
    }
};

int main()
{
    D d;
    cout << d.data << endl;
    return 0;
}
