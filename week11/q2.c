#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
  struct node *next;
} NODE;

NODE *orderedSLL(NODE *head, int ele);
void display(NODE *head);
NODE *merge(NODE *head1, NODE *head2, NODE *head3);
NODE *freeList(NODE *head);

int main() {
  NODE *head1 = NULL, *head2 = NULL, *head3 = NULL;
  int n1, n2, ele;

  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    scanf("%d", &ele);
    head1 = orderedSLL(head1, ele);
  }

  scanf("%d", &n2);
  for (int i = 0; i < n2; i++) {
    scanf("%d", &ele);
    head2 = orderedSLL(head2, ele);
  }

  display(head1);
  printf("\n");
  display(head2);
  printf("\n");
  head3 = merge(head1, head2, head3);
  display(head3);
  printf("\n");

  head1 = freeList(head1);
  head2 = freeList(head2);
  head3 = freeList(head3);
}

NODE *orderedSLL(NODE *head, int ele) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->info = ele;
  newNode->next = NULL;

  if (head == NULL || head->info >= ele) {
    newNode->next = head;
    head = newNode;
  } else {
    NODE *current = head;
    while (current->next != NULL && current->next->info < ele) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
  return head;
}

void display(NODE *head) {
  if (head == NULL) {
    printf("Empty List");
  } else {
    while (head != NULL) {
      printf("%d ", head->info);
      head = head->next;
    }
  }
}

NODE *freeList(NODE *head) {
  NODE *temp;
  while (head != NULL) {
    temp = head->next;
    free(head);
    head = temp;
  }
  return NULL;
}

NODE *merge(NODE *head1, NODE *head2, NODE *head3) {
  while (head1 != NULL) {
    head3 = orderedSLL(head3, head1->info);
    head1 = head1->next;
  }
  while (head2 != NULL) {
    head3 = orderedSLL(head3, head2->info);
    head2 = head2->next;
  }

  return head3;
}
