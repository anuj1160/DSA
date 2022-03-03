#include <stdio.h>
#include <stdlib.h>
struct ArrayStack
{
    int top, capacity;
    int *array;
};
struct ArrayStack *createStack(int cap)
{
    struct ArrayStack *stack;
    stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (int*)malloc(cap * sizeof(int));
    return stack;
}                                             
                                                            //  stack using array
int isFull(struct ArrayStack *stack)
{
    if (stack->top == stack->capacity - 1)
    {
        return 1;                                   
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct ArrayStack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct ArrayStack *stack, int value)
{
    if (!isFull(stack))
    {
        stack->top++;
        stack->array[stack->top] = value;
    }
}
int pop(struct ArrayStack *stack)
{
    if (!isEmpty(stack))
    {
        int item;
        item = stack->array[stack->top];
        stack->top--;
        return item;
    }
    return -1;
}

int main()
{
    int num, temp;
    struct ArrayStack *stack;
    stack = createStack(4);
    int choice;
    printf("\n1. push");
        printf("\n2. pop");
        printf("\n3. exit");
    while (1)
    {
        
        printf("\n Enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number\n");
            scanf("%d", &num);
            push(stack, num);
            break;
        case 2:
            temp = pop(stack);
            if (temp == -1)
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("popped value is %d\n", temp);
            }
            break;
        case 3:
            exit(0);
        }
    }

    return 0;
}