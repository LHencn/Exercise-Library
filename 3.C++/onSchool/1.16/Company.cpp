/*************************************************************************
	> File Name: Company.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 09时53分43秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class CompanyABoss {
    public :
    int battle() {
        int ret = 10;
        cout << "CompanyABoss :: battle = " << ret << endl;
        return ret;
    }
};

class CompanyBBoss {
    public :
    virtual int fight() {
        int ret = 8;
        cout << "CompanyBBoss :: fight = " << ret << endl;
        return ret;
    }
};

class CompanyBNewBoss : public CompanyBBoss {
    public :
    int fight() {
        int ret = /*this->*/CompanyBBoss::fight() * 2; //当前对象的父类的方法
        cout << "New Boss::fight = " << ret << endl;
        return ret;
    }
};

void vs(CompanyABoss *c1, CompanyBBoss *c2) {
    int a = c1->battle();
    int b = c2->fight();
    if (a > b) {
        cout << "Company A is vinner" << endl;
    } else {
        cout << "Company B is winner" << endl;
    }
}

int main() {
    CompanyABoss c1;
    CompanyBBoss c2;
    vs(&c1, &c2);
    cout << "one year later..." << endl;
    CompanyBNewBoss nb;
    vs(&c1, &nb);
    return 0;
}
