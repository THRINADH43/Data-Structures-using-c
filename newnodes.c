#include<stdio.h>
#include<stdlib.h>
struct node {
        int data;
        struct node *next;
};
struct node* create (int x)
{
	
	struct node *l;
	l=(struct node *)malloc(sizeof (struct node));
	l->data=x;
	l->next=NULL;
	return l;
}
struct node* creatennodes(int n)
{
        int i,x;
        struct node *l1,*l2;
        printf("Enter the first node data: ");
        scanf("%d",&x);
        l1=l2=create(x);
        for (i=1;i<n;i++)
        {
        	printf("Enter the next node: ");
        	scanf("%d",&x);
        	l2->next=create(x);
        	l2=l2->next;
        }
        return l1;
}
void display(struct node *l)
{
        while (l!=NULL)
        {
                printf("data: %d\n",l->data);
                l=l->next;
        }
}
int count (struct node *l1)
{
	int c=0;
	while (l1!=NULL)
	{
		c++;
		l1=l1->next;
	}
	return c;
}
void search(struct node *l,int element)
{
        while (l!=NULL)
        {
                if (l->data==element)
                {
                        printf("Element Found: ");
                        break;
                }
                l=l->next;
        }
}
struct node* deleteend(struct node *l)
{
	    struct node *l2;
	    l2=l;
        while (l!=NULL)
        {
                if(l->next->next==NULL)
                {
                        printf("Deleting - %d\n",l->next->data);
                        l->next=NULL;
                        break;
                }
                l=l->next;
        }
        return l2;


}
struct node* deletestart(struct node *l)
{
	    struct node *new;
        printf("Deleting at start: %d\n",l->data);
        new= (struct node *)malloc(sizeof(struct node));
        new=l->next;
        return new;
}
struct node* deleteatvalue(struct node *l, int value)
{
  // Error in performing this do again.
	int to_set=0;
	struct node *l1=l;
	struct node *temp,*pre;
	if(l->data==value)
	{
		printf("Deleted element %d",l->data);
		l=l->next;
		return l;
	}
	
