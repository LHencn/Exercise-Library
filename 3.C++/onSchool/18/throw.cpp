/*************************************************************************
	> File Name: throw.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月18日 星期五 14时44分03秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    /*
    try {
        throw 1;
    } catch(char c) {
        cout << "catch(char c)" << c << endl;
    } catch(short s) {
        cout << "catch(short s)" << s << endl;
    } catch(double d) {
        cout << "catch (double d)" << d << endl;
    } catch (int i) {
        cout << "catch (int i)" << i << endl;
    } catch(...) {
        cout << "catch(...)" << endl;
    }
    */

    try {
        try {
            throw 'a'; //1
        } catch(int i) {
            cout << "catch(int i)" << i << endl;
            throw i;
        } catch(...) {
            cout << "catch(...)" << endl;
            throw;//2带着异常'a'
        }
    } catch(char c) {//捕获'a'
        cout << "information is : " << c << endl;
    } catch(...) {
        cout << "other exception" << endl;
    }
    cout << "final" << endl;
    return 0;
}
