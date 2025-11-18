#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head = NULL, *Temp = NULL, *Last = NULL, *pre = NULL, *new_node = NULL, *curr = NULL, *next = NULL;

void create_node(int val)
{
    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    return;
}

void insert_at_end(int val)
{
    create_node(val);
    if(Head ==NULL)
        Head = new_node;
    else
    {
        Last = Head;
        while(Last->next!=NULL)
        {
            Last = Last->next;
        }
        Last->next = new_node;
    }
    printf("\n%d inserted at the back of list.\n",val);
    return;
}

void display()
{
    if(Head == NULL)
    {
        printf("Empty list.\n");
    }
    else
    {
        Temp = Head;
        while(Temp != NULL)
        {
            printf("%d ,",Temp->data);
            Temp = Temp->next;
        }
    }
    return;
}

struct Node * reverse()
{
    curr = Head;
    pre = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    Head = pre;
    return Head;
}

struct Node * concatenate(struct Node *h1, struct Node *h2)
{
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    Last = h1;
    while(Last->next != NULL)
    {
        Last = Last->next;
    }
    Last->next = h2;
    return h1;
}

void main()
{
    int ch, val,pos;
    printf("\n1. insert at back, 2. Reverse, 3. Concatenate two list, 4. display :");
    struct Node *h2 = NULL;
    while(1)
    {
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value:");
                scanf("%d", &val);
                insert_at_end(val);
                break;
            case 2:
                reverse();
                break;
            case 3:
                concatenate(Head, h2);
                break;
            case 4:
                display();
                break;

            default:
                exit(0);
        }
    }
    return;
}

