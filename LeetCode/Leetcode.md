#   						leetcode题解

#### 1、

##### 暴力枚举

```c
int* twoSum(int* nums, int numsSize, int target) {
    static int res[2] = {0}; //静态数组延长数组的生命周期
    for (int i = 0; i < numsSize; i++) {
        int a = nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (a + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                
            }
        }
    }
    return res;
}
```

注：因为如果不用静态的话，数组的生命周期就是从定义的地方到函数结束，函数运行结束，这个内存也就释放掉了。返回的是数组的首地址，一旦函数运行结束，这个地址里的东西就变成空了，所以要用静态数组延长数组的生命周期。

##### 两遍哈希表

方法：哈希表正是为此目的而构建的，它支持以 *近似* 恒定的时间进行快速查找。我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)。但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)。

一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（`target - nums[i]`）是否存在于表中。注意，该目标元素不能是 `nums[i]` 本身！

## 						链表

重点：常采用一个虚拟节点放在链表头处，即我们之前学过的头结点，虚拟结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部。

#### 					19、删除给定链表中的倒数第n个节点

1.两遍遍历

时间复杂度为O（L）空间复杂度为O（1），操作执行2L-n步，我们第一次遍历该链表可计算出该链表有length个节点，则这道题就是删除这个链表的第（length - n + 1）个节点。第二次遍历删除该节点就好啦。

2.一遍遍历

1. 时间复杂度为O（L），空间复杂度为O（L），操作执行L步，我们采用顺序表每个节点存储该链表的每个节点，操作执行到最后后，删除第（length-n+1）个节点。
2. 时间复杂度：O（L），空间复杂度O（1），操作执行L步，第一个指针从列表的开头向前移动 n+1 步，而第二个指针将从列表的开头出发。现在，这两个指针被 n 个结点分开。我们通过同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点。此时第二个指针将指向从最后一个结点数起的第 n 个结点。我们重新链接第二个指针所引用的结点的 `next` 指针指向该结点的下下个结点。

![](./picture/19-删除链表倒数第n个节点一次遍历.png)

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p = &ret, *q = p;
    head = p;
    int count = 0;
    while (p) {
        if (count++ > n) 
            q = q->next;
        p = p->next;
    }
    struct ListNode *temp = q->next;
    q->next = q->next->next;
    free(temp);
    return head->next;
}
```

#### 						24、交换链表中两两相邻的节点

将该链表加一个虚拟节点，循环进行两两交换。

![](./picture/24.png)

```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p = &ret;
    head = p;
    struct ListNode *temp;
    while (p->next  != NULL && p->next->next != NULL) {
        temp = p->next->next;
        p->next->next = temp->next;
        temp->next = p->next;
        p->next = temp;
        p = p->next->next;
    }
    return head->next;
}
```



#### 						83、删除链表中的重复项

两个节点为一组循环，比较该两节点值，若相等，则删除后一个节点然后继续循环比较，不等则将指针后移，继续循环比较。

```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p = head, *temp;
    while (p && p->next) {
        if (p->val == p->next->val) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        } else 
            p = p->next;
    }
    return head;
}
```



#### 						141、环型链表

![](./picture/141环型链表.png)

1. 如何判断一个链表中有环？

   1. 链表第一个节点成环：此时所有节点入度均为1，出度均为1
   2. 链表第一个节点不成环：此时有一个节点入度为2

2. 哈希表：遍历链表，将每个节点地址引用放到哈希表中，若某次该节点地址出现在哈希表中，则有环，若链表中出现空节点，则到链表尾部，没环啦！！！

   1. 时间复杂度：O(n)， 对于含有 n 个元素的链表，我们访问每个元素最多一次。添加一个结点到哈希表中只需要花费 O(1) 的时间。
   2. 空间复杂度：O(n)， 空间取决于添加到哈希表中的元素数目，最多可以添加 n 个元素。 

3. 采用快慢指针：通过使用具有 **不同速度** 的快、慢两个指针遍历链表，空间复杂度可以被降低至 O（1）。慢指针每次移动一步，而快指针每次移动两步。如果列表中不存在环，最终快指针将会最先到达尾部，即快指针为NULL，此时我们可以返回 `false`。若某次快慢指针相等，则表明两指针指向同一区域，重合，有环啦！！

   1. 时间复杂度：O(n)， 让我们将 n 设为链表中结点的总数。为了分析时间复杂度，我们分别考虑下面两种情况。

      - **\*链表中不存在环：***
        快指针将会首先到达尾部，其时间取决于列表的长度，也就是 O(n)。
      - **\*链表中存在环：***
        我们将慢指针的移动过程划分为两个阶段：非环部分与环形部分：
        1. 慢指针在走完非环部分阶段后将进入环形部分：此时，快指针已经进入环中 \text{迭代次数} = \text{非环部分长度} = N迭代次数=非环部分长度=N
        2. 两个指针都在环形区域中：考虑两个在环形赛道上的运动员 - 快跑者每次移动两步而慢跑者每次只移动一步。其速度的差值为1，因此需要经过{二者之间距离}/{速度差值}}速度差值二者之间距离 次循环后，快跑者可以追上慢跑者。这个距离几乎就是 "\text{环形部分长度 K}环形部分长度 K" 且速度差值为 1，我们得出这样的结论 \text{迭代次数} = \text{近似于}迭代次数=近似于 "\text{环形部分长度 K}环形部分长度 K".

      因此，在最糟糕的情形下，时间复杂度为 O(N+K)O(N+K)，也就是 O(n)O(n)。

   2. 空间复杂度：O(1)O(1)， 我们只使用了慢指针和快指针两个结点，所以空间复杂度为 O(1)O(1)。

```c
 //采用快慢指针
