#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// 다른 자료형이면 이 부분을 수정하자
typedef int element;

typedef struct
{
  element data[SIZE];
  int rear, front;
} QueueType;

void init(QueueType *Q)
{
  Q->rear = Q->front = -1;
}


int is_empty(QueueType *Q)
{
  return Q->front == Q->rear;
}

int is_full(QueueType *Q)
{
  return Q->rear == SIZE - 1;
}

void enqueue(QueueType *Q, element e)
{
  if (is_full(Q))
    printf("Overflow\n");
  else
  {
    Q->rear++;

    Q->data[Q->rear] = e;
  }
}

element dequeue(QueueType *Q)
{
  if (is_empty(Q))
  {
    printf("Empty\n");
    return 0;
  }
  else
  {
    Q->front++;
    return Q->data[Q->front];
  }
}

void print(QueueType *Q)
{
  printf("Front Pos : %d\n, Rear Pos : %d\n", Q->front, Q->rear);
  for (int i = Q->front + 1; i <= Q->rear; i++)
  {
    // printf 안에 자료형 주의!
    printf("[%d] ", Q->data[i]);
  }
  printf("\n");
}

int main(){

    QueueType* queue = (QueueType*)malloc(sizeof(QueueType));
    // 초기화
    init(queue);

    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    print(queue);
    
    // 뽑을 때 뽑는 값 리턴
    int a = dequeue(queue);
    print(queue);

    int empty = is_empty(queue);
    int full = is_full(queue);

    // 동적할당 없이 쓸 때는 항상 주소 넣기 주의
    QueueType Q;
    init(&Q);
    
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    print(&Q);
    printf("[%c] \n", dequeue(&Q));
    return 0;
}