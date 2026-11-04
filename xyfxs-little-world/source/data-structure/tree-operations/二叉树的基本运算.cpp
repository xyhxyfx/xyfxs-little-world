# include <stdio.h>
using namespace std;

/*
本篇中的char类型为该节点存储数据，可以替换成任意数据类型ElemType
*/

// 链式存储结构
typedef struct node {
	char data; // ElemType data
	struct node *lchild;
	struct node *rchild;
} BTNode;

// 创建二叉树 CreateBTree(*b, *str)
// 对于括号表达式输入“A(B(D(,G)),C(e,F))”
// 需要全局变量str输入
const int MaxSize = 10000;
void CreateBTree(BTNode *&b, char *str) {
	BTNode *St[MaxSize], *p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch(ch) {
			case '(': top++; St[top] = p; k = 1; break;
			case ')': top--; break;
			case ',': k = 2; break;
			default: p = new BTNode;
				p->data = ch;
				p->lchild=p->rchild=NULL;
				if (b == NULL) b = p;
				else {
					switch(k) {
						case 1:St[top]->lchild = p; break;
						case 2:St[top]->rchild = p; break;
					}
				}
		}
		j++;
		ch = str[j];
	}
}


// 销毁二叉树（递归）DestoryBTree(&b)
void DestoryBTree(BTNode *&b) {
	if (b != NULL) {
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		delete b;
	}
}


// 查找节点FindNode(*b, x)
BTNode *FindNode(BTNode *b, char x) {
	BTNode *p;
	if (b == NULL) return NULL;
	else if (b->data == x) return b;
	else {
		p = FindNode(b->lchild, x);
		if(p != NULL) return p;
		return FindNode(b->rchild, x);
	}
}


// 求高度BTHeight(*b)
int BTHeight(BTNode *b) {
	int lchild_h, rchild_h;
	if (b == NULL) return 0;
	else {
		lchild_h = BTHeight(b->lchild);
		rchild_h = BTHeight(b->rchild);
		return (lchild_h > rchild_h) ? (lchild_h+1) : (rchild_h+1);
	}
}


// 输出二叉树DisBTree(*b)
// 按照括号表达式输出“A(B(D(,G)),C(e,F))”
void DisBTree(BTNode *b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DisBTree(b->lchild);
			if (b->rchild != NULL) printf(",");
			DisBTree(b->rchild);
			printf(")");
		}
	}
}

int main() {
	
	return 0;
}
