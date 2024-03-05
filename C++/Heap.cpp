#include <iostream>

// full binary tree : 자식 0 or 2개씩만 있는 tree, tree 모양은 제한 없다
// Perfect binary tree : 완벽 대칭 tree

// Complete binary tree : 좌 -> 우로 채워지는 tree 
// O(log(n))성립! Complete binary tree만드는 것이 중요하다

// Heap : array 형태 but complete binary tree처럼 생각 가능! : 인덱스를 left, rigth 마다 정해서 배정 가능


// Heap sort : Max heapify를 사용한 sort 방법 
// heap의 가장 마지막과 시작을 바꾸고 maxheapify를 하면서 뒤에서부터 하나씩 제거해나간다
// idx[0]과 idx[-1]을 바꿈
// idx[-1]을 제거
// max heapify(0)
// heap이 빌 때까지 반복
// 제거된 값이 저장된 리스트가 sort 된 것이다.

// Priority Queues
// 1. Extract-Max
    // 가장 첫번째 인덱스 제거, 
    // 가장 마지막 값을 첫번째로 올리고 max heapify

// 2. Increase-key
    // key 값을 바꾸면 recursive하게 부모와 비교하면서 바꾸기 
    // Decrease는 자식과 비교

// 3. Insert
    // key를 가장 작게 주고 -1에 넣기
    // increase key로 원래 위치 찾기

// Priority Queues 장점 : 모든 작업 O(log(n))이 걸린다



class Heap {
    private:
        int *harr;
        int capacity;
        int heap_size;
    public:
        Heap(const int &acapacity){
            harr = new int[capacity];
            capacity = acapacity;
            heap_size = 0;
        }
        ~Heap(){
            delete[] harr;
        }
        void insertKey(const int &k);
        void max_heapify(const int &i);
        void min_heapify(const int &i);

        void build_max_heap();
        void build_min_heap();
        int parent_idx(const int &i){
            if (i == 0){
                std::cout << "Error : Root have no parent"<< std::endl;
                return 0;
                }
            else {
                return (i-1)/2;
                }
        }

        // index 0부터 시작 기준!
        int left_idx(const int &i){return 2*i+1;}
        int right_idx(const int &i){return 2*i +2;}

        void print_all(){
            for (int i =0; i < heap_size; i++){
                std::cout << harr[i] << ' ';
            }
            std::cout << std::endl;
        }
};

void Heap::insertKey(const int &k){
    if (this->capacity == this->heap_size){
        std::cout << "Heap is full\n" << std::endl;
    }
    else {
        harr[heap_size] = k;
        heap_size++;
    }
}

// void Heap::max_heapify(const int &i){ // O(log(n)) : linear to tree height
    
//     if ((left_idx(i) < this->capacity) && harr[i] < harr[this -> left_idx(i)]){
//         int temp = harr[i];
//         harr[i] = harr[this -> left_idx(i)];
//         harr[this -> left_idx(i)] = temp;
//         max_heapify(left_idx(i));
//     }
//     else if ((right_idx(i) < this->capacity) && harr[i] < harr[this -> right_idx(i)]){
//         int temp = harr[i];
//         harr[i] = harr[this -> right_idx(i)];
//         harr[this -> right_idx(i)] = temp;
//         max_heapify(right_idx(i));
        
//     }
// }


// max_heapify는 좌, 우 leaf중 최대값을 찾아서 바꾸는 것! 단순히 크다고 왼쪽 우선 바꾸는게 아니다! 따라서 최대 idx를 만들어서 인덱스만 따라가는 것이 효율적이다.
void Heap::max_heapify(const int &i){ // O(log(n)) : linear to tree height
    int max_idx = i;
    if ((left_idx(i) < this->capacity) && harr[max_idx] < harr[this -> left_idx(i)]){ // 첫번째 조건이 recursive base 조건을 만들어준다!
        max_idx = left_idx(i);
    }
    if ((right_idx(i) < this->capacity) && harr[max_idx] < harr[this -> right_idx(i)]){
        max_idx = right_idx(i);
    }

    if (max_idx != i){
        int temp = harr[i];
        harr[i] = harr[max_idx];
        harr[max_idx] = temp;
        max_heapify(max_idx);
    }
}

void Heap::min_heapify(const int &i){ // O(log(n)) : linear to tree height
    int min_idx = i;
    if ((left_idx(i) < this->capacity) && harr[min_idx] > harr[this -> left_idx(i)]){ // 첫번째 조건이 recursive base 조건을 만들어준다!
        min_idx = left_idx(i);
    }
    if ((right_idx(i) < this->capacity) && harr[min_idx] > harr[this -> right_idx(i)]){
        min_idx = right_idx(i);
    }

    if (min_idx != i){
        int temp = harr[i];
        harr[i] = harr[min_idx];
        harr[min_idx] = temp;
        max_heapify(min_idx);
    }
}

void Heap::build_min_heap(){ 
    // O(n * log(n)) but in specific, n -> n/2 왜냐하면 자식 노드는 걍 안해도 됨, 아래 node는 subtree 크기가 작음 => 결국 계산하면 O(n)이 된다
    // sorting이 O(nlog(n))이므로 훨씬 더 좋다!
    for (int i = (this->heap_size / 2) -1 ; i >= 0; i--){// only when internal node
        
        min_heapify(i);
        
    }
}
void Heap::build_max_heap(){ 
    // O(n * log(n)) but in specific, n -> n/2 왜냐하면 자식 노드는 걍 안해도 됨, 아래 node는 subtree 크기가 작음 => 결국 계산하면 O(n)이 된다
    // sorting이 O(nlog(n))이므로 훨씬 더 좋다!
    for (int i = (this->heap_size / 2) -1 ; i >= 0; i--){// only when internal node
        
        max_heapify(i);
        
    }
}


int main(){
    Heap heap(15);
    heap.insertKey(2);
    heap.insertKey(3);
    heap.insertKey(6);
    heap.insertKey(1);
    heap.insertKey(23);
    heap.insertKey(5);
    heap.insertKey(9);
    heap.insertKey(0);
    heap.insertKey(55);
    heap.insertKey(100);
    heap.insertKey(7);
    heap.insertKey(-3);
    heap.insertKey(-99);
    heap.insertKey(120);
    heap.insertKey(57);

    
    std::cout << "Before sorting" << std::endl;
    heap.print_all();


    // heap.max_heapify(4);
    // std::cout << "After max_heapify index 4 " << std::endl;
    // heap.print_all();

    heap.build_min_heap();
    //heap.max_heapify(0);
    std::cout << "After Max_heapified build" << std::endl;
    heap.print_all();

}