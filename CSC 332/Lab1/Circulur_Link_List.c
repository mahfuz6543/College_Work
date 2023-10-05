#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head_ref, int data) {
  if (head_ref != NULL) 
  return head_ref;

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data = data;
   head_ref = new_node;
   head_ref->next = head_ref;
  return head_ref;
}

struct Node* InsertAtFront(struct Node* head_ref, int data) {
  
  if (head_ref == NULL) 
  return insertAtBeginning(head_ref, data);
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = data;
new_node->next = head_ref->next;
head_ref->next = new_node;
  return head_ref;
}

struct Node* InsertAtLast(struct Node* head_ref, int data) {
  
  if (head_ref == NULL) 
  {
	return insertAtBeginning(head_ref, data);
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = data;
new_node->next = head_ref->next;
head_ref->next = new_node;
head_ref = new_node;
  return head_ref;
}

void Deletion(struct Node** head_ref, int key) {
  if (*head_ref == NULL)
   return;
  if ((*head_ref)->data == key && (*head_ref)->next == *head_ref) 
  {
  free(*head_ref);
  *head_ref = NULL;
  return;
  }
  struct Node *temp = *head_ref, *d;
if ((*head_ref)->data == key){
  while (temp->next != *head_ref) 
  temp = temp->next;
temp->next = (*head_ref)->next;
  free(*head_ref);
  *head_ref = temp->next;
  }
  while (temp->next != *head_ref && temp->next->data != key) {
  temp = temp->next;
  }
  if (temp->next->data == key) {
  d = temp->next;
  temp->next = d->next;
  free(d);
  }
}

void printList(struct Node* head_ref) {
  struct Node* p;
  if (head_ref == NULL) {
  printf("The list is empty");
  return;
  }
  p = head_ref->next;
  do {
  printf("%d ", p->data);
  p = p->next;
  } while (p != head_ref->next);
}

int main() {
  struct Node* head_ref = NULL;
  head_ref = insertAtBeginning(head_ref, 22);
  head_ref = InsertAtFront(head_ref, 8);
  head_ref = InsertAtFront(head_ref, 54);
  head_ref = InsertAtFront(head_ref, 49);
  head_ref = InsertAtFront(head_ref, 36);
  printf("Circulur Linked list: ");
  printList(head_ref);
  Deletion(&head_ref, 54);
  printf("\n");
  printf("After Deletion: ");
  printList(head_ref);
  return 0;
}