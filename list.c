#include "stdio.h"
#include "stdlib.h"


typedef struct list {
    int data;
    struct list *next; 
} list;
list *head;
list *tail = 0;

head = malloc(sizeof(list));
