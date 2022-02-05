#include<stdio.h>        //Code is working fine but need to change something so that even the first one get's deleted.
#include<stdlib.h>
int a[100];
int size;
int top=-1;
int allfull()
{
    if (top==size)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int allempty()
{
    if (top==-1)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
void push(int value)
{
    int x;
    if (allfull()==-1)
    {
        printf("Cannot be added. The condition of overflow: \n");
    }
    else
    {
        top++;
        a[top]=value;
    
    }   
}
int pop()
{
    int x;
    if (allempty()==-1)
    {
        return -1;
    }
    else
    {
        x=a[top];
        top--;
    }
}
void display()
{
    int i;
    for (i=0;i<top+1;i++)
    {
        printf("Data: %d\n",a[i]);
    }
}
int main()
{
    printf("Enter size of the stack : ");
    scanf("%d",&size);
    int value,ch;
    do
    {
        printf("--------------------------\n");
        printf("Choose from the below: \n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("Enter the value: ");
                    scanf("%d",&value);
                    push(value);
                    display(value);
                    break;
            case 2: value=pop();
                    if (value==-1)
                    {
                        printf("Unable to delete the value: ");
                    }
                    else
                    {
                        printf("The element deleted: \n");
                    }
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
        }
    } while (ch<5);
    
}