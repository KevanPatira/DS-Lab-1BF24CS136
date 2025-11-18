#include<stdio.h>
struct Node{
    int val;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL, *new_node = NULL, *Last = NULL;

void create_node(int val)
{
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;
}

void insert_at_end(int val)
{
    create_node(val);
    if(head ==NULL)
        head = new_node;
    else
    {
        Last = head;
        while(Last->next!=NULL)
        {
            Last = Last->next;
        }
        Last->next = new_node;
    }
    printf("\n%d inserted at the back of list.\n",val);
    return;
}

struct Node * getMiddle(struct Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    else
    {
        struct Node *slow = head;
        struct Node *fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}

struct Node * mergeSortedLists(struct Node *h1, struct Node *h2)
{
    struct Node dummy, *tail = &dummy;
    while(h1 != NULL && h2 != NULL)
    {
        if(h1->val <= h2->val)
        {
            tail->next = h1;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    if(h1 != NULL)
        tail->next = h1;
    else if(h2 != NULL)
        tail->next = h2;
    return dummy.next;
}

void display()
{
    if(head == NULL)
    {
        printf("Empty list.\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ,",temp->val);
            temp = temp->next;
        }
    }
    return;
}

struct Node * sort(struct Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    else
    {
        struct Node *mid = getMiddle(head);
        struct Node *head2 = mid->next;
        mid->next = NULL;
        struct Node *sorthead1 = sort(head);
        struct Node *sorthead2 = sort(head2);
        return mergeSortedLists(sorthead1, sorthead2);
    }
}

void main()
{
    int ch, val;
    printf("\n1. insert at back, 2. Sort the list, 3. display :");
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
                sort(head);
                break;
            case 3:
                display();
                break;

            default:
                exit(0);
        }
    }
    return;
}
