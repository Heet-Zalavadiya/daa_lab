// Write a program to implement binary search algorithm using linked list and recursive method.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int binarySearchRecursive(struct Node *head, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    struct Node *current = head;
    for (int i = 0; i < mid; i++) {
        current = current->next;
    }
    if (current->data == target) {
        return mid;
    } else if (current->data < target) {
        return binarySearchRecursive(head, target, mid + 1, high);
    } else {
        return binarySearchRecursive(head, target, low, mid - 1);
    }
}

int main() {
    struct Node *head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(9);

    int target = 5;
    int result = binarySearchRecursive(head, target, 0, 4);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    // Free the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}