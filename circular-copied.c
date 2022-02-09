#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *create(int x)
{
    struct node *l;
    l=(struct node *)malloc(sizeof(struct node));
    l->data=x;
    l->next=NULL;
    return l;
}
struct node *createn(int n)
{
    if(n==0)
    {
        return NULL;
    }
    struct node *l1,*l2;
    int x,i;
    printf("Enter the node: ");
    scanf("%d",&x);
    l1=l2=create(x);
    for (i=1;i<n;i++)
    {
        printf("Enter the node: ");
        scanf("%d",&x);
        l2->next=create(x);
        l2=l2->next;
    }
    l2->next=l1;
    return l1;
}
void display(struct node *l)
{
    struct node *l1=l;
    /*if (l==NULL)
    {
        printf("List is empty: \n");
        return 0;
    }*/
    do
    {
        printf("%d \n",l->data);
        l=l->next;
    } while (l!=l1);
}
int count(struct node *l)
{
    int c=0;
    struct node * l1=l;
    if (l==NULL)
    {
        return c;
    }
    do
    {
        c++;
        l=l->next;
    } while (l!=l1);
    return c;
}
struct node * search(struct node *l, int val)
{
    struct node *l1=l;
    if(l==NULL)
    {
        printf("List is empty: \n");
        return NULL;
    }
    do
    {
        if(l->data==val)
        {
            return l;
        }
        l=l->next;
    } while (l!=l1);
    return NULL;    
}
struct node *findprevious(struct node *l,int val)
{
    struct node *l1=l,*pre=NULL;
    if (l==NULL)
    {
        return NULL;
    }
    if (l->next==l)
    {
        return NULL;
    }
    do
    {
        pre=l1;
        l1=l1->next;
        if(l1->data==val)
        {
            return pre;
        }
    } while (l!=l1);
    return NULL;
}
struct node *iab(struct node *l,int val)
{
    struct node *l1=l,*t;
    t=create(val);
    if (l==NULL)
    {
        t->next=t;
        return t;
    }
    while (l1->next !=l)
    {
        l1=l1->next;
    }
    t->next=l;
    l1->next=t;
    return t;
}
struct node *iae(struct node *l,int val)
{
    struct node *l1=l,*t;
    t=create(val);
    if (l==NULL)
    {
        t->next=t;
        return t;
    }
    while (l1->next !=l)
    {
        l1=l1->next;
    }
    t->next=l;
    l1->next=t;
    return l;
}
struct node *iav(struct node *l,int val, int x)
{
    struct node *l1,*t;
    l1=search(l1,x);
    if (l1==NULL)
    {
        printf("Insertion Not Possible: \n");
        return l;
    }
    t=create(val);
    t->next=l1->next;
    l1->next=t;
    return l;
}
