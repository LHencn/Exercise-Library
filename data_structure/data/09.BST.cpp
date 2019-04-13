/*************************************************************************
	> File Name: 09.BST.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月31日 星期日 10时20分08秒
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
using namespace std;

class BSTNode {
public :
    BSTNode() : lchild(nullptr), rchild(nullptr) {}
    BSTNode(int val) : val(val), lchild(nullptr), rchild(nullptr) {}
    BSTNode *getNewNode(int);
    bool insert(int);
    bool erase(int);
    bool search(int);
    virtual ~BSTNode();
    void setVal(int);
    void setLchild(BSTNode *);
    void setRchild(BSTNode *);
private:
    int val;
    BSTNode *lchild, *rchild;
};

BSTNode &getNewNode(int val) {
    BSTNode node;
    node.setVal(val);
    node.setLchild(nullptr);
    node.setRchild(nullptr);
    return node;

}

    
