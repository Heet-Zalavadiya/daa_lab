#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayNode(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node *insertNode(struct Node *head, int val)
{
    // insert at first
    if (head == NULL || head->data > val)
    {
        struct Node *new = malloc(sizeof(struct Node));
        new->data = val;
        new->next = head;
        head = new;
        return head;
    }
    // insert at middle
    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data < val)
    {
        curr = curr->next;
    }
    struct Node *new = malloc(sizeof(struct Node));
    new->data = val;
    new->next = curr->next;
    curr->next = new;

    return head;
}

struct Node *deleteNode(struct Node *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == val)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *curr = head;
    while (curr->next != NULL && curr->next->data != val)
    {
        curr = curr->next;
    }

    if (curr->next != NULL)
    {
        struct Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    return head;
}

int main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    displayNode(head);

    head = insertNode(head, 9);
    head = insertNode(head, 21);
    head = insertNode(head, 31);

    printf("\nAfter insert\n");
    displayNode(head);

    head = deleteNode(head, 9);
    head = deleteNode(head, 21);
    head = deleteNode(head, 31);

    printf("\nAfter delete\n");
    displayNode(head);
    
    free(head);
    free(second);
    free(third);
    return 0;
}