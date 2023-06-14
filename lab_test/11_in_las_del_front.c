#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

void display(node_t *head);
void insert_last(node_t *head, int data);
node_t *delete_front(node_t *head);

int main(int argc, char *argv[]) {
  int choice;

  node_t *head = malloc(sizeof(node_t));
  head->data = 1;
  head->next = NULL; // pre-existing data for insert last
  do {
    printf("\n1. Insert At Last\n2. Delete At Front\n3. Display\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nEnter element: ");
      int element;
      scanf("%d", &element);
      insert_last(head, element);
      break;
    case 2:
      head = delete_front(head);
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

void insert_last(node_t *head, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  while (head->next != NULL) {
    head = head->next;
  }
  head->next = new_node;
  new_node->data = data;
  new_node->next = NULL;
}

node_t *delete_front(node_t *head) {
  printf("\nDeleting %d", head->data);
  node_t *p = head;
  p = head->next;
  free(head);
  return p;
}
