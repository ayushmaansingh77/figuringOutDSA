/* circular_doubly.c
   Simple Neso-style circular doubly linked list with insertion/deletion.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

/* addToEmpty: create one-node circular doubly list; node->next=node->prev=node */
struct node* addToEmpty(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) return NULL;
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp; /* tail */
}

/* insert at beginning: new node becomes head (tail->next) */
struct node* addAtBeg(struct node* tail, int data) {
    if (tail == NULL) return addToEmpty(data);
    struct node *head = tail->next;
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;

    newP->prev = tail;
    newP->next = head;
    head->prev = newP;
    tail->next = newP;
    return tail; /* tail unchanged */
}

/* insert at end: new node becomes tail */
struct node* addAtEnd(struct node* tail, int data) {
    if (tail == NULL) return addToEmpty(data);
    struct node *head = tail->next;
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;

    newP->next = head;
    newP->prev = tail;
    tail->next = newP;
    head->prev = newP;
    tail = newP; /* update tail */
    return tail;
}

/* insert after position pos (1-based). If tail==NULL, create node. */
struct node* addAfterPos(struct node* tail, int data, int pos) {
    if (tail == NULL) return addToEmpty(data);
    struct node *temp = tail->next; /* head */
    while (pos > 1) {
        if (temp == tail) break;
        temp = temp->next;
        pos--;
    }
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;

    newP->prev = temp;
    newP->next = temp->next;
    temp->next->prev = newP;
    temp->next = newP;

    if (temp == tail) tail = newP; /* inserted after tail -> new tail */
    return tail;
}

/* print list from head */
void printList(struct node* tail) {
    if (tail == NULL) { printf("No element in the List\n"); return; }
    struct node *temp = tail->next; /* head */
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

/* delete first */
struct node* delFirst(struct node* tail) {
    if (tail == NULL) return NULL;
    if (tail->next == tail) { free(tail); return NULL; } /* single node */
    struct node *head = tail->next;
    struct node *newHead = head->next;
    tail->next = newHead;
    newHead->prev = tail;
    free(head);
    return tail;
}

/* delete last */
struct node* delLast(struct node* tail) {
    if (tail == NULL) return NULL;
    if (tail->next == tail) { free(tail); return NULL; }
    struct node *last = tail;
    struct node *prev = last->prev;
    prev->next = last->next;
    last->next->prev = prev;
    free(last);
    tail = prev;
    return tail;
}

/* delete intermediate at position pos (1-based).
   pos==1 => delete first. If deleting tail, update tail. */
struct node* delInter(struct node* tail, int pos) {
    if (tail == NULL) return NULL;
    if (pos == 1) return delFirst(tail);
    struct node *temp = tail->next; /* head */
    while (pos > 1) {
        temp = temp->next;
        pos--;
    }
    /* temp is node to delete */
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp == tail) tail = temp->prev; /* if deleting tail, update */
    free(temp);
    return tail;
}

int main() {
    struct node *tail = NULL;

    tail = addToEmpty(34);             /* list: 34 */
    tail = addAtEnd(tail, 45);         /* 34 45 */
    tail = addAtEnd(tail, 6);          /* 34 45 6 */
    printf("Initial: ");
    printList(tail);

    tail = addAfterPos(tail, 56, 2);   /* insert 56 after pos 2 (after 45) */
    printf("After addAfterPos 56 at pos 2: ");
    printList(tail);

    tail = addAtBeg(tail, 11);         /* insert at beginning */
    printf("After add at beginning (11): ");
    printList(tail);

    tail = delFirst(tail);
    printf("After delete first: ");
    printList(tail);

    tail = delLast(tail);
    printf("After delete last: ");
    printList(tail);

    tail = delInter(tail, 2); /* delete node at pos 2 */
    printf("After delete at pos 2: ");
    printList(tail);

    /* free remaining nodes */
    while (tail) tail = delFirst(tail);
    return 0;
}
