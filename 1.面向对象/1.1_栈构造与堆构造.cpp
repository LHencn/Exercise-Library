/*************************************************************************
	> File Name: 1.1_栈构造与堆构造.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月08日 星期五 10时06分33秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct Link {
    int data;
    Link *next;
};

void FreeLink(Link *head) {
    while (head) {
        delete head;
        head = head->next;
    }
}

int main() {
    Link c{3, nullptr};
    Link b{2, &c};
    Link a{1, &b};
    FreeLink(&a);
    return 0;
}

