# include <stdio.h>
using namespace std;

// 链式存储结构
typedef struct node {
	char data; // ElemType data
	struct node *lchild;
	struct node *rchild;
} BTNode;


// 递归算法

// 先序遍历
void PreOrder(BTNode *b){
    if (b != NULL) {
        printf("%c", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}


// 中序遍历
void InOrder(BTNode *b){
    if (b != NULL) {
        PreOrder(b->lchild);
        printf("%c", b->data);
        PreOrder(b->rchild);
    }
}


// 后序遍历
void PostOrder(BTNode *b){
    if (b != NULL) {
        PreOrder(b->lchild);
        PreOrder(b->rchild);
        printf("%c", b->data);
    }
}



// 栈实现
const int MaxSize = 10000;
typedef struct {
    BTNode *data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *&s) {
    s = new SqStack;
    s->top = -1;
}

void DestroyStack(SqStack *&s) {
	delete s;
}

bool Push(SqStack *&s, BTNode *e) {
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, BTNode *e){
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool StackEmpty(SqStack *&s) {
	return (s->top == -1);
}

// 非递归算法
// 先序遍历法1
/*
将根结点b进栈:
while (栈不空) {
    出栈结点p并访问之;
    若 p 结点有右孩子,将其右孩子进栈;
    若 p 结点有左孩子,将其左孩子进栈;
}
*/
void PreOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;
    InitStack(st);
    if (b != NULL) {
        Push(st, b);
        while (!StackEmpty(st)) {
            Pop(st, p);
            printf("%c", p->data);
            if (p->rchild != NULL) Push(st, p->rchild);
            if (p->lchild != NULL) Push(st, p->lchild);
        }
        printf("\n");
    }
    DestroyStack(st);
}


// 先序遍历法2
/*
p=b;
while（栈不空或者p!一NULL) {
   while（结点p有左孩子）{   //对于结点p及其所有的左下结点，边访问边进栈
    访问结点p;将其进栈；
    p-p->lchild;
    }
    //此时栈顶结点（已访问)没有左孩子，或者左子树已遍历过
    if(栈不空）{
    出栈 p;
    p=p-> rchild;
    }
}
*/
void PreOrder2(BTNode *b) {
    BTNode *p;
    SqStack *st;
    InitStack(st);
    p = b;
    while (!StackEmpty(st) || p != NULL) {
        while (p != NULL) {
            printf("%c", p->data);
            Push(st, p);
            p = p->lchild;
        }
        if (!StackEmpty(st)) {
            Pop(st, p);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(st);
}


// 中序遍历
void InOrder(BTNode *b) {
    BTNode *p;
    SqStack *st;
    InitStack(st);
    p = b;
    while (!StackEmpty(st) || p != NULL) {
        while (p != NULL) {
            Push(st, p);
            p = p->lchild;
        }
        if (!StackEmpty(st)) {
            Pop(st, p);
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(st);
}


// 后序遍历
/*
p=b;
do {
    while(结点p有左孩子) {
    将结点 p 进栈;
    p=p→>lchild;
    }
    //此时栈顶结点(尚未访问)没有左孩子或左子树已遍历过
    while(栈不空且结点p是栈顶结点) {
        取栈顶结点 p;
        if(结点p的右子树已访问) {
            访问结点 p;
            退栈;
        }
        else p=p->rchild;
    }
}while (栈不空);
*/
void PostOrder(BTNode *b) {
    BTNode *p, *r;
    bool flag;
    SqStack *st;
    InitStack(st);
    p = b;
    do {
        while (p != NULL) {
            Push(st, p);
            p = p->lchild;
        }
        r = NULL;
        flag = true;
        while (!StackEmpty(st) && flag) {
            GetTop(st, p); // GetTop还未定义！！
            
        }
    }
}




int main() {
    return 0;
}