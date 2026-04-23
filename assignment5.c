/*1.	Write a C program to implement a Binary Search Tree (BST) using a linked list representation. Your program should support the following operations:
(i)	Insertion: Insert a node into the BST while maintaining BST properties. Duplicate values should not be allowed.
(ii)	Deletion: Delete a node from the BST based on a given key.
"	Handle all three cases: (a) Node is a leaf node, (b) Node has one child and (c) Node has two children
(iii)	 Searching: Search for a given value in the BST (Display whether the element is found or not).
(iv)	 Traversal: In order Traversal (Left ? Root ? Right).*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value not allowed!\n");

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }
    if (key == root->data) {
        printf("Element found\n");
        return;
    }
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Search  4.Inorder  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

/*2.	Write a C program to implement a Binary Heap (Min Heap or Max Heap). The program should support the following operations:
(i)	Heap Creation: Initialize an empty heap using an array.
(ii)	Insertion (Heapify-Up): Insert a new element into the heap. Maintain the heap property using heapify-up operation.
(iii)	 Deletion (Heapify-Down): Delete the root element (minimum in Min Heap / maximum in Max Heap). Maintain heap property using heapify-down operation.
(iv)	 Display Heap: Print the elements of the heap.*/


#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    size++;
    heap[size] = value;

    int i = size;

    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void deleteRoot() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", heap[1]);

    heap[1] = heap[size];
    size--;

    int i = 1;

    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= size && heap[left] < heap[smallest])
            smallest = left;

        if (right <= size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert  2.Delete Root  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

/*3.	Write a C program to implement a Priority Queue using a Binary Heap (Min Heap or Max Heap). The program should support the following operations:
(i)	Insert (Enqueue with Priority): Insert an element along with its priority into the queue. Maintain heap property using heapify-up.
(ii)	Delete (Dequeue Highest Priority Element): Remove the element with the highest priority: (Min Heap ? smallest element) and (Max Heap ? largest element). Maintain heap property using heapify-down.
(iii)	 Peek: Display the element with the highest priority without removing it.
(iv)	 Display: Print all elements of the priority queue.*/

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    size++;
    heap[size] = value;

    int i = size;

    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void deleteRoot() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Removed element: %d\n", heap[1]);

    heap[1] = heap[size];
    size--;

    int i = 1;

    while (1) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= size && heap[left] < heap[smallest])
            smallest = left;

        if (right <= size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void peek() {
    if (size == 0)
        printf("Queue is empty!\n");
    else
        printf("Highest priority element: %d\n", heap[1]);
}

void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value (priority): ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
