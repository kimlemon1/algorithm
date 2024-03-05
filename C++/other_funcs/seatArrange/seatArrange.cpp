#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class node{
    private:
        int val;
        node* left;
        node* right;
        bool sit;
    public:
        node(int aval);
        ~node();
        int getval();
        bool sitted();
        void sitdown();

        void link_left(int aval);
        void link_right(int aval);
        node* getleft();
        node* getright();
};


class BinaryTree{
    private:
        int count; // N개 추가 하면 중단, recursive 확인용
        node* root;

    public:
        BinaryTree(int N);
        ~BinaryTree(){delete root;}

        void recur_help(node* cur_node, int N);
        int Search(const int& a);
};


int seatArrange(int N, int Q, vector<int>& queue) {
    //N: number of seats in GSDS
    //Q: number of students
    //queue: desired seat for each student in a row

    /* Your code here */
    BinaryTree tree(N);
    for(int i : queue){
        cout<< tree.Search(i) << ' ';
    }
    cout << endl;
    return 0;
}

/* Do not modify below */
int main(){
    int N1 = 6;          
    int Q1 = 4;             
    vector<int> queue1 = {3, 5, 6, 2};
    seatArrange(N1, Q1, queue1);

    int N2 = 10;
    int Q2 = 5;
    vector<int> queue2 = {2, 8, 6, 7, 10};
    seatArrange(N2, Q2, queue2);

    int N3 = 13;
    int Q3 = 7;
    vector<int> queue3 = {8, 7, 6, 9, 10, 12, 13};
    seatArrange(N3, Q3, queue3);

    int N4 = 8;
    int Q4 = 4;
    vector<int> queue4 = {1, 2, 3, 4};
    seatArrange(N4, Q4, queue4);
}


// Node body
node::node(int aval){
    val = aval;
    left = nullptr;
    right = nullptr;
    sit = false;
}

node::~node(){
    delete left;
    delete right;
}

int node::getval() {return val;}
bool node::sitted() {return sit;}
void node::sitdown() {sit = true;}

void node::link_left(int aval) { // new_node delete안해도 된다, 왜냐햐면 left, right에서 연결됨 => 동일한 메모리공간 가리키기 때문에 결국 비워진다. 맞나?
    node* new_node = new node(aval);
    left = new_node;
}
void node::link_right(int aval) {
    node* new_node = new node(aval);
    right = new_node;
}
node* node::getleft(){return left;}
node* node::getright(){return right;}

// Tree body

BinaryTree::BinaryTree(int N){
    // make tree
    root = new node(1);
    recur_help(root, N); 
}

void BinaryTree::recur_help(node* cur_node, int N){
            if (cur_node != nullptr){
                // end of recursion, do nothing
                int cur_val = cur_node->getval();
                if (cur_val * 2 + 1 <= N){
                    cur_node->link_right(cur_val*2 +1);
                    cur_node ->link_left(cur_val*2);
                }
                else if (cur_val *2  == N){
                    cur_node ->link_left(cur_val*2);
                }
                recur_help(cur_node->getleft(), N);
                recur_help(cur_node->getright(), N);
            }
        }

int BinaryTree::Search(const int& a){
    // 어느 leaf로 갈지 방향 저장용 stack
    deque<int> leaf_direction;
    int cur = a; // 거꾸로 간다 : 2로 나누면서 나머지 저장 

    // 거꾸로 갈 방향 저장
    while (cur != 1){ // cur == 1: root에 도달
        leaf_direction.push_front(cur % 2);
        cur = cur / 2;
    }


    // root 부터 저장된 값 따라 방향으로 이동 + 리턴
    int length = leaf_direction.size();
    node* cur_node = root;

    for (int i = 0; i<length; ++i){
        // 가는 중 앉아있으면 해당 값 리턴, 종료
        if (cur_node->sitted()){return cur_node->getval();}

        int direction = leaf_direction.front();
        leaf_direction.pop_front();

        if (direction == 0){
            cur_node = cur_node->getleft();
        }
        else{
            cur_node = cur_node->getright();
        }
    }
    // 중간에 않은 좌석이 없다면 
    cur_node->sitdown(); // 목표한 좌석 앉기, 좌석 번호 리턴
    return cur_node->getval();
}