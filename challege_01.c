#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the middle of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Traverse the list with two pointers:
    // - 'fast' moves two steps at a time
    // - 'slow' moves one step at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // 'slow' will be at the middle
}

// Helper function to add a new node at the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Helper function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating a sample linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5); // For an odd count, the middle should be 3
    appendNode(&head, 6); // For an odd count, the middle should be 3

    printList(head);

    struct Node* middle = findMiddle(head);
    if (middle != NULL) {
        printf("Middle element: %d\n", middle->data);
    } else {
        printf("The list is empty.\n");
    }

}