	while (l!=NULL)
	{
 		if (l->data==value)
		{
  			to_set=1;
	 		break;
  		 }
  		 pre=l;
		 l=l->next;	
 	 }
  	if (to_set==0)
 	{
	   printf("Element not found and nodes are not altered \n"); 
	   return l;	
    }
    else
    {
    	pre->next=l->next;
    	return l1;
    }
	 	
}
struct node *deleteatposition(struct node *l1,int pos)
{
	int i;
	struct node *l2;
	l2=l1;
	int b;
	b=count(l1);
	if (l1==NULL)
	{
		printf("Empty list \n");
		return NULL;
	}
	if (pos>b || pos <0)
	{
		printf("Delete at a position is not possible \n");
		return l1;
	}
	if (pos==1)
	{
		l1=deletestart(l1);
		return l1;
	}
	if (pos==b)
	{
		l1=deleteend(l1);
		return l1;
	}
	for (i=0;i<pos-1;i++)
	{
		l1=l1->next;
	}
	l1->next=l1->next->next;
	return l2;
}
struct node * insertatstart(struct node *l, int element)
{
    struct node *new = NULL;
    new = (struct node *)malloc(sizeof(struct node));
    new->data=element;
    new->next=l;
    return new;
    
} 
struct node * insertatend (struct node *l, int element)
{
	struct node *new = NULL;
	struct node *new1;
	new1=l;
	new = (struct node *)malloc(sizeof(struct node));
	new->data=element;
	new->next=NULL;
	while (l!=NULL)
	{
		if (l->next==NULL)
		{
			l->next=new;
			break;
		}
		l=l->next;
	}
	return new1;
}
struct node * insertaftervalue(struct node *l, int element, int value)
{
	struct node *new;
	struct node *new1;
	struct node *previous;
	int to_set=0;
	// previous=l;
	new = (struct node *)malloc(sizeof(struct node));
	new1=l;
	new->data=element;
	new->next=NULL;
	while (l!=NULL)
	{
		if (l->data==value)
		{  
			new->next=l->next;
			l->next=new;
			break;
		}
		else
		{
			to_set=1;
		}
		l=l->next;
	}
	if (to_set==1)
	{
		printf("Value not found and list is not altered: \n");
	}
	return new1;
}
struct node *findpre (struct node *l1, int ele)
{
	struct node *pre;
	if (l1->next==NULL)
	{
		return NULL;
	}
	while ( l1!=NULL)
	{
		if (l1->data==ele)
		{
			break;
		}
		else
		{
			pre = l1;
			l1=l1->next;
		}
	}
		if (l1==NULL)
		{
			return NULL;
		}
		else
		{
			return pre;
		}
	
}
struct node *Insertatposition(struct node *l1,int pos, int x)
{
	struct node *t,*l2;
	int c,i;
	l2=l1;
	c=count(l1);
	if (pos > c+1)
	{
		printf("Insert at a position not possible \n");
		return l1;
	}
	else if (pos==1)
	{
		l1=insertatstart(l1,x);
		return l1;
	}
	else if (c+1 == pos)
	{
		l1=insertatend(l1,x);
		return l1;
	}
	for (i=1;i<pos-1;i++)
	{
		l1=l1->next;
		t=create(x);
		t->next=l1->next;
		l1->next=t;
	}
	return l2;
}
int find(struct node *l,int element)
{
	int i,c,to_set=0;
	c=count(l);
	for (i=0;i<c;i++)
	{
		if (l->data==element)
		{
			to_set=1;
			return i+1;
		}
		l=l->next;
	}
	if (to_set==0)
	{
		printf("Cannot find the element: \n");
		return 0;
	}
	
}
/*struct node* reverse(struct node *l)
{
	struct node *reverse,*temp;
	int value1,value2,to_set=0;
	while (l!=NULL)
	{
		value1=l->data;
		l=l->next;
	}
	while (to_set==1)
	{
		if (l->data==value1)
		{
			reverse=create(l->data);
			temp=l->data;
			value1=
		}
	}
}*/
struct node* concatenate(struct node *l,struct node *l2)
{
	struct node *temp;
	temp=l;
	while (l!=NULL)
	{
		if (l->next==NULL)
		{
			l->next=l2;
			return temp;
		}
		l=l->next;
	}
	
}
int main()
{
    struct node *l;
    struct node *l1;
    struct node *l2;
	struct node *l3;
	int pos;
	int n,x,element,value,c;
	do 
	{
		printf("\n-----------MENU--------------\n");
		printf("1. To create \n");
		printf("2. To display \n");
		printf("3. To exit \n");
		printf("4. Search \n");
		printf("5. Delete at start \n");
		printf("6. Delete at end \n");
		printf("7. Delete at a value \n");
		printf("8. To insert at the start: \n");
		printf("9. To insert at the end: \n");
		printf("10. To insert at after a value: \n");
		printf("11. To konw the total count: \n");
		printf("12. To find the prevous \n");
		printf("13. Insert at a position \n");
		printf("14. Delete at a position: \n");
		printf("15. To find an element: \n");
		printf("16. To concatenate \n");
		printf("Enter your choice: ");
		scanf("%d",&x);
		switch (x)
		{
			case 1: printf("Creating a list: \n");
                    printf("Enter total nodes: ");
                    scanf("%d",&n);
                    l=creatennodes(n);
                    break;
            case 2: printf("Displaying nodes: \n");
                    display(l);
                    break;
            case 3: exit(0);
                    break;
            case 4: printf("Enter element to search: \n");
                    scanf("%d",&element);
                    search(l,element);
                    break;
            case 6: printf("Deleting node at end: \n");
                    l=deleteend(l);
                    printf("After deleting end node: \n");
                    display(l);
                    break;
            case 5: printf("Deleting at start: \n");
                    l=deletestart(l);
                    printf("After Deleting the starting node: \n");
                    display(l);
                    break;
            case 7: printf("Enter the value to delete: \n");
                    scanf("%d",&value);
                    deleteatvalue(l,value);
                    printf("After deleting the value \n");
                    display(l);
                    break;	
            case 8: printf("Inserting at the start: \n");
                    printf("Enter the element to insert: \n");
                    scanf("%d",&element);
                    l=insertatstart(l,element);
                    printf("After inserting at the start: \n");
                    display(l);
                    break;
            case 9: printf("To insert at the end: \n");
                    printf("Enter the element to insert: \n");
                    scanf("%d",&element);
                    l=insertatend(l,element);
                    printf("After Inserting at end: \n");
                    display(l);
                    break;
            case 10: printf("To insert after a value: \n");
                     printf("Enter the element to insert: ");
                     scanf("%d",&element);
                     printf("Enter the value to insert after: ");
                     scanf("%d",&n);
                     l=insertaftervalue(l,element,n);
                     printf("After inserting at value: \n");
                     display(l);
                     break;
            case 11: n=count(l);
			         printf("The total count: %d\n",n);
					 break;
			case 12: printf("Enter the value to find the previous: ");
			         scanf("%d",&n);
					 l2=findpre(l,n);
					 if (l2==NULL)
					 {
 					      printf("Element not found");	
 					 }
 					 else
 					 {
 					 	printf("Element found: %d\n",l2->data);
 					 }
					 break;
		    case 13: printf("Inserting at a position: \n");
			         printf("Enter the postion: ");
					 scanf("%d",&pos);
					 printf("Enter the value to insert: \n");
					 scanf("%d",&x);
					 l=Insertatposition(l,pos,x);
					 printf("After Inserting\n");
					 display(l);
					 break;     
             case 14: printf("Deleting at a position: \n");
			          printf("Enter the position to delete: ");
					  scanf("%d",&pos);
					  l=deleteatposition(l,pos);
					  printf("After deleting: \n");
					  display(l);
					  break;
			case 15:  printf("Enter the element to find: ");
			          scanf("%d",&element);
					  value=find(l,element);
					  printf("Location: %d",value);
					  break;
			case 16: printf("About to Concatenate: \n");
		             printf("Creating a list: \n");
                     printf("Enter total nodes: ");
                     scanf("%d",&n);
                     l2=creatennodes(n);
                     l3=concatenate(l,l2);
                     printf("After concatenation: \n");
                     display(l3);
                     break;
					 			         			                    
		} 
		
	} while (x<20);
}