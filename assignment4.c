q1
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
    } else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void peek() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        printf("Front: %d\n", queue[front]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    return 0;
}
q2
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;
    free(temp);
}

void display() {
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek() {
    if (front == NULL)
        printf("Queue Empty\n");
    else
        printf("Front: %d\n", front->data);
}

int main() {
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    dequeue();
    peek();
    return 0;
}
q3
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int n = strlen(str);
    char queue[100];
    int front = 0, rear = -1;

    // enqueue all characters
    for (int i = 0; i < n; i++)
        queue[++rear] = str[i];

    int flag = 1;

    for (int i = 0; i < n; i++) {
        if (str[i] != queue[rear--]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
q4
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    return 0;
}
q5
#include <stdio.h>
#define MAX 5

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1;
int f2 = -1, r2 = -1;

void enqueue(int q[], int *f, int *r, int x) {
    if (*r == MAX - 1) return;
    if (*f == -1) *f = 0;
    q[++(*r)] = x;
}

int dequeue(int q[], int *f, int *r) {
    if (*f == -1) return -1;
    int val = q[*f];
    (*f)++;
    if (*f > *r) *f = *r = -1;
    return val;
}

void push(int x) {
    enqueue(q2, &f2, &r2, x);

    while (f1 != -1)
        enqueue(q2, &f2, &r2, dequeue(q1, &f1, &r1));

    // swap q1 and q2
    for (int i = f2; i <= r2; i++)
        q1[i] = q2[i];

    f1 = f2;
    r1 = r2;
    f2 = r2 = -1;
}

void pop() {
    if (f1 == -1) {
        printf("Stack Empty\n");
        return;
    }
    printf("Popped: %d\n", dequeue(q1, &f1, &r1));
}

void peek() {
    if (f1 == -1)
        printf("Stack Empty\n");
    else
        printf("Top: %d\n", q1[f1]);
}

void display() {
    for (int i = f1; i <= r1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    return 0;
}
