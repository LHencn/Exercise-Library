/*************************************************************************
	> File Name: 8.1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月13日 星期日 18时28分05秒
 ************************************************************************/

#include<stdio.h>


int atoi(char *str) {
    int i = 0, ret = 0, flag = 1, pre_ret;
    while (str[i] == ' ') ++i;
    if (str[i] == '-') flag = -1, i++;
    while (str[i] && str[i] <= '9' && str[i] >= '0') {
        pre_ret = ret;
        ret = ret * 10 + (str[i] - '0');
        if (ret / 10 != pre_ret) {
            return flag == -1 ? INT_MIN : INT_MAX;
        }


        
    }
}
