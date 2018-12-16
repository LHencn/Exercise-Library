/*************************************************************************
	> File Name: 201809-3.2.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月16日 星期日 08时04分06秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void to_lower(string &str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') 
            str[i] += 32;
    }
    return ;
}

struct Node {
    int level, ind;
    string p, id;
    vector<Node *> childs;
    Node(string &str, int ind) {
        this->ind = ind;
        level = 0;
        while (str[level] == '.') ++level;
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

vector<string> getMatch(string str) {
    int pos = 0;
    string temp = "";
    vector<string> ret;
    while (str[pos]) {
        if (str[pos] == ' ') {
            if (temp[0] != '#') to_lower(temp);
            ret.push_back(temp);
            temp = "";
        } else {
            temp += str[pos];
        }
        pos++;
    }
    if (temp[0] != '#') to_lower(temp);
    ret.push_back(temp);
    return ret;
}

void guang(Node *root, vector<string> &match, int k, vector<int> &ret) {
    if (root == NULL) return ;
    if (root->p == match[k] || root->id == match[k]) ++k;
    if (k == match.size()) ret.push_back(root->ind), --k;
    for (int i = 0; i < root->childs.size(); i++) {
        guang(root->childs[i], match, k, ret);
    }
    return ;
}



int main() {
    int n, m;
    stack<Node *> ss;
    string str;
    cin >> n >> m; getchar();
    for (int i = 1; i <= n; i++) {
        getline(cin, str);
        Node *temp = new Node(str, i);
        while (!ss.empty() && temp->level <= ss.top()->level) ss.pop();
        if (!ss.empty()) ss.top()->childs.push_back(temp);
        ss.push(temp);
    }
    Node *root;
    while (!ss.empty()) root = ss.top(), ss.pop();
    output(root);
    while (m--) {
        getline(cin, str);
        vector<int> ret;
        vector<string> match = getMatch(str);
        guang(root, match, 0, ret);
        cout << ret.size();
        for (int i = 0; i < ret.size(); i++) {
            cout << " " << ret[i];
        }
        cout << endl;
    }
    return 0;
}
