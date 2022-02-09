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
l=(struct node*)malloc(sizeof(struct node));
l->data=x;
l->next=NULL;
return l;
}

struct node *createNnodes(int n)
{
	struct node *l1,*l2;
	int i,x;
	printf("enter the first node data\n");
	scanf("%d",&x);
	l1=l2=create(x);
	for(i=1;i<n;i++)
	{
		printf("enter the next node data\n");
		scanf("%d",&x);
		l2->next=create(x);
		l2=l2->next;
	}
	l2->next=l1;
	return l1;
}

void display(struct node *l1)
{
	struct node *l2=l1;
	if(l1==NULL)
	{
		printf("empty list\n");
		
	}
	printf("%d\n",l1->data);
	l2=l2->next;
	while(l2!=l1)
	{
		printf("%d\n",l2->data);
		l2=l2->next;
	}
}

int countnodes(struct node *l1)
{
	struct node *l2=l1;
	int c=0;
	if(l1==NULL)
	return 0;
	do
	{
		c++;
		l2=l2->next;
	}while(l2!=l1);
	return c;
}
struct node *findserch(struct node *l1,int x)
{
	
	struct node *l2=l1;
	if(l1==NULL)
	{
		
		return l1;
	}
	while(l1!=l2)
	{
		
		if(l1->data==x)
		break;
		l1=l1->next;
	}
	return l1;
}
struct node *findprevious(struct node *l1,int x)

{
	
	struct node *l2=l1,*p;
	if(l1==NULL)
	   return NULL;
    if(l1->next=l1)
    return l1;
    do
    {
    	p=l1;
    	l1=l1->next;
    	if(l1->data=x)
    	return p;
    }while(l1!=l2);
     return NULL;
}
struct node* IAB(struct node *l,int x)
{
        struct node *t,*l2=l;
        t=create(x);
        if(l==NULL)
        {
                t->next=t;
                return t;
        }
        while(l2->next!=l)
        {
                l2=l2->next;
        }
        t->next=l;
        l2->next=t;
        return t;
}
struct node* IAE(struct node *l,int x)
{
        struct node *l2=l,*t;
        t=create(x);
        if(l==NULL)
        {
                t->next=t;
                return t;
        }
        while(l2->next!=l)
        {
                l2=l2->next;
        }
        t->next=l2->next;
        l2->next=t;
        return l;
}
struct node* IAV(struct node *l,int v,int x)
{
        struct node *l1,*t;
        t=create(x);
        if(l==NULL)
                return l;
        l1=findserch(l,v);
        if(l1==NULL)
                return l1;
        t->next=l1->next;
        l1->next=t;
        return l;
}
struct node* IAP(struct node *l,int p,int x)
{
        int c,i;
        struct node *l2=l,*l1,*t;
        t=create(x);
        c=countnodes(l);
        if(c==0&&p==1)
        {
                t->next=t;
                return t;
        }
        if(c==0||p<=0||p>c+1)
                return l;
        if(p==1)
        {
                l1=IAB(l,x);
                return l1;
        }
        if(c==c+1)
        {
                l1=IAE(l,x);
                return l1;
        }
        for(i=1;i<p-1;i++)
        {
                l=l->next;
        }
        t->next=l->next;
        l->next=t;
        return l2;
}
struct node* DAB(struct node *l)
{
        struct node *l2=l;
        if(l==NULL)
                return NULL;
        if(l->next==l)
                return NULL;
        while(l2->next!=l)
        {
                l2=l2->next;
        }
        l2->next=l->next;
        return l->next;
}
struct node* DAE(struct node *l)
{
        struct node *l2=l;
        if(l==NULL||l->next==l)
                return NULL;
        while(l->next->next!=l2)
        {
                l=l->next;
        }
        l->next=l2;
        return l2;
}
struct node* DAV(struct node *l,int v)
{
        struct node *l2;
        if(l==NULL||l->data==v)
                return NULL;
        l2=findprevious(l,v);
        if(l2==NULL)
                return l;
        if(l2->next==l)
        {
                l=DAB(l);
                return l;
        }
        l2->next=l2->next->next;
        return l;
}
struct node* DAP(struct node *l,int p)
{
        int i,n;
        struct node *l2=l;
        if(l==NULL)
                return l;
        n=countnodes(l);
        if(p<=0||p>n)
                return l;
        if(p==1)
        {
                l=DAB(l);
                return l;
        }
        if(p==n)
        {
                l=DAE(l);
                return l;
        }
        for(i=1;i<p-1;i++)
        {
                l=l->next;
        }
        l->next=l->next->next;
        return l2;
}
struct node* sort(struct node *l)
{
        struct node *l2=l,*i,*j;
        int t;
        for(i=l;i->next!=l2;i=i->next)
        {
                for(j=i->next;j!=l2;j=j->next)
                {
                        if(i->data>j->data)
                        {
                                t=i->data;
                                i->data=j->data;
                                j->data=t;
                        }
                }
        }
        return l2;
}

