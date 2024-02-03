#include <stdio.h>
#define SIZE 100

typedef int element; // 배열안에 들어오는 값의 타입을 element로 한번에 지정

typedef struct {
  element data[SIZE];
  int top; // Index 번호
} StackType;

// 초기화
void init(StackType *S)
{
  S -> top = -1; // 포인터 연산자로 top에 접근해서 -1로 초기화
}

// 에러 체크 함수
int is_full(StackType *S)
{
  return S->top == SIZE - 1;
}

int is_empty(StackType *S)
{
  return S->top == -1;
}

// 삽입
void push(StackType *S, element e)
{
  if (isFull(S))
    printf("Overflow\n");
  else
  {
    S->top++;              // top을 하나 증가시킨후
    S->data[S->top] = e;   // 데이터를 삽입한다
  }
}

// 삭제
element pop(StackType *S)
{
  if (is_empty(S))
  {
    printf("Empty\n");
    return -1;
  }
  else
  {
    element e = S->data[S->top]; // 가장 상위에 있는 데이터를 e에 저장한 후
    S->top--;                    // top을 하나 감소시킨다
    return e;
  }
}

// 조회
element peek(StackType *S)
{
  if (is_empty(S))
  {
    printf("Empty\n");
    return -1;
  }
  else
  {
    return S->data[S->top];
  }
}

void print(StackType *S)
{
  for (int i = 0; i <= S->top; i++)
  {
    printf("%c ", S->data[i]);
  }
  printf("\n");
}

int main()
{
  StackType S;
  init(&S);

  pop(&S);
  push(&S, 'a');
  push(&S, 'b');
  push(&S, 'c');
  print(&S);

  element p = pop(&S);
  printf("%c\n", p);
  print(&S);
}