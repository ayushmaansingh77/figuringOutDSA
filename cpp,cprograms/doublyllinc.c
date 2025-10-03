#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* back;  // previous pointer
} Node;

/* create a new node with given value, next/back initialized to NULL */
Node* create_node(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = value;
    n->next = NULL;
    n->back = NULL;
    return n;
}

/* convert an int array of length n into a doubly linked list and return head */
Node* convertArr2dll(const int arr[], size_t n) {
    if (n == 0) return NULL;

    Node* head = create_node(arr[0]);
    head->back = NULL;
    Node* prev = head;

    for (size_t i = 1; i < n; ++i) {
        Node* temp = create_node(arr[i]);
        temp->back = prev;    // set backward pointer
        prev->next = temp;    // set forward pointer
        prev = temp;
    }
    prev->next = NULL;        // terminate list
    return head;
}

/* print list forward */
void print_list(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

/* free list memory */
void free_list(Node* head) {
    while (head) {
        Node* nxt = head->next;
        free(head);
        head = nxt;
    }
}

int main(void) {
    int arr[] = {12, 5, 8, 7, 34};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArr2dll(arr, n);
    print_list(head);
    free_list(head);
    return 0;
}
