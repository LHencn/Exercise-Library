/*************************************************************************
	> File Name: 2.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月23日 星期六 09时52分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct RBTNode {
    int key;
    int color;
    struct RBTNode *lchild, *rchild;
}RBTNode;

RBTNode *NIL;

__attribute__((constructor))
void init_NIL() {
    NIL = (RBTNode *)malloc(sizeof(RBTNode));
    NIL->color = BLACK;
    NIL->key = -1;
    NIL->lchild = NIL->rchild = NIL;
}

RBTNode *init(int key) {
    RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

int has_red_child(RBTNode *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

RBTNode *left_rotate(RBTNode *root) {
    RBTNode *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

RBTNode *right_rotate(RBTNode *root) {
    RBTNode *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

RBTNode *insert_maintain(RBTNode *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED && (has_red_child(root->lchild) || has_red_child(root->rchild))) {
    } else if (root->lchild->color == RED && has_red_child(root->lchild)) { 
        //判断条件为左孩子为红且左孩子有红孩子
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (root->rchild->color == RED && has_red_child(root->rchild)) {
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    } else {
        return root;
    }
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

RBTNode *__insert(RBTNode *root, int key) {
    if (root == NIL) return init(key);
    if (root->key == key) return root;
    if (key > root->key) 
        root->rchild = __insert(root->rchild, key);
    else 
        root->lchild = __insert(root->lchild, key);
    return insert_maintain(root);
}

RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

RBTNode *predecessor(RBTNode *root) {
    RBTNode *temp = root->lchild;
    //判断条件不是不等于空，而是不等于NIL
    while (temp->rchild != NIL) temp = temp->rchild; 
    return temp;
}

RBTNode *erase_maintain(RBTNode *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    #define UNBLANCE(a, b) (root->a->color == DOUBLE_BLACK && root->b->color == BLACK && !has_red_child(root->b))
    if (UNBLANCE(lchild, rchild) || UNBLANCE(rchild, lchild)) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;;
    }
    #undef UNBLANCE
    if (root->lchild->color == DOUBLE_BLACK) {
        if (root->rchild->color == RED) {
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild->color = RED;
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        if (root->rchild->rchild->color != RED) {
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            root->rchild->rchild->color = RED;
        }
        root->lchild->color = BLACK;
        root = left_rotate(root);
        root->color = root->lchild->color; //root变为原来根节点的颜色
        root->lchild->color = root->rchild->color = BLACK;
        return root;
    }
    if (root->rchild->color == DOUBLE_BLACK) {
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild->color = RED;
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        if (root->lchild->lchild->color != RED) {
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
            root->lchild->lchild->color = RED;
        }
        root->rchild->color = BLACK;
        root = right_rotate(root);
        root->color = root->rchild->color; 
        root->rchild->color = root->lchild->color = BLACK;
        return root;
    }
}

RBTNode *__erase(RBTNode *root, int key) {
    if (root == NIL) return NIL;
    if (key > root->key)
        root->rchild = __erase(root->rchild, key);
    else if (key < root->key) {
        root->lchild = __erase(root->lchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            RBTNode *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            //return erase_maintain(temp);????????
            return temp; //??????
        } else {
            RBTNode *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
            //return erase_maintain(root); ?????????????
        }
    }
    return erase_maintain(root);
}

RBTNode *erase(RBTNode *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(RBTNode *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(RBTNode *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d) = %d\n", root->key, root->lchild->key, root->rchild->key, root->color);
    output(root->lchild);
    output(root->rchild);
    return ;
}


