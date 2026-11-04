#include <stdio.h>
using namespace std;
const int MaxSize = 10000;

typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *&s) {
    s = new SqStack;
    s->top = -1;
}

void DestroyStack(SqStack *&s) {
	delete s;
}

bool Push(SqStack *&s, char e) {
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, char &e){
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool StackEmpty(SqStack *&s) {
	return (s->top == -1);
}

int main() {
    SqStack *stack;
    InitStack(stack);
    return 0;
}
