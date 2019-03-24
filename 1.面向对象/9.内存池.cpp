/*************************************************************************
	> File Name: 9.内存池.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月24日 星期日 20时29分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>

#define CNT 16

using namespace std;

class Node {
public :
    Node () : lchild(nullptr), rchild(nullptr), val(0) {}
private :
    Node *lchild, *rchild;
    int val;
};

template<typename T>
class Pool : public T {
public:
    Pool() {}

};

Pool<Node> buffer[CNT];

Pool<Node> *unused;

Node *getNewNode(int val) {
    if (unused == nullptr) return nullptr;
    Pool<Node> *ret = unused;
    unused = unused->next;
    
}

void clear(Node *node) {
    
}

int main() {
    
    return 0;
}
