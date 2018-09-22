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

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    int flag1 = 0;
    int a[11] = {0};
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch(frm[i]) {
            case '%': {
                i++;
                switch(frm[i]) {
                    case 'd': {
                        int64_t temp = va_arg(arg, int), x = 0;
                        if (temp == 0)
                            putchar(0 + '0');
                        while (temp) {
                            if (temp < 0) {                        //判断负数
                                putchar('-');
                                temp = 0 - temp;
                            }
                            if (x == 0 && temp % 10 == 0)          //判断以输出0
                                flag1++;
                            x = x * 10 + temp % 10;
                            temp /= 10;
                        }
                        while (x) {                                //输出0
                            putchar(x % 10 + '0');
                            x /= 10;
                        }
                        while (flag1--) {
                            putchar(0 + '0');
                        }
                    } break;
                    default :
                        fprintf(stderr, "error: unknow %%c\n", frm[i]);
                    exit(1);
                }
            } break;
            default :
                putchar(frm[i]);
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
