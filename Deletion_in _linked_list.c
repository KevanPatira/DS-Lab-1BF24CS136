#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head = NULL, *Temp = NULL, *Last = NULL, *pre=NULL, *new_node;

void create_node(int val)
{
    new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    return;
}

void insert_at_beg(int val)
{
    create_node(val);
    if(Head == NULL)
        Head = new_node;
    else
    {
        new_node->next = Head;
        Head = new_node;
    }
    printf("\n%d inserted at the front of list.\n",val);
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

void insert_at_pos(int val, int pos)
{
    if(pos == 0)
    {
        insert_at_beg(val);
        return;
    }
    create_node(val);
    if(Head == NULL)
        Head = new_node;
    else
    {
        Temp = Head;
        for(int i=0;i<pos-1;i++)
        {
            Temp = Temp->next;
        }
        new_node->next = Temp->next;
        Temp->next = new_node;
    }
    printf("\n%d is inserted at %d index of list.\n", val, pos);
    return;
}

void Delete_beg()
{
    if(Head == NULL)
    {
        printf("Empty list");
    }
    else if(Head->next == NULL)
    {
        free(Head);
        Head = NULL;
    }
    else
    {
        Temp = Head;
        Head = Head->next;
        free(Temp);
        Temp = NULL;
    }
    return;
}

void Delete_end()
{
    if(Head == NULL)
    {
        printf("Empty list");
    }
    else if(Head->next == NULL)
    {
        free(Head);
        Head = NULL;
    }
    else
    {
        Temp = Head;
        while(Temp->next!=NULL)
        {
            pre = Temp;
            Temp = Temp->next;
        }
        pre->next = NULL;
        free(Temp);
        Temp = NULL;
    }
    return;
}

void Delete_pos(int pos)
{
    if(Head == NULL)
        printf("Empty list");
    else if(Head->next == NULL)
    {
        free(Head);
        Head = NULL;
    }
    else if(pos == 1)
    {
        Delete_beg;
    }
    else
    {
        Temp = Head;
        for(int i=0;i<pos;i++)
        {
            pre = Temp;
            Temp = Temp->next;
        }
        pre->next = Temp->next;
        free(Temp);
        Temp = NULL;
    }
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

void main()
{
    int ch, val,pos;
    printf("\n1. insert at front, 2. insert at back, 3.insert at a position, 4. display, 5. Delete from front, 6. delete from end, 7. delete from a position :");
    while(1)
    {
        printf("\nEnter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value:");
                scanf("%d", &val);
                insert_at_beg(val);
                break;
            case 2:
                printf("Enter value:");
                scanf("%d", &val);
                insert_at_end(val);
                break;
            case 3:
                printf("Enter value and position:");
                scanf("%d %d", &val,&pos);
                insert_at_pos(val,pos);
                break;
            case 4:
                display();
                break;
            case 5:
                Delete_beg();
                break;
            case 6:
                Delete_end();
                break;
            case 7:
                printf("Enter index value of node to be deleted:");
                scanf("%d", &pos);
                Delete_pos(pos);
                break;
            default:
                exit(0);
        }
    }
    return;
}
