#include <stdio.h>
#include <stdlib.h>

int max = 3;
int q[3];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear >= max -1)
    {
        printf("Queue Overflow");
        return;
    }
    
    q[++rear] = data;
    if (front == -1)
    {
        front = 0;
    }
}

int dequeue() {
    if (front == -1)
    {
        printf("Queue Underflow");
        return 0;
    }
    
    int data = q[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else {
        ++front;
    }
    return data;
}

void display() {
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", q[i]);
    }
}


int main(void) {
    enqueue(30);
    enqueue(20);
    enqueue(10);
    display();
    printf("\ndequeued: %d\n",dequeue());
    display();
    return 0;
}