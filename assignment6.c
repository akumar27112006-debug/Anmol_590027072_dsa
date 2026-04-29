#1struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

void display(struct Student* head) {
    while(head != NULL) {
        printf("%d %s %.2f\n", head->roll, head->name, head->marks);
        head = head->next;
    }
}
#2#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int n = 0;

// Heapify Up
void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

// Insert
void insert(int val) {
    heap[n] = val;
    heapifyUp(n);
    n++;
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && heap[left] < heap[smallest])
        smallest = left;

    if(right < n && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(smallest);
    }
}

// Delete root
void deleteRoot() {
    if(n == 0) return;

    heap[0] = heap[n-1];
    n--;
    heapifyDown(0);
}

// Display
void display() {
    for(int i=0;i<n;i++)
        printf("%d ", heap[i]);
}

int main() {
    insert(10);
    insert(5);
    insert(30);
    insert(2);

    display();

    deleteRoot();
    printf("\nAfter deletion:\n");
    display();

    return 0;
}
#3#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int n = 0;

void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && heap[left] < heap[smallest])
        smallest = left;

    if(right < n && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(smallest);
    }
}

// Enqueue
void insert(int val) {
    heap[n] = val;
    heapifyUp(n);
    n++;
}

// Dequeue
void deleteMin() {
    if(n == 0) return;
    heap[0] = heap[n-1];
    n--;
    heapifyDown(0);
}

// Peek
int peek() {
    if(n == 0) return -1;
    return heap[0];
}

// Display
void display() {
    for(int i=0;i<n;i++)
        printf("%d ", heap[i]);
}

int main() {
    insert(20);
    insert(5);
    insert(15);

    printf("Top: %d\n", peek());

    deleteMin();

    display();

    return 0;
}
