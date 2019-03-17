/*************************************************************************
	> File Name: lambda.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月07日 星期四 11时23分46秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int a = 5;
    auto inc = [&a](){a++;};
    inc();
    inc();
    cout << a << endl;
    int x = 5, y = 6;
    auto func2 = [x, y](int x, int y) {
        cout << this->x << endl;
    };

    return 0;
}
