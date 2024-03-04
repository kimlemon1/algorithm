#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType LinkedNode;
struct nodeType{
    int val;
    LinkedNode *next;
};

typedef struct stackType stack;
struct stackType{
    LinkedNode *first;
};

int top(stack *s, int defval){
    if (s->first!=NULL){
        return s->first->val;
    }
    return defval;
}

int pop(stack *s, int defval){
    if (s->first!=NULL){
        int ans=s->first->val;
        LinkedNode *remove = s->first;
        s->first = s->first->next;
        free(remove);
        return ans;
    }
    return defval;
}
void push(stack *s, int newval){
    LinkedNode *newnode = (LinkedNode*)malloc(sizeof(LinkedNode));
    newnode->val = newval;
    newnode->next = s->first;
    s->first=newnode;
}

int main(void){
    stack mystack = {NULL};

    push(&mystack, 10);
    printf("FIRST %d %d %d\n", top(&mystack,0), pop(&mystack, 0), top(&mystack,0));
}