#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
  struct node *next;
} NODE;

NODE *orderedSLL(NODE *head, int ele);
void display(NODE *head);
NODE *cocatenate(NODE *head1, NODE *head2);
NODE *freeList(NODE *head);

int main() {
  NODE *head1 = NULL, *head2 = NULL;
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
  head1 = cocatenate(head1, head2);
  display(head1);
  printf("\n");

  head1 = freeList(head1);
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

NODE *cocatenate(NODE *head1, NODE *head2) {
  if (head1 == NULL) {
    return head2;
  }
  if (head2 == NULL) {
    return head1;
  }

  NODE *current = head1;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = head2;

  return head1;
}
