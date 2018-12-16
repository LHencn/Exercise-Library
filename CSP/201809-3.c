/*************************************************************************
	> File Name: 201809-3.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月15日 星期六 20时18分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>


struct Node {
    int level;
    string p, id;      //标签大小写不敏感 id大小写敏感
    vector<Node *> childs;
};



