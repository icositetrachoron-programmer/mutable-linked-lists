#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H
#ifndef _STDLIB_H
#include <stdlib.h>
#endif

typedef struct node {
  int value;
  struct node* next;
} node;
node* newNode(void) {
  return (node*) malloc(sizeof(node));
}
void addNode(node* head) {
  node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode();
}
int length(node* head) {
  node* current = head;
  int count = 1;
  while (current->next != NULL) {
    ++count;
    current = current->next;
  }
  return count;
}
node* atIndex(node* head, int index) {
  int pos = 0;
  node* current = head;
  while (pos != index) {
    if (current->next == NULL) {
      exit(EXIT_FAILURE);
    } else {
      current = current->next;
      ++pos;
    }
  }
  return current;
}
void setValue(node* head, int index, int value) {
  atIndex(head, index)->value = value;
}
void push(node* head, int value) {
  addNode(head);
  setValue(head, length(head) - 1, value);
}
#endif
