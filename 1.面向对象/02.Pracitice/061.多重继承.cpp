#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct A
{
    int a;
    A() { a = 0; }
};

struct B :virtual A
{
};

struct C : virtual A
{
};

struct D : B, C
{
};

int main()
{
    D d;
    A *pb = static_cast<B *>(&d);
    A *pc = static_cast<C *>(&d);
    pb->a = 1;
    pc->a = 2;
    cout << "pb->a:" << pb->a << " pc->a:" << pc->a << endl;
    return 0;
}
