/*************************************************************************
	> File Name: myprintf.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月09日 星期二 16时39分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int print_int(int x, int flag) {
    if (x == 0) {
        flag && putchar('0');
        return !!(flag);
    }
    int temp = x, ret = 0, digit = 0;
    x = 0;
    if (temp < 0) temp = -temp, printf("-");
    while (temp) {
        x = x * 10 + temp % 10;
        temp /= 10;
        digit++;
    }
    while (digit--) {
        putchar(x % 10 + '0');
        ret++;
    }
    return ret;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch(frm[i]) {
            case '%': {
                i++;
                switch(frm[i]) {
                    case 'd': {
                        int temp = va_arg(arg, int);
                        int p1 = temp / 10, p2 = temp % 10;
                        if (temp < 0) {
                            p1 = -p1, p2 = -p2;
                            putchar('-'); cnt++;
                        }
                        cnt += print_int(p1, 0);
                    }
                }
            }
        }
    }
}

