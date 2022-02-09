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
struct node * ial(struct node *l,int val,int x)
{
	struct  node *l1=l,*t=NULL;
	int c,i;
	c=count(l);
	if (x < l || x>(c+1))
	{
		printf("Intersetion not possible: ");
		return l;
	}
	t=create(val);
	if (x==1)
	{
		l=iab(l,val);
		return l;
	}
	for (i=-1;i<(x-1);i++)
	{
		l=l->next;
	}
	t->next=l->next;
	l->next=t;
	return l1;
}
struct node *dab(struct node *l)
{
	struct node *l1=l;
	if (l==NULL)
	{
	printf("Deletion not possible: ");
	return l;
	}
	if (l->next==l)
	{
	return NULL;
	}
	while (l->next!=l1)
	{
		l=l->next;
	}
	l->next=l1->next;
	return l1->next;
}
struct node *dae(struct node *l)
{
	struct node *l1=l;
	if (l==NULL)
	{
		printf("Deletion not possible: ");
		return l;
	}
	if (l->next==l)
	{
		return NULL;
	}
	while (l->next->next !=l1)
	{
		l=l->next;
	}
	l->next=l1;
	return l1;
}
struct node *dav(struct node *l,int val)
{
	struct node *l1=l,*pre=NULL;
	if (l==NULL)
	{
		printf("Deletion not possible: ");
		return l;
	}
	if (l->data==val)
	{
		l=dab(l);
		return l;
	}
	do
	{
		if (l->data==val)
		{
			pre->next=l->next;
			return l1;
		}
		pre=l;
		l=l->next;
	} while (l!=l1);
	printf("Deletion not posible: ");
	return l1;
}
struct node *dap(struct node *l,int pos)
{
	struct node *l1=l;
	int i,c=0;
	c=count(l);
	if (pos < 1 || pos > c || c==0)
	{
		printf("Deletion not possible: ");
		return l;
	}
	if (pos==1)
	{
		return dab(l);
	}
	for (i=1;i<(pos-1);i++)
	{
		l=l->next;
	}	
	l->next=l->next->next;
	return l1;
}
struct node * sort(struct node *l)
{
	struct node *i,*j,*l1=l;
	int t;
	if (l==NULL)
	{
		return NULL;
	}
	for (i=l;i->next!=l1;i=i->next)
	{
		for (j=i->next;j!=l1;i=j->next)
		{
			if (i->data > j -> data)
			{
				t=j->data;
				i->data=i->data;
				i->data=t;
			}
		}
	}
	return l1;
}
struct node * concate(struct node *l1,struct node *l2)
{
	struct node *l3=l1,*l4=l2;
	if (l1==NULL)
	{
		return l2;
	}
	if (l2==NULL)
	{
		return l1;
	}
	l1->next=l2;
	while (l2->next!=l4)
	{
		l2=l2->next;
	}
	l2->next=l3;
	return l3;
}
struct node * reverse(struct node *l)
{
	struct node *lr=NULL,*ld, *l1=l;
	if (l==NULL)
	{
		return NULL;
	}
	do
	{
		l1=iab(lr,l1->data);
		l1=l1->next;
	}while (l1!=l);
	return lr;
}
void reversedisplay(struct node *l)
{
	if (l==NULL)
	{
		return ;
	}
	int c,i=0;
	c=count(l);
	int *p=(int *)malloc(c *(sizeof (int)));
	struct node *l1=l;
	do
	{
		*(p+i)=l->data;
		l=l->next;
		i++;
	}while (l!=l1);
	for (i=(c-1);i>=0;i--)
	{
		printf("%d\n",*(p+i));
	}
}
struct node * merge(struct node *l1,struct node *l2)
{
	struct node *m=NULL,*l;
	l1=concate(l1,l2);
	l1=sort(l1);
	l=l1;
	m=create(l2->data);
	l=l->next;
	while (l!=l1)
	{
	 	if (search(m,l->data)==NULL)
		{
			m=iae(m,l->data);
		}
		l=l->next;
	}
	return m;
}

