#include<stdio.h>
int size;
int top=-1;
int stack[100];
int isfull()
{
    if(top!=size-1)
    {
        return 1;
    }
    printf("Stack overflow.\n");
    return 0;
}
int isempty()
{
    if(top!=-1)
    {
        return 1;
    }
    printf("Stack underflow.\n");
    return 0;
}
void push(int data)
{
	if(isfull())
    {
        stack[++top] = data;
        printf("%d is added.\n",data);
    }
}
void pop()
{
    if(isempty())
    {
        printf("%d is removed.\n",stack[top--]);
    }
}
void peek()
{
    if(isfull())
    {
        printf("%d\n",stack[top]);
    }
}
void Display()
{
    printf("Elements in the stack are:\n");
    for(int i=0;i<top;i++)
    {
        if(i==0)
            printf("[ %d, ",stack[i]);
        else if(i==top-1)
            printf("%d ]\n",stack[i]);
        else
            printf("%d, ",stack[i]);            
    }
}
int main()
{
    printf("Enter size of stack:");
    scanf("%d", &size);
    int stack[size],choice,data;
    for(int i=0;i<100;i++)
    {
        printf("\nEnter 1 to push\n2 to pop\n3 to peek\n4 to Display\nAnything else to exit:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to push in stack:");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                Display();
                break;
            default:
                printf("Exiting the program.");
            	return 0;
        }
    } 
}