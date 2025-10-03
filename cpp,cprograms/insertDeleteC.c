#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* createNode: allocate and initialize a node */
struct Node *createNode(struct Node *next, int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(*n));
    if (!n) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = val;
    n->next = next;
    return n;
}

struct Node *insertHead(struct Node *head, int val)
{
    struct Node *temp = createNode(head, val);
    return temp;
}

struct Node *insertK(struct Node *head, int val, int k)
{
    if (head == NULL) {
        if (k == 1) {
            return createNode(NULL, val);
        } else {
            return NULL;
        }
    }

    if (k == 1) {
        struct Node *temp = createNode(head, val);
        return temp;
    }

    int cnt = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        cnt++;
        if (cnt == k - 1) {
            struct Node *x = createNode(temp->next, val);
            temp->next = x;
            return head;
        }
        temp = temp->next;
    }

    return head;
}

struct Node* convert2ll(int arr[], int n) {
    if (n <= 0) return NULL;
    struct Node* head = createNode(NULL, arr[0]);
    struct Node* mover = head;
    for (int i = 1; i < n; i++) {
        struct Node* temp = createNode(NULL, arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while (head) {
        struct Node* nxt = head->next;
        free(head);
        head = nxt;
    }
}

struct Node *removesHead(struct Node * head)
{
    if (head == NULL) return head;

    struct Node * temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deleteTail(struct Node *head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node *deletek(struct Node *head, int k){
    if (head == NULL) {
        return head;
    }
    if (k == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            if (prev != NULL) {
                prev->next = prev->next->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


int main()
{
    int arr[] = {12, 3, 4, 7, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Create list from array: ");
    struct Node *head = convert2ll(arr, n);
    printList(head);                     // 

    printf("Insert 100 at head: ");
    head = insertHead(head, 100);
    printList(head);                     
    printf("Insert 200 at position 3: ");
    head = insertK(head, 200, 3);        
    printList(head);                    

    printf("Remove head: ");
    head = removesHead(head);
    printList(head);                     

    printf("Delete tail: ");
    head = deleteTail(head);
    printList(head);                     

    printf("Delete element at position 4: ");
    head = deletek(head, 4);             
    printList(head);                     

    /* cleanup */
    freeList(head);
    head = NULL;

    return 0;
}