main()
{
	int n,ch,b,ele,x,pos;
	struct node *l1,*l2;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	do
	{
		
		printf("1:create a node\n");
		printf("2:display\n");
		printf("3:count\n");
		printf("4:find element\n");
		printf("5:findprevious\n");
		printf("6:insert an element at beginning\n");
		printf("7:inserting an element at the end\n");
		printf("8:inserting after a value\n");
		printf("9:inserting after a particular value\n");
		printf("10:delete the beginning value of the list\n");
		printf("11:deleting the last node of the list\n");
		printf("12:delete after a particular value\n");
		printf("13:deletion at particular position\n");
		printf("14:sorting a linked list\n");
		printf("15:exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			        
			        l1=createNnodes(n);
			        break;
			case 2:printf("dispalying the node values\n");
			       display(l1); 
			       break;
			 case 3:b=countnodes(l1);
			      printf("total no. of nodes=%d\n",b);
				  break; 
			case 4: printf("enter the searching element\n");
			        scanf("%d",&ele);
			        l1=findserch(l1,ele);
                    if(l1==NULL)
		          	printf("element not found\n");
			        else
		          	printf("element found\n");
		         	break;	
			case 5: printf("enter the element\n");
			         scanf("%d",&ele);
			         l2=findprevious(l1,ele);
		             if(l2==NULL)
			         printf("element not found\n");
			         else
			         printf("previous element =%d\n",l2->data);
			         break;
			 case 6: printf("enter the node value\n");
			         scanf("%d",&x);
			         l1=IAB(l1,x);
			         printf("displaying the values after insertion\n");
			         display(l1);
			         break;
			 case 7: printf("enter the element value\n");
			         scanf("%d",&x);
					 l1=IAE(l1,x);
					 printf("displaying after insertion\n");
					 display(l1);
					 break;   
			case 8:  printf("enter the value of the element\n");
			         scanf("%d",&ele);
					 printf("enter the node value\n");
					 scanf("%d",&x);
					 l1=IAV(l1,x,ele);
					 printf("displaying after insertion process\n");
					 display(l1);
					 break;
			case 9:  printf("enter the position where you want to insert\n");
			         scanf("%d",&pos);
					 printf("enter the node value\n");
					 scanf("%d",&x);
					 l1=IAP(l1,pos,x);
					 printf("displaying after insertion\n");
					 display(l1);
					 break;
			case 10: l2=DAB(l1);
			         display(l2);
					 break;
			case 11: l1=DAE(l1);
                     printf("after deleting the last node the list is\n");
			         display(l1);
					 break;	
			case 12: printf("enter the value\n");
			         scanf("%d",&ele);
					 l1=DAV(l1,ele);
					 printf("after deletion\n");
					 display(l1);
					 break;	
			case 13: printf("enter the position to delete\n");
			         scanf("%d",&pos);
					 l1=DAP(l1,pos);
					 printf("after deletion\n");
					 display(l1);
					 break;
			case 14: l1=sort(l1);
			         printf("selection sort\n");
					 display(l1);
					 break;		 		 	 	 		 	 		       
			case 15: exit(0);
			         break;
		}
		} while(ch<15); 
}
