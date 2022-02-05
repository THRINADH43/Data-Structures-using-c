#include<stdio.h>  //All the functions defined are working perfectly.
#include<stdlib.h>                                                 
struct node                                                     // TODO : Complete Insert at a point and Insert at a value and also all the delete functions.

{
    int data;
    struct node *next;
};
struct node * create (int value)
{
    struct node *l;
    l=(struct node *)malloc(sizeof(struct node));
    l->data=value;
    l->next=NULL;
    return l;
}
struct node *created(int total)
{
    struct node *l1,*l2;
    int i,value;
    printf("Enter the value: ");
    scanf("%d",&value);
    l1=l2=create(value);
    for (i=1;i<total;i++)
    {
        printf("Enter the value: ");
        scanf("%d",&value);
        l2->next=create(value);
        l2=l2->next;
    }
    l2->next=l1;
    return l1;
}
void display(struct node *l1)
{
    int d;
    d=l1->data;
    printf("Data: %d\n",d);
    l1=l1->next;
    while (l1->data!=d)
    {
        printf("Data: %d\n",l1->data);
        l1=l1->next;
    }

}
int find(struct node *l,int value,int total)
{
    int d,i,to_set=1;
    d=l->data;
    if (d==value)
    {
        return 1;
    }
    l=l->next;
        for (i=1;i<total;i++)
        {
            if (l->data==value)
            {
                to_set=0;
                return i+1;
               break;
            }
            l=l->next;
        }   
    if (to_set==1)
    {
        return -1;
    }
}
struct node* insertatbegin(struct node *l,int value)
{
    struct node *l1,*l2;
    l1=create(value);
    // l1->next=l;
    l2=l;
    int d;
    d=l->data;
    l=l->next;
    while (l->data != d)
    {
        if (l->next->data ==d)
        {
            l->next=l1;
            l1->next=l2;
        }
        l=l->next;
    }
    return l1;   //Need to return the address of l1 as the initial value changed.
}
struct node* insertatend(struct node *l, int value)
{
    struct node *l1,*l2;
    l1=create(value);
    int d;
    l2=l;
    d=l->data;
    l=l->next;
    while (l->data!=d)
    {
        if (l->next->data==d)
        {
            l->next=l1;
            l1->next=l2;
        }
        l=l->next;
    }
    return l2;

}
int main()
{
    struct node *l;
    int total,findres,value,newfindres;
    printf("Enter the total nodes list: ");
    scanf("%d",&total);
    l=created(total);
    display(l);
    printf("Enter the value to search: ");
    scanf("%d",&value);
    findres=find(l,value,total);
    newfindres=findres-1;
    if (newfindres <0)
    {
        printf("Element not found in the list\n");
    }
    else
    {
        printf("Element found at %d\n",newfindres);
        
    }
    printf("Enter value to insert at begin: ");
    scanf("%d",&value);
    l=insertatbegin(l,value);
    printf("After insertion \n");
    display(l);
    printf("Enter the value to insert at end: \n");
    scanf("%d",&value);
    l=insertatend(l,value);
    printf("After insertion at end \n");
    display(l);
}
