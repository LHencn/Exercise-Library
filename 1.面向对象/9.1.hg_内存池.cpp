/*************************************************************************
	> File Name: 34.memory_pool.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 日  3/24 20:28:29 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Node {
public:
    Node() : lchild(nullptr), rchild(nullptr), val(0) {}
private:
    Node *lchild, *rchild;
    int val;
};

template<typename T>
class Pool {
public:
    class PoolNode : public T {
    public :
        PoolNode() : used(false), next(nullptr) {}
        bool used;
        PoolNode *next;
    };
    Pool(size_t n) : size(n) {
        mem = new PoolNode[n];
        initPool();
    }
    T *getObj() {
        if (head == nullptr) return nullptr;
        PoolNode *p = head;
        head = head->next;
        p->used = true;
        return p;
    }
    void destroyObj(T *obj) {
        PoolNode *p = reinterpret_cast<PoolNode *>(obj);
        if (p == nullptr) return ;
        if (p->used == false) return ;
        p->used = true;
        p->next = head;
        head = p;
        return ;
    }

private:
    Pool() {}
    void initPool() {
        head = &mem[0];
        for (int i = 0; i < size; i++) {
            if (i != size - 1) mem[i].next = mem + i + 1;
        }
        return ;
    }
    size_t size;
    PoolNode *mem, *head;
};

int main() {
    Pool<Node> p(10);
    Node *p1 = p.getObj(), *p2 = p.getObj();
    cout << p1 << " " << p2 << endl;
    p.destroyObj(p1);
    p.destroyObj(p2);
    p1 = p.getObj();
    cout << p1 << endl;
    return 0;
}
