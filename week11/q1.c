#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
  struct node *next;
} NODE;

NODE *orderedSLL(NODE *head, int ele);
void display(NODE *head);
int sumAlternate(NODE *head);
int sumEvenData(NODE *head);
int sumOddData(NODE *head);
NODE *freeList(NODE *head);

int main() {
  NODE *head = NULL;
  int n;
  int ele;
  int sum;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ele);
    head = orderedSLL(head, ele);
  }
  display(head);
  printf("\n");
  sum = sumAlternate(head);
  printf("%d\n", sum);
  sum = sumEvenData(head);
  printf("%d\n", sum);
  sum = sumOddData(head);
  printf("%d\n", sum);

  head = freeList(head);
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
  while (head != NULL) {
    printf("%d ", head->info);
    head = head->next;
  }
}

int sumAlternate(NODE *head) {
  int sum = 0;
  int count = 0;
  while (head != NULL) {
    if (count % 2 == 0) {
      sum += head->info;
    }
    count++;
    head = head->next;
  }

  return sum;
}

int sumEvenData(NODE *head) {
  int sum = 0;
  while (head != NULL) {
    if (head->info % 2 == 0) {
      sum += head->info;
    }
    head = head->next;
  }
  return sum;
}

int sumOddData(NODE *head) {
  int sum = 0;
  while (head != NULL) {
    if (head->info % 2 != 0) {
      sum += head->info;
    }
    head = head->next;
  }
  return sum;
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
