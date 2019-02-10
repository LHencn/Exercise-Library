 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 * 两遍遍历
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head;
    int count = 0;
    while (p) { //计算链表长度
        p = p->next;
        count++;
    }
    struct ListNode ret;//虚拟节点
    ret.next = head;
    p = &ret;
    head = &ret;
    count = count - n + 1;//删除链表正着数第count位
    int flag = 1;
    while (p->next && flag != count) {//二次遍历查找节点
        p = p->next;
        flag++;
    }
    struct ListNode *temp = p->next;//删除该节点
    p->next = p->next->next;
    free(temp);
    return head->next;
}

/*
 * 一遍遍历采用顺序表操作
 */
typedef struct Vector {
    struct ListNode **data;
    int size, length;
}Vector;

Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->size = n;
    p->length = 0;
    p->data = (struct ListNode **)malloc(sizeof(struct ListNode*) * p->size);
    return p;
}

void expand(Vector *v) {
    struct ListNode **temp = v->data;
    v->size = 2 * v->size;
    v->data = (struct ListNode **)malloc(sizeof(struct ListNode*) * v->size);
    for (int i = 0; i < v->length; i++) {
        v->data[i] = temp[i];
    }
    free(temp);
}

int insert(Vector *v, int loc, struct ListNode *value) {
    if (loc < 0 || loc > v->length)
        return 0;
    if (v->length == v->size)
        expand(v);
    for (int i = v->length; i > loc; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[loc] = value;
    v->length++;
    return 1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    Vector *v = init(100);
    int count = -1;
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p = &ret;
    head = p;
    while (p) {
        insert(v, count + 1, p);
        p = p->next;
        count++;
    }
    count = count - n + 1;
    v->data[count - 1]->next = v->data[count]->next;
    free(v->data[count]);
    return head->next;
}

/*
 * 一遍遍历采用双指针
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p = &ret, *q = p;
    head = p;
    int count = 0;
    while (p) {
        if (count++ > n) {
            /*
             * p指针从开始节点count=0向后走，走到第n+1步即count值大于n时q指针开始向后走，始终保持pq间相隔n个节点
             * 当p=NULL时，q指针即指向倒数第n个节点
             */
            q = q->next;
        }
        p = p->next;
    }
    struct ListNode *temp = q->next;
    q->next = q->next->next;
    free(temp);
    return head->next;
}
