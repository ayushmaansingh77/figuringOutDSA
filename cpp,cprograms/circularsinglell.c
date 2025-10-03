

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* create one-node circular list */
struct node* addToEmpty(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) return NULL;
    temp->data = data;
    temp->next = temp;
    return temp; /* this node is both head and tail */
}

/* insert at beginning: tail stays same, head is tail->next */
struct node* addAtBeg(struct node* tail, int data) {
    if (tail == NULL) return addToEmpty(data);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next; /* point to current head */
    tail->next = temp;       /* tail now links to new head */
    return tail;
}

/* insert at end: new node becomes tail */
struct node* addAtEnd(struct node* tail, int data) {
    if (tail == NULL) return addToEmpty(data);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next; /* head */
    tail->next = temp;
    tail = temp;             /* update tail */
    return tail;
}

/* insert after position pos (1-based, relative to head).
   If pos is larger than length, insertion happens after last node. */
struct node* addAfterPos(struct node* tail, int data, int pos) {
    if (tail == NULL) return addToEmpty(data);
    struct node *p = tail->next; /* head */
    while (pos > 1) {
        if (p == tail) break; /* reached tail */
        p = p->next;
        pos--;
    }
    /* insert after p */
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    if (p == tail) tail = temp; /* if inserted after tail, new node becomes tail */
    return tail;
}

/* delete first node */
struct node* delFirst(struct node* tail) {
    if (tail == NULL) return NULL;
    struct node *head = tail->next;
    if (head == tail) { /* single node */
        free(head);
        return NULL;
    }
    tail->next = head->next;
    free(head);
    return tail;
}

/* delete last node */
struct node* delLast(struct node* tail) {
    if (tail == NULL) return NULL;
    struct node *head = tail->next;
    if (head == tail) { free(tail); return NULL; }
    struct node *p = head;
    while (p->next != tail) p = p->next;
    p->next = tail->next; /* p becomes new last */
    free(tail);
    tail = p;
    return tail;
}

/* delete intermediate node at position pos (1-based).
   pos==1 deletes head (calls delFirst). */
struct node* delInter(struct node* tail, int pos) {
    if (tail == NULL) return NULL;
    if (pos == 1) return delFirst(tail);
    struct node *p = tail->next; /* head */
    while (pos > 2 && p->next != tail->next) {
        p = p->next;
        pos--;
    }
    struct node *del = p->next;
    if (del == tail) { /* deleting tail node */
        p->next = del->next;
        free(del);
        tail = p;
        return tail;
    }
    p->next = del->next;
    free(del);
    return tail;
}

/* print circular list starting from head (tail->next) */
void printList(struct node* tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *p = tail->next; /* head */
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

int main() {
    struct node *tail = NULL;

    /* build initial list: 34 -> 45 -> 6 */
    tail = addToEmpty(34);
    tail = addAtEnd(tail, 45);
    tail = addAtEnd(tail, 6);
    printf("Initial: ");
    printList(tail);

    /* insert 66 after position 2 (after 45) */
    tail = addAfterPos(tail, 66, 2);
    printf("After insert 66 at pos 2: ");
    printList(tail);

    /* insert at beginning */
    tail = addAtBeg(tail, 11);
    printf("After add at beginning (11): ");
    printList(tail);

    /* delete first */
    tail = delFirst(tail);
    printf("After delete first: ");
    printList(tail);

    /* delete last */
    tail = delLast(tail);
    printf("After delete last: ");
    printList(tail);

    /* delete intermediate at pos 2 */
    tail = delInter(tail, 2);
    printf("After delete at pos 2: ");
    printList(tail);

    /* free remaining nodes */
    while (tail) tail = delFirst(tail);
    return 0;
}
