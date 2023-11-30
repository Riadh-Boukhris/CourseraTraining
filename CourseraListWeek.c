#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200

typedef struct list {
    int data;
    struct list* next;
} list;

int is_empty(const list* h) {
    return h == NULL;
}

list* create_list(int d) {
    list* node = malloc(sizeof(list));
    node->data = d;
    node->next = NULL;
    return node;
}

list* add_to_front(int d, list* h) {
    list* node = create_list(d);
    node->next = h;
    return node;
}

list* array_to_list(int d[], int size) {
    list* head = create_list(d[0]);
    for (int i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list* h, char* title) {
    printf("%s\n", title);
    while (!is_empty(h)) {
        printf("%d\t", h->data);
        h = h->next;
    }
    printf("\n");
}

void remove_duplicates(list* head) {
    list* current = head;

    while (current != NULL) {
        list* runner = current;

        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Remove the duplicate node
                list* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    int data_array[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        data_array[i] = rand() % 50;
    }

    list* head = array_to_list(data_array, SIZE);

    print_list(head, "Original List");

    remove_duplicates(head);

    print_list(head, "\nList after removing duplicates");

    // Free allocated memory
    list* current = head;
    while (current != NULL) {
        list* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
