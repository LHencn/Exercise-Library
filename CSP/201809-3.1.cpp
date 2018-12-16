/*************************************************************************
	> File Name: 201809-3.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月15日 星期六 20时58分35秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

void to_lower(string &str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] += 32;
    }
}

struct Node {       //树
    int level;      //点的数量
    string p, id;   //标签和id
    vector <Node *> childs;
    Node(string &str) {
        level = 0;
        while (str[level] == '.') ++ level;
        int pos = level;
        p = id = "";
        while (str[pos] && str[pos] != ' ') p += str[pos++];
        while (str[pos]) id += str[pos++];   
        to_lower(p);
    }
};

void output(Node *root) {
    if (root == NULL) return ;
    cout << root->p;
    for (int i = 0; i < root->childs.size(); i++) {
        cout << " " << root->childs[i]->p;
    }
    cout << endl;
    for (int i = 0; i < root->childs.size(); i++) {
        output(root->childs[i]);
    }
}
int main() {
    int n, m;
    stack<Node *> ss;
    cin >> n >> m;
    getchar();
    string str;
    while (n--) {
        getline(cin, str);
        Node *temp = new Node(str);
        while (!ss.empty() && temp->level <= ss.top()->level) ss.pop();
        if (!ss.empty()) ss.top()->childs.push_back(temp);
        ss.push(temp);
    }
    Node *root;
    while (!ss.empty()) root = ss.top(), ss.pop();
    output(root);

    return 0;
}
