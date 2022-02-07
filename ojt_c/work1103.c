#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element; //element 뒤에 오는 변수를 int형으로 선언(형 재정의)
typedef struct ListNode{ //구조체 선언
  element data;
  struct ListNode *link;  //포인터 선언
}ListNode;

void print_list(ListNode* head){
  ListNode* p;
  
  if(head == NULL) return;

  p = head->link; //구조체 포인터 선언
  do{
    printf("%d->", p->data);
    p = p->link;
  }while(p != head);
  printf("%d->", p->data);
}

ListNode* insert_first(ListNode* head, element data){
  ListNode *node = (ListNode *)malloc(sizeof(ListNode)); //노드 생성, ListNode 크기만큼 메모리 할당
  node->data = data;
  if(head == NULL){
    head = node;
    node->link = head;
  }
  else{
    node->link = head->link;
    head->link = node;
  }
  return head;
}

ListNode* insert_last(ListNode* head, element data){
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));//노드 생성, ListNode 크기만큼 메모리 할당
  node->data = data;
  if(head == NULL){
    head = node;
    node->link = head;
  }
  else{
    node->link = head->link;
    head->link = node;
    head = node;
  }
  return head;
}

int main(void){
  ListNode *head = NULL;

  head = insert_last(head, 20); //리스트 맨 끝에 추가
  head = insert_last(head, 30);
  head = insert_last(head, 40);
  head = insert_first(head, 10);
  print_list(head);
  return 0;
}



typedef int element;
typedef struct DListNode{
  element data;
  struct DListNode* llink;
  struct DListNode* rlink;
}DListNode;

void init(DListNode* phead){
  phead->llink = phead;
  phead->rlink = phead;
}

void print_dlist(DListNode* phead){
  DListNode* p;
  for(p = phead->rlink; p != phead; p = p->rlink){
    printf("<-| |%d| |->", p->data);
  }
  printf("\n");
}

void dinsert(DListNode *before, element data){
  DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
  newnode->data = data;
  newnode->llink = before;
  newnode->rlink = before->rlink;
  before->rlink->llink = newnode;
  before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed){
  if(removed == head) return;
  removed->llink->rlink = removed->rlink;
  removed->rlink->llink = removed->llink;
  free(removed);
}

int main(void){
  DListNode* head = (DListNode *)malloc(sizeof(DListNode));
  init(head);
  printf("추가 단계\n");
  for (int i = 0; i < 5; i++){
    dinsert(head, i);
    print_dlist(head);
  }
  printf("\n삭제 단계\n");
  for (int i = 0; i < 5; i++){
    print_dlist(head);
    ddelete(head, head->rlink);
  }
  free(head);
  return 0;
}



typedef int element;
typedef struct StackNode{
  element data;
  struct StackNode *link;  
}StackNode;

typedef struct{
  StackNode *top;
}LinkedStackType;

void init(LinkedStackType *s){ //초기
  s->top = NULL;
}

int is_empty(LinkedStackType *s){ //비어있을 경우
  return (s->top == NULL);
}

int is_full(LinkedStackType *s){ //가득 차 있을 경우
  return 0;
}

void push(LinkedStackType *s, element item){ //스택 push
  StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
  temp->data = item;
  temp->link = s->top;
  s->top = temp;
}

void print_stack(LinkedStackType *s){ //스택 출력
  for (StackNode *p = s->top; p != NULL; p = p->link)
    printf("%d->", p->data);
  printf("NULL \n");
}

element pop(LinkedStackType *s){ //스택 pop
  if(is_empty(s)){
    fprintf(stderr, "스택이 비어있음\n");
    exit(1);
  }
  else{
    StackNode *temp = s->top;
    int data = temp->data;
    s->top = s->top->link;
    free(temp);
    return data;
  }
}

element peek(LinkedStackType *s){ //스택 항목 확인
  if(is_empty(s)){
    fprintf(stderr, "스택이 비어있음\n");
    exit(1);
  }
  else{
    return s->top->data;
  }
}

int main(void){
  LinkedStackType s;
  init(&s);
  push(&s, 1); print_stack(&s);
  push(&s, 2); print_stack(&s);
  push(&s, 3); print_stack(&s);
  pop(&s); print_stack(&s);
  pop(&s); print_stack(&s);
  pop(&s); print_stack(&s);
  return 0;
}