#include<stdio.h>
#include<stdlib.h>

struct Node *root=NULL;

struct Node {
    struct Node *rchild;
    struct Node *lchild;
    int data;
};

struct Queue {
    int size, front, rear;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x) {
    if((q->rear+1) % q->size == q->front)
        printf("queue is full\n");
    else {
        q->rear = (q->rear+1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q) {
    struct Node* x = NULL;
    if(q->front == q->rear)
        printf("queue is empty\n");
    else {
        q->front = (q->front+1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q) {   
    return q.front == q.rear;
}

void create() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter the root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q)) {
        p = dequeue(&q);

        printf("Enter the left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if(x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter the right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if(x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p) {
    if(p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p) {
    if(p) {
       
        inorder(p->lchild);
         printf("%d ", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct Node *p) {
    if(p) {
       
        postorder(p->lchild);
        postorder(p->rchild);
         printf("%d ", p->data);
    }
}
int main() {
    create();
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\n post order");
    postorder(root);
    printf("\n Inorder");
    inorder(root);
    return 0;
}
