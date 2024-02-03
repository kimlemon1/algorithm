#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int val;
    struct NODE* next;
}node;

typedef struct SLLIST{
    int count;
    struct NODE* head;
}sllist;

// 초기화
void Node_Init(node* head) {
    head->val = 0;
    head->next = NULL;
}
void SSList_Init(sllist* list, node* head){
    list->count = 0;
    list->head = head;
}


void add(sllist* list, int idx, int val){
    if (idx > list->count){
        printf("Index out of range in add");
    }
    else{
        node* new_node = (node*)malloc(sizeof(node));
        Node_Init(new_node);
        new_node->val = val;
        node* cur = list->head;
        node* before;
        int cur_idx= 0;
        while (cur_idx < idx){
            before = cur;
            cur = cur->next;
            cur_idx++;
        }
        before->next = cur->next;
    }
}

int search(sllist* list, int val){
    int idx = -1;

    node* cur = list->head;
    int cur_idx = 0;
    while(cur != NULL){
        if (cur->val == val){
            idx = ++cur_idx;
            break;
        }
        else{
            cur = cur->next;
            cur_idx++;
        }

    }
    return idx;
}


int main(){
    node a, b, c, d;
    a.val = 0;
    b.val = 1;
    c.val = 2;
    d.val = 3;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    
    sllist list;
    SSList_Init(&list, &a);
    

}