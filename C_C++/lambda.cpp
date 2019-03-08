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

int a = 0;
int main() {
    auto inc = [&a](){a++;};
    inc();
    inc();
    cout << a << endl;
    return 0;
}
