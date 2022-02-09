#include<stdio.h> //check the addition polynomial again
#include<stdlib.h>
struct node
{
    int coeff,exp;
    struct node *next;
};
struct node * create(int c,int e)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->coeff=c;
    p->exp=e;
    p->next=NULL;
    return p;
}
struct node * createpoly()
{
    struct node *p1,*p2;
    int ch,c,e;
    p1=p2=create(0,0);
    while (1)
    {
        printf("1.Continue\n2.Terminate\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if (ch==2)
        {
            break;
        }
        printf("Enter coefficient and exponent: \n");
        scanf("%d %d",&c,&e);
        p2->next=create(c,e);
        p2=p2->next;
        if (e==0)
        {
            break;
        }
    }
    return p1->next;
}
void display(struct node *p)
{
    while (p!=NULL)
    {
        printf("%dX^%d",p->coeff,p->exp);
        if (p->next!=NULL)
        {
            printf("&");
        }
        p=p->next;
    }
}
struct node *addpoly(struct node *p1,struct node *p2)
{
    struct node *p3=NULL,*p4=NULL;
    p3=p4=create(0,0);
    while (p1!=NULL && p2!=NULL)
    {
        if (p1->exp > p2->exp)
        {
            p3->next=create(p1->coeff,p1->exp);
            p3=p3->next;
            p1=p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            p3->next=create(p2->coeff,p2->exp);
            p3=p3->next;
            p2=p2->next;
        }
        else
        {
            p3->next=create(p1->coeff+p2->coeff,p1->exp);
            p3=p3->next;
            p1=p1->next;
        }
    }
    if (p1==NULL)
    {
        p3->next=p2;
    }
    if (p2==NULL)
    {
        p3->next=p1;
    }
    return p4->next;
}
struct node * mulpoly(struct node *p1,struct node *p2)
{
    struct node *p3=NULL,*p4=NULL,*p5=NULL,*i,*j;
    for (i=p1;i!=NULL;i=i->next)
    {
        p3=p4=create(0,0);
        for (j=p2;j!=NULL;j=j->next)
        {
            p3->next=create(i->coeff*j->coeff,i->exp*j->exp);
            p3=p3->next;
        }
        p5=addpoly(p5,p4->next);
    }
    return p5;
}
void main()
{
    struct node *p1=NULL,*p2=NULL,*pa=NULL,*pb=NULL;
    int ch;
    do
    {
        printf("----------------------\n");
        printf("1.Create\n2.Display\n3.Add\n4.Multiply\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("Enter 1st polynomial: ");
                    p1=createpoly();
                    printf("Enter 2nd Polynomial: ");
                    p2=createpoly();
                    break;
            case 2: printf("The values of set A: \n");
                    display(p1);
                    printf("\n");
                    printf("The values of Set B: \n");
                    display(p2);
                    printf("\n");
                    break;
            case 3: p1=addpoly(p1,p2);
                    printf("After Addition: \n");
                    display(pa);
                    break;
            case 4: pb=mulpoly(p1,p2);
                    printf("After Multiplication: \n");
                    display(pb);
                    break;
            case 5: exit(0);
                    break;

        }
    } while (ch<6);
    
}

