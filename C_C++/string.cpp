/*************************************************************************
	> File Name: string.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月06日 星期三 10时57分26秒
 ************************************************************************/

/*
 *C++采用string方法复制字符串
 */

#include <iostream>
#include <string>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    char s[] = "abcdefg";
    char b[4];
    strncpy(b, s + 2, 3);
    b[3] = '\0';
    cout << "b: " << b << endl;

    string st = "abcdefg";
    string d(begin(st) + 2, begin(st) + 5); //此时string是类，定义对象d，只能采用cout输出，prinf不可以
    cout << "d: "<< d << endl;
    return 0;
}
