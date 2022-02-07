#include <stdio.h>#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {
element data;
struct StackNode *link;
} StackNode;

typedef struct {
StackNode *top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType *s)
{
s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
return 0;
}
// 삽입 함수
void push(LinkedStackType *s, element item)
{
StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
temp->data = item;
temp->link = s->top;
s->top = temp;
}
void print_stack(LinkedStackType *s)
{
for (StackNode *p = s->top; p != NULL; p = p->link)
printf("%d->", p->data);
printf("NULL \n");
}

// 삭제 함수
element pop(LinkedStackType *s)
{
if (is_empty(s)) {
fprintf(stderr, "스택이 비어있음\n");
exit(1);
}
else {
StackNode *temp = s->top;
int data = temp->data;
s->top = s->top->link;
free(temp);
return data;
}
}
// 주 함수
int main(void)
{
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

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 // 새로운 루트 노드를 반환한다.
TreeNode * delete_node(TreeNode * root, int key)
{
    if (root == NULL) return root;
    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임 if (key < root->key)
    root->left = delete_node(root->left, key);
    // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임 else if (key > root->key)
    root->right = delete_node(root->right, key); // 키가 루트와 같으면 이 노드를 삭제하면 됨

    else {
    }
    return root;
    // 첫 번째나 두 번째 경우 if (root->left == NULL) {
    TreeNode * temp = root->right; free(root);
    return temp;
    }
    else if (root->right == NULL) {
    TreeNode * temp = root->left; free(root);
    return temp;
    }
// 세 번째 경우
    TreeNode * temp = min_value_node(root->right);
    // 중외 순회시 후계 노드를 복사한다.
    root->key = temp->key;
    // 중외 순회시 후계 노드를 삭제한다.
    root->right = delete_node(root->right, temp->key);
    }
return root;
}