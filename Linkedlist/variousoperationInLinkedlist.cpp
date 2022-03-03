#include <stdio.h>
#include <stdlib.h>
struct Node
{
    /* data */
    int data;
    struct Node *next;
};
struct Node *head = NULL;
int d;
void creat()
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the value for inserting in the linkedlist\n");
    scanf("%d", &d);
    newnode->next = NULL;
    newnode->data = d;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void deleteFromBegining()
{
    struct Node *beg = head;
    if (head != NULL)
    {
        head = head->next;
        free(beg);
    }
}
void deleteFromEnd()
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
}
void printList()
{
    struct Node *print = head;
    while (print != NULL)
    {
        printf("%d ", print->data);
        print = print->next;
    }
    printf("\n");
}
void ddeleteFromMiddle()
{
    int value;
    printf("Enter the value which want to delete from Linked list\n");
    scanf("%d", &value);
    struct Node *prev;
    struct Node *temp = head;
    while (temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
}
// Linked List various Operations
int main()
{
    int choice;
    printf("Enter 1 for inserting a element\nEnter 2 for deleteing the element from brgining\nEnter 3 for delteing the elemwnt from last\nEnter 4 for print the list\nEnter 5 for deleting the element from middle\nEnter 0 for exit\n");

    while (1)
    {
        printf("enetr choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creat();
            break;

        case 2:
            deleteFromBegining();
            break;
        case 3:
            deleteFromEnd();
            break;
        case 4:
            printList();
            break;
        case 5:
            ddeleteFromMiddle();
            break;
        case 0:
            return 0;
            break;
        }
    }

    return 0;
}