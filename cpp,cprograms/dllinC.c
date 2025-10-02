
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *back;
} Node;

/* create doubly linked list from array, returns head (or NULL if n==0) */
Node *convertArr2dll(const int arr[], size_t n) {
    if (n == 0) return NULL;
    Node *head = (Node*)malloc(sizeof(Node));
    if (!head) { perror("malloc"); exit(EXIT_FAILURE); }
    head->data = arr[0];
    head->back = NULL;
    head->next = NULL;

    Node *prev = head;
    for (size_t i = 1; i < n; ++i) {
        Node *temp = (Node*)malloc(sizeof(Node));
        if (!temp) { perror("malloc"); exit(EXIT_FAILURE); }
        temp->data = arr[i];
        temp->back = prev;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

/* print list */
void printList(const Node *head) {
    const Node *cur = head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next) printf(" <-> ");
        cur = cur->next;
    }
    printf("\n");
}

/* free entire list */
void freeList(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* delete head, return new head */
Node *deleteHead(Node *head) {
    if (!head) return NULL;
    if (!head->next) { /* single node */
        free(head);
        return NULL;
    }
    Node *old = head;
    head = head->next;
    head->back = NULL;
    free(old);
    return head;
}

/* delete tail, return head */
Node *deleteTail(Node *head) {
    if (!head) return NULL;
    if (!head->next) { free(head); return NULL; }
    Node *tail = head;
    while (tail->next) tail = tail->next;
    Node *prev = tail->back;
    prev->next = NULL;
    free(tail);
    return head;
}

/* ---------- insertion routines in C ---------- */

/* insert at beginning, returns new head */
Node *insert_at_begin(Node *head, int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = value;
    n->back = NULL;
    n->next = head;
    if (head) head->back = n;
    return n;
}

/* insert at end, returns head */
Node *insert_at_end(Node *head, int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = value;
    n->next = NULL;
    if (!head) { n->back = NULL; return n; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    n->back = cur;
    return head;
}

/* insert after first node with target value; returns head.
   If target not found, appends at end. */
Node *insert_after_value(Node *head, int target, int value) {
    if (!head) {
        /* empty list -> new single node */
        Node *n = (Node*)malloc(sizeof(Node));
        if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
        n->data = value; n->next = n->back = NULL;
        return n;
    }
    Node *cur = head;
    while (cur && cur->data != target) cur = cur->next;
    if (!cur) {
        /* not found -> insert at end */
        return insert_at_end(head, value);
    }
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = value;
    n->next = cur->next;
    n->back = cur;
    cur->next = n;
    if (n->next) n->next->back = n;
    return head;
}

/* demo in main */
int main(void) {
    int arr[] = {12, 5, 8, 7, 34};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    Node *head = convertArr2dll(arr, n);
    printf("Initial list:\n"); printList(head);

    printf("Insert 3 at beginning:\n");
    head = insert_at_begin(head, 3);
    printList(head);

    printf("Insert 99 at end:\n");
    head = insert_at_end(head, 99);
    printList(head);

    printf("Insert 42 after first node with value 8:\n");
    head = insert_after_value(head, 8, 42);
    printList(head);

    printf("Delete head:\n");
    head = deleteHead(head);
    printList(head);

    printf("Delete tail:\n");
    head = deleteTail(head);
    printList(head);

    freeList(head);
    return 0;
}
