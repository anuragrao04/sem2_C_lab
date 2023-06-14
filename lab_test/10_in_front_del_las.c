#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

void display(node_t *head);
node_t *insert_front(node_t *head, int data);
void delete_last(node_t *head);

int main(int argc, char *argv[]) {
  int choice;
  node_t *head = NULL;
  do {
    printf("\n1. Insert At Front\n2. Delete At Last\n3. Display\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nEnter element: ");
      int element;
      scanf("%d", &element);
      head = insert_front(head, element);
      break;
    case 2:
      delete_last(head);
      break;
    case 3:
      display(head);
      break;
    }

  } while (choice <= 4);

  return EXIT_SUCCESS;
}

void display(node_t *head) {
  printf("\nElements: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

node_t *insert_front(node_t *head, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
  return head;
}

void delete_last(node_t *head) {
  while (head->next->next != NULL) {
    head = head->next;
  }
  printf("\nDeleting %d", head->next->data);
  free(head->next);
  head->next = NULL;
}
