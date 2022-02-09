#include<stdio.h> //Problem with insert at begin and end
#include<stdlib.h> //Unable print the previous data when called the above functions
struct node
{
    int data;
    struct node *pre,*next;
};
struct node *create(int x)
{
    struct node *l;
    l=(struct node *)malloc(sizeof(struct node));
    l->data=x;
    l->pre=NULL;
    l->next=NULL;
    return l;
}
struct node *createn(int n)
{
    struct node *l1,*l2;
    int x,i;
    printf("Enter the node value: ");
    scanf("%d",&x);
    l1=l2=create(x);
    for (i=1;i<n;i++)
    {
        printf("Enter the node: ");
        scanf("%d",&x);
        l2->next=create(x);
        l2->next->pre=l2;
        l2=l2->next;
    }
    return l1;
}
void display(struct node *l)
{
    while (l!=NULL)
    {
        printf("%d\n",l->data);
        l=l->next;
    }
    printf("\n");
}
struct node *findprevious(struct node *l,int x)
{
    struct node *l2;
    if (l2==NULL)
    {
        return NULL;
    }
    if (l->data==x)
    {
        return NULL;
    }
    while (l!=NULL)
    {
        if (l->data==x)
        {
            return l->pre;
        }
        l=l->next;
    }
    return NULL;
}
struct node *iab(struct node *l,int val)
{
    struct node *t=create(val);
    if (l==NULL)
    {
        return t;
    }
    l->next=l;
    l->pre=t;
    return t;
}
struct node * iae(struct node *l,int val)
{
    struct node *l1=l,*t=create(val);
    if (l==NULL)
    {
        return t;
    }
    while (l->next!=NULL)
    {
        l=l->next;
    }
    l->next=t;
    t->pre=l;
    return l1;
}
struct node * dae(struct node *l)
{
    struct node *l1=l;
    if (l==NULL)
    {
        printf("Deletion Not Possible \n");
        return NULL;
    }
    if (l->next==NULL)
    {
        return NULL;
    }
    while (l->next!=NULL)
    {
        l=l->next;
    }
    l->pre->next=NULL;
    return l;
}

struct node *dav(struct node *l,int val)
{
    struct node *l1=l;
    if (l==NULL)
    {
        return NULL;
    }
    while (l!=NULL)
    {
        if  (l->data == val)
        {
            l->pre->next = l->next;
            return l1;
            l=l->next;
        }
        printf("Deletion Not Possible \n");
        return l1;
    }
}
void reversedisplay(struct node *l)
{
    if (l==NULL)
    {
        return ;
    }
    while (l->next !=NULL)
    {
        l=l->next;
    }
    while (l!=NULL)
    {
        printf("%d ",l->data);
        l=l->pre;
    }
    printf("\n");
}
void main()
{
    struct node *l=NULL,*l1=NULL;
    int n,ch,val;
    do
    {
        printf("----------------------------\n");
        printf("1.Create\n2.Display\n3.Find Previous\n4.Insert at Begin\n5.Insert at End\n6.Delete at End\n7.Delete at specified\n8.Reverse display\n9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("Enter no of nodes: ");
                    scanf("%d",&n);
                    l=createn(n);
                    break;
            case 2: printf("The values are: \n");
                    display(l);
                    break;
            case 3: printf("Enter the value to find it's previous: ");
                    scanf("%d",&val);
                    l1=findprevious(l,val);
                    if(l1==NULL)
                    {
                        printf("Element not Found\n");
                    }
                    else
                    {
                        printf("The previous value: %d",l1->data);
                    }
                    break;
            case 4: printf("Enter the value to insert at begin: ");
                    scanf("%d",&val);
                    l=iab(l,val);
                    display(l);
                    break;
            case 5: printf("Enter the values to insert at end: ");
                    scanf("%d",&val);
                    l=iae(l,val);
                    display(l);
                    break;
            case 6: l=dae(l);
                    printf("After Deletion the end node: \n");
                    display(l);
                    break;
            case 7: printf("Enter the value to delete: ");
                    scanf("%d",&val);
                    l=dav(l,val);
                    printf("After Deleting: \n");
                    display(l);
                    break;
            case 8: printf("Printing in Reverse Order: \n");
                    reversedisplay(l);
                    printf("\n");
                    break;
            case 9: exit(0);
                    break;
        }
    } while (ch <10 );    
}
