/*************************************************************************
	> File Name: practice.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月08日 星期一 08时39分42秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int arg1=0x40302010;
	int arg2=0x20;
	int* ptr1=NULL;
	int* ptr2=NULL;
	char str[] = {"1234567"};
	printf("arg1:%x\narg2:%x\n",&arg1,&arg2);
	printf("ptr1:%x\nptr2:%x\n",&ptr1,&ptr2);
	printf("str:%x\n",str);
char* arg1Ptr = (char*)&arg1;
	printf("arg1Ptr[0]:%02x\narg1Ptr[1]:%02x\narg1Ptr[2]:%02x\narg1Ptr[3]:%02x\n",*arg1Ptr,*(arg1Ptr+1),*(arg1Ptr+2),*(arg1Ptr+3));


    return 0;
}
