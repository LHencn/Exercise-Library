/*************************************************************************
	> File Name: myPrintf.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月20日 星期四 20时29分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int print_int(int x, int flag) {
    if (x == 0) {
        flag && putchar('0');
        return !!(flag);
    }
    int temp = x, ret = 0;
    x = 0;

}
int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    int flag1 = 0;
    for (int i = 0; frm[i]; i++, cnt++) {
        switch(frm[i]) {
            case '%': {
                i++;
                switch(frm[i]) {
                    case 'd': {
                        int temp = va_arg(arg, int), x = 0;
                        int p1 = temp / 10, p2 = temp % 10;
                        if (temp < 0) {
                            p1 = -p1, p2 = -p2;
                            putchar('-'); cnt++;
                        }
                        cnt += print_int(p1, 0);
                        cnt += print_int(p2, 1);
                    } break;
                    default;
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]);
                        exit(1);
                }
            } break;
            default :
                putchar(frm[i]); 
                cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    
    my_printf("hello haizei\n");
    my_printf("n = %d\n", 123);
    my_printf("n = %d\n", 1200);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);    
    return 0;

}