bool hasCycle(struct ListNode *head) {
   if(head == NULL) return false;
    struct ListNode *p = head, *q = head->next;
    while (q && q->next) {
        p = p->next;//慢指针
        q = q->next->next;//快指针
        if (p == q) return true;
    }
    return false;
}
//顺序表
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

bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head;
    Vector *v = init(10);
    while (p) {
        for (int i = 0; i < v->length; i++) {
            if (p == v->data[i]) 
                return true;
        }
        insert(v, 0, p);
        p = p->next;
    }
    return false;
}
```



#### 						160、寻找两链表相交节点

1. 采用类似于140题**成环快慢指针**做法，定义两个指针分别进行链表遍历，若到链表尾部则转到另一个链表开头继续遍历，直至两指针相等或都等于NULL，此时即为结果。时间复杂度O（n）

2. 采用两遍循环，循环每个节点，判断另一个链表中的节点是否有和其地址相同，时间复杂度O（n^2)

   ```c
   struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
       if(headA == NULL || headB == NULL) return NULL;
       struct ListNode *pA = headA, *pB = headB;
       while(pA != pB) {
               pA = pA == NULL ? headB : pA->next;
               pB = pB == NULL ? headA : pB->next;
       }
       return pA;
   }
   ```

   3.如果两个链表有公共结点，则从这个结点向后，都是两个链表所共有的结点。我们可以计算一下两个链表的结点数量差，让结点个数更多的链表先向后遍历，直到两个链表的剩余未遍历结点个数相等。此时，两个链表同时向后遍历，如果发现遍历到同一个结点则说明这两个链表交叉，否则未交叉。时间复杂度为O（n+m）；

   4.将其中一个链表首尾相接，从另一个链表的表头开始遍历，判断是否有环(判断是否有环可以通过 Hash 等方法实现)，如果有环则说明两链表交叉。时间复杂度为 O(n+m);

#### 202、寻找快乐数

题目：一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

解题：所有不快乐数的数位平方和计算，最後都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中。

1.n出现重复值就一定是循环的，2.可以根据n值的特征，比如出现某个值就一定是循环的。

```c
bool isHappy(int n) {
     int temp=0;
        while(n!=1)
        {
            while(n>0)
            {
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n=temp;
            temp=0;
            if(n==4) return 0; 
        }
       return 1; 
}
```



![](./picture/202、快乐数.jpg)

#### 						203、移除链表中给定元素

题目：删除链表中等于给定值 **val** 的所有节点。

**示例:**

```
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

解题：加一个虚拟节点，双指针遍历链表。

```c

```



#### 						206、反转链表

题目：反转一个单链表。

**示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

**进阶:**
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

题解：采用三个指针将链表中两两节点进行反转。

```c
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return ;
    struct ListNode *p = head->next, *q = head, *temp;
    q->next = NULL;
    while (p->next) {
        temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    p->next = q;
    return p;
}
```



#### 						234、回文链表		

题目：请判断一个链表是否为回文链表。

**示例 1:**

```
输入: 1->2
输出: false
```

**示例 2:**

```
输入: 1->2->2->1
输出: true
```

**进阶：**
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

题解：

1. 采用快慢指针找到链表中点
2. 将链表中点next指针指向空，将链表反转
3. 链表左右分别开始向中点遍历，判断是否相等

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast = head, *slow = head, *temp = NULL;
    while (fast) {//快慢指针找到链表中点
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    while (slow) {//反转链表
        fast = slow->next;
        slow->next = temp;
        temp = slow;
        slow = fast;
    }
    fast = head;
    slow = temp;
    while (fast && slow) {//左右遍历
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
```





#### 					237、删除链表中非末尾节点

题目：请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png)

 

**示例 1:**

```
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
```

题解：因为我们无法访问我们想要删除的节点*之前*的节点，我们始终不能修改该节点的 `next` 指针。相反，我们必须将想要删除的节点的值替换为它后面节点中的值，然后删除它之后的节点。

```c
void deleteNode(struct ListNode* node) {//node->next节点给node节点赋值,然后删除node->next节点
    node->val = node->next->val;
    struct ListNode *p = node->next;
    node->next = p->next;
    free(p);
}
```

## 栈和队列

#### 20、有效的括号

题目：给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:

```
输入: "()"
输出: true
```

示例 2:

```
输入: "()[]{}"
输出: true
```

示例 3:

```
输入: "(]"
输出: false
```

**题解：**

1. 初始化栈 S。
2. 一次处理表达式的每个括号。
3. 如果遇到开括号，我们只需将其推到栈上即可。这意味着我们将稍后处理它，让我们简单地转到前面的 **子表达式**。
4. 如果我们遇到一个闭括号，那么我们检查栈顶的元素。如果栈顶的元素是一个 `相同类型的` 左括号，那么我们将它从栈中弹出并继续处理。否则，这意味着表达式无效。
5. 如果到最后我们剩下的栈中仍然有元素，那么这意味着表达式无效。

复杂度：

1. 时间复杂度：O(n)O(n)，因为我们一次只遍历给定的字符串中的一个字符并在栈上进行 O(1)O(1) 的推入和弹出操作。
2. 空间复杂度：O(n)O(n)，当我们将所有的开括号都推到栈上时以及在最糟糕的情况下，我们最终要把所有括号推到栈上。例如 `((((((((((`。

#### 232、用栈实现队列

思路：采用两个栈实现逻辑上的队列

s

#### 225、用队列实现栈





## 二叉树

#### 100、相同的树

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

**示例 1:**

```
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
```

题解：

```c
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) 
        return true;
    if (p && q && p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
}
```

#### 101、对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:

```
    1
   / \
  2   2
   \   \
   3    3
```

**说明:**

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

题解：

**方法：递归**

如果一个树的左子树与右子树镜像对称，那么这个树是对称的。

![Push an element in stack](https://leetcode-cn.com/media/original_images/101_Symmetric.png)

因此，该问题可以转化为：两个树在什么情况下互为镜像？

如果同时满足下面的条件，两个树互为镜像：

1. 它们的两个根结点具有相同的值。
2. 每个树的右子树都与另一个树的左子树镜像对称。

![Push an element in stack](https://leetcode-cn.com/media/original_images/101_Symmetric_Mirror.png)

就像人站在镜子前审视自己那样。镜中的反射与现实中的人具有相同的头部，但反射的右臂对应于人的左臂，反之亦然。

```c
//递归
bool isMirror(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) 
        && isMirror(t1->left, t2->right);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
    
}
```

- 时间复杂度：O(n)。因为我们遍历整个输入树一次，所以总的运行时间为 O(n)，其中 nn 是树中结点的总数。
- 空间复杂度：递归调用的次数受树的高度限制。在最糟糕的情况下，树是线性的，其高度为 O(n)。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为 O(n)。

**？迭代：**

```c
//迭代、一层一层比较

```

#### 102、二叉树的层次遍历

 

