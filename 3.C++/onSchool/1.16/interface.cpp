/*************************************************************************
	> File Name: interface.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 14时40分12秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class interface {
    public :
        virtual bool open() = 0;
        virtual void close() = 0;
        virtual bool send(char *buf, int len) = 0;
        virtual int receive(char *buf, int len) = 0;
};


