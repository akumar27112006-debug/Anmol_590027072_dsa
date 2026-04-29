#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int countNodes(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Total nodes: %d", countNodes(head));
    return 0;
}
void searchElement(struct Node* head, int key) {
    int pos = 1;
    while(head != NULL) {
        if(head->data == key) {
            printf("Found at position %d", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Not found");
}
struct Node* insertAtBeginning(struct Node* head, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int val) {
    struct Node* newNode = createNode(val);
    if(head == NULL) return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
struct Node* deleteFromBeginning(struct Node* head) {
    if(head == NULL) return NULL;

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    if(head == NULL) return NULL;

    if(head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while(temp->next && temp->next->data != key)
        temp = temp->next;

    if(temp->next) {
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }

    return head;
}
void reverseData(struct Node* head) {
    int arr[100], i = 0;

    struct Node* temp = head;
    while(temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    temp = head;
    for(int j = i-1; j >= 0; j--) {
        temp->data = arr[j];
        temp = temp->next;
    }
}
void reverseData(struct Node* head) {
    int arr[100], i = 0;

    struct Node* temp = head;
    while(temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    temp = head;
    for(int j = i-1; j >= 0; j--) {
        temp->data = arr[j];
        temp = temp->next;
    }
}
struct Node* insertBeg(struct Node* last, int val) {
    struct Node* newNode = createNode(val);

    if(last == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct Node* first = last->next;

    newNode->next = first;
    newNode->prev = last;
    first->prev = newNode;
    last->next = newNode;

    return last;
}
struct Node* insertBeg(struct Node* last, int val) {
    struct Node* newNode = createNode(val);

    if(last == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct Node* first = last->next;

    newNode->next = first;
    newNode->prev = last;
    first->prev = newNode;
    last->next = newNode;

    return last;
}
struct Term {
    int coeff, exp;
    struct Term* next;
};

int evaluate(struct Term* head, int x) {
    int result = 0;

    while(head != NULL) {
        int term = head->coeff;
        for(int i=0;i<head->exp;i++)
            term *= x;

        result += term;
        head = head->next;
    }
    return result;
}
struct Student {
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
