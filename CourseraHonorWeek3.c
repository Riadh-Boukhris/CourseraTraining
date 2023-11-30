#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to remove duplicates from the doubly linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        // Search for nodes with the same value as the current node
        struct Node* runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                // Remove the duplicate node
                if (runner->prev != NULL) {
                    runner->prev->next = runner->next;
                }
                if (runner->next != NULL) {
                    runner->next->prev = runner->prev;
                }
                free(runner);
            }
            runner = runner->next;
        }

        current = current->next;
    }
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Generating an initial doubly linked list with random integers from [0, 49]
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < 200; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = rand() % 50;
        newNode->prev = tail;
        newNode->next = NULL;

        if (tail != NULL) {
            tail->next = newNode;
        } else {
            // If the list is empty, set the head
            head = newNode;
        }

        tail = newNode;
    }

    // Print the original list
    printf("Original List:\n");
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    // Print the list after removing duplicates
    printf("\nList after removing duplicates:\n");
    printList(head);

    // Free allocated memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
