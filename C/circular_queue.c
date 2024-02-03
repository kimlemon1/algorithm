#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int element;

typedef struct
{
  element data[SIZE];
  int rear, front;
} QueueType;

void init(QueueType *Q)
{
  Q->rear = Q->front = 0;
}

int is_empty(QueueType *Q)
{
  return Q->front == Q->rear;
}

int is_full(QueueType *Q)
{
  return Q->front == (Q->rear + 1) % SIZE;
}

void enqueue(QueueType *Q, element e)
{
  if (is_full(Q))
    printf("Overflow\n");
  else
  {
    Q->rear = (Q->rear + 1) % SIZE;

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
    Q->front = (Q->front + 1) % SIZE;
    return Q->data[Q->front];
  }
}

element peek(QueueType *Q)
{
  if (is_empty(Q))
  {
    printf("Empty\n");
    return 0;
  }
  return Q->data[(Q->front + 1) % SIZE];
}

void print(QueueType *Q)
{
  printf("Front Pos : %d\n, Rear Pos : %d\n", Q->front, Q->rear);
  int i = Q->front; // 제일 앞에있는 원소 바로 하나 전부터 시작
  while (i != Q->rear)
  {
    i = (i + 1) % SIZE;
    printf("[%d]", Q->data[i]);
  }
  printf("\n");
}

int main()
{
  // 동적할당 안할 때 주의
  QueueType Q;
  init(&Q);
  
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  print(&Q);
  printf("[%c] \n", dequeue(&Q));
}