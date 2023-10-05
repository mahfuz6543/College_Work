#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node{
  int data;
  struct Node* next;
};

// insert at beginning
void insertAtBeginning(struct Node** head_ref, int new_data){
  // allocate node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // insert the data
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

// insert at middle
void insertAfter(struct Node* prev_node, int new_data){
  if (prev_node == NULL){
  printf("previous node provided cannot be NULL");
  return;
  }
  // allocate new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  // make new node as next previous node
  new_node->next = prev_node->next;
  // move previous node as new node
  prev_node->next = new_node;
}

// insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
//allocate node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; 
  new_node->data = new_data;
  new_node->next = NULL;
  // make the new node the head if the Linked List is empty
  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }
  // else traverse until the final node
  while (last->next != NULL) last = last->next;
  last->next = new_node;
  return;
}

// Deletion
void deleteNode(struct Node** head_ref, int key) {
    // store head node
  struct Node *temp = *head_ref, *prev;
  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Locate the key that has to be delete.
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }
  // If the key is not present
  if (temp == NULL) return;
  // Remove the node
  prev->next = temp->next;
  free(temp);
}

// Search a node
int searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;
  while (current != NULL) {
  if (current->data == key) return 1;
  current = current->next;
  }
  return 0;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } 
  else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;
  insertAtEnd(&head, 8);
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 26);
  insertAtEnd(&head, 77);
  insertAfter(head->next, 0);

  printf("Linked list: ");
  printList(head);

  printf("\nDeleting after an element: ");
  deleteNode(&head, 10);
  printList(head);

  int item_to_find = 10;
  if (searchNode(&head, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d :Deleted element", item_to_find);
  }

  sortLinkedList(&head);
  printf("\nSorted List: ");
  printList(head);
}