/*************************************************************************
	> File Name: ls1.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月23日 星期日 00时06分53秒
 ************************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    return a < b;
}
int main(){
    //struct __dirstream  typedef struct __dirstream DIR;  
    DIR *dir;
    char str[100];
    string res[100];
    struct dirent *rent;//struct
    dir = opendir(".");
    int cnt = 0;
    while((rent=readdir(dir))){
        strcpy(str, rent->d_name);
        if(str[0] == '.')
            continue;
        if(!str)
            continue;
        //printf("%s  ", str);
        res[cnt++] = str;
    }
    //cout<<"cnt = "<<cnt<<endl;
    sort(res, res+cnt, cmp);
    for(int i=0; i<cnt; i++)
        cout<<res[i]<<"  ";
    puts("");
    closedir(dir);
    return 0;

}


