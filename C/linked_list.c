#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next_node; // 아직 typedef 선언 전이라서 full name 필수
} Node;

typedef struct LinkedList{
    int len;
    Node *root;
} LL;


void push_back(LL* ll,const int val);
void insert(LL* ll, const int idx, const int val);
void delete(LL *ll, const int idx);
void traverse(LL *ll);
Node* make_node(const int val);
void initialize_LL(LL *new_ll);
void delete_all(LL *ll);
void reverselist(LL *L);

int main(){
    LL *ll = (LL*)malloc(sizeof(LL));
    initialize_LL(ll);

    push_back(ll, 0);
    push_back(ll, 1);
    push_back(ll, 2);
    push_back(ll, 3);

    insert(ll, 4, 99);
    traverse(ll);
    reverselist(ll);
    traverse(ll);
    delete_all(ll);
    insert(ll,0,100);
    traverse(ll);
    

    return 0;
}



void push_back(LL* ll,const int val){
    // linked list root를 받으면 맨 마지막에 더하기
    Node* new_node = make_node(val);
    if (ll->len == 0){
        ll->root = new_node;
    }
    else{
        Node* cur_node = ll->root;
        while (cur_node->next_node != NULL){
            cur_node = cur_node->next_node;
        }
        cur_node->next_node = new_node;
    }
    ll->len++;

}

void insert(LL* ll, const int idx, const int val){
    if (idx > ll->len) {
        printf("Error : Index out of range when insert\n");
        return;
    }
    Node* new_node = make_node(val);
    if (idx == 0){
        new_node->next_node = ll->root;
        ll->root = new_node;
    }
    else{
        Node* cur = ll->root;
        for (int i =0;i<idx-1;i++){
            cur = cur->next_node;
        }
        new_node->next_node = cur->next_node;
        cur->next_node = new_node;
    }
    ll->len++;
}

void delete(LL *ll, const int idx){
    if (ll->len <= idx){
        printf("Error : Index out of range when delete\n");
        return;
    }
    Node* remove;
    if (idx == 0){
        remove = ll->root;
        ll->root = ll->root->next_node;
    }
    else{
        Node* cur = ll->root;

        for (int i =0; i< idx-1;i++){
            cur = cur->next_node;
        }
        remove = cur->next_node;
        cur->next_node = cur->next_node->next_node;
    }
    free(remove);
    ll->len--;
}

void delete_all(LL *ll){
    Node* cur = ll->root;
    Node* before;
    while (cur != NULL){
        before = cur;
        cur = cur->next_node;
        free(before);
    }
    ll->root = NULL;
    ll->len = 0;
}

void traverse(LL *ll){
    Node* cur = ll->root;
    for (int i =0; i<ll->len;i++){
        printf("%d ", cur->val);
        cur = cur->next_node;
    }
    printf("\n");
}

Node* make_node(const int val){
    Node *root = (Node*)malloc(sizeof(Node));
    root ->val = val;
    root ->next_node = NULL;
    return root;
}

void reverselist(LL *L){
    Node *prev = NULL;
    Node *cur = L->root;
    Node *next = NULL;
    while (cur != NULL){
        next = cur->next_node;
        cur->next_node = prev;
        prev = cur;
        cur = next;
    }
    L->root = prev;
}

void initialize_LL(LL *new_ll){
    new_ll->len = 0;
    new_ll->root = NULL;
}

