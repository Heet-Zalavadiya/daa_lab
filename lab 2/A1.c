#include <stdio.h>

int stack[100];
int top = -1;
int max = 3;

void push(int x)
{
    if (top == max - 1)
    {
        printf("Stack Overflow");
        return;
    }

    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return 0;
    }

    return stack[top--];
}

int peep(int idx)
{
    if (stack[top - idx + 1] < 0)
    {
        printf("Stack Underflow");
        return 0;
    }
    return stack[top - idx + 1];
}

void change(int x, int idx)
{
    if (stack[top - idx + 1] < 0)
    {
        printf("Stack Underflow");
        return;
    }
    stack[top - idx + 1] = x;
}

void display() {
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n",stack[i]);
    }
    return;
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    display();
    printf("\nPopped: %d\n",pop());
    display();

    printf("\nPeeped: %d\n",peep(1));
    display();

    change(11,1);
    display();

    return 0;
}