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
    return 0;
}
