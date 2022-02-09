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
    struct node *l1,*l2;
    int x,i;
    l1=l2=create(0);
    for (i=0;i<n;i++)
    {
        printf("Enter the value of nodes: ");
        scanf("%d",&x);
        l2->next=create(x);
        l2=l2->next;
    }
    return l1->next;
}
void display(struct node *l)
{
    while (l!=NULL)
    {
        printf("%d\n",l->data);
        l=l->next;
    }
}
struct node * sort (struct node *l)
{
    struct node *i,*j;
    int t;
    for (i=l;i!=NULL;i=i->next)
    {
        for (j=i->next;j!=NULL;j=j->next)
        {
            if (i->data >  j->data)
            {
                t=i->data;
                i->data = j-> data;
                j->data=t;
            }
        }
    }
    return l;
}
struct node * unions(struct node *l1,struct node *l2)
{
    struct node *l3,*l4;
    l3=l4=create(0);
    while (l1!=NULL && l2!=NULL)
    {
        if (l1->data > l2->data)
        {
            l3->next=create(l2->data);
            l3=l3->next;
            l2=l2->next;
        }
        else if (l1->data < l2->data)
        {
            l3->next = create(l1->data);
            l3=l3->next;
            l1=l1->next;
        }
        else
        {
            l3->next=create(l1->data);
            l3=l3->next;
            l2=l2->next;
            l1=l1->next;
        }
    }
    if (l1==NULL)
    {
        l3->next=l2;
    }
    if (l2==NULL)
    {
        l3->next=l1;
    }
    return l4->next;
}
struct node *intersection(struct node *l1,struct node *l2)
{
    struct node *l3,*l4;
    l3=l4=create(0);
    while (l1!=NULL && l2!=NULL)
    {
        if (l1->data > l2-> data)
        {
            l2=l2->next;
        }
        else if (l1->data < l2-> data)
        {
            l1=l1->next;
        }
        else
        {
            l3->next=create(l1->data);
            l1=l1->next;
            l2=l2->next;
            l3=l3->next;
        }
    }
    return l4->next;
}
void main()
{
    struct node *l1=NULL,*l2=NULL,*lu=NULL,*li=NULL;
    int n1,n2,ch;
    do
    {
        printf("----------------------\n");
        printf("1.Create\n2.Display\n3.Union\n4.Intersection\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("Enter no of nodes of set A: ");
                    scanf("%d",&n1);
                    l1=createn(n1);
                    l1=sort(l1);
                    printf("Enter no of nodes of set B: ");
                    scanf("%d",&n2);
                    l2=createn(n2);
                    l2=sort(l2);
                    break;
            case 2: printf("The values of set A: \n");
                    display(l1);
                    printf("The values of Set B: \n");
                    display(l2);
                    break;
            case 3: lu=unions(l1,l2);
                    printf("After union: \n");
                    display(lu);
                    break;
            case 4: li=intersection(l1,l2);
                    printf("After Intersection: \n");
                    display(li);
                    break;
            case 5: exit(0);
                    break;

        }
    } while (ch<6);
    
}
