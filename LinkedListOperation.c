// Operations on N nodes (singly linked list)
#include<stdio.h>
#include<stdlib.h>
struct node {
     int data;
    // char roll[50];
    struct node *next;
};
struct node* creatennodes(int n)
{
    struct node *l[200];
    int i;
    for (i=0;i<n;i++)
    {
        l[i]=(struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&l[i]->data);
        l[i]->next=NULL;
    }
    for (i=0;i<n-1;i++)
    {
        l[i]->next=l[i+1];
    }
    return *l;
}
void display(struct node *l)
{
    while (l!=NULL)
    {
        printf("data: %d\n",l->data);
        l=l->next;
    }
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
void deleteend(struct node *l)
{
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
    int to_set=0;
    struct node *l1;
    // struct node *previous;
    l1=l;
    struct node *temp;
    while (to_set==0)
    {
        if (l->next->data==value) // Finding Whether the value matches to the required value a head of that node.
        {
            printf("Deleting the node: %d",value);
            temp = l->next;
            l->next=l->next->next;
            to_set=1;
            break;
        }
        l=l->next;
    }
    return l1;
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
            l=l->next;
        }
        return new1;
}
int count(struct node *l)
{
    int total;
    while (l!=NULL)
    {
        total=total+1;
        l=l->next;
    }
return total;
}
int main()
{
    struct node *l;
    struct node *l1;
    int n,x,element,value;
    do
    {
        printf("Choose from the below options: \n");
        printf("1. To Insert \n");
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
        scanf("%d",&x);
        switch (x)
        {
            case 1: printf("Creating a list: \n");
                    printf("Enter total nodes: \n");
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
                    deleteend(l);
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
            case 10:    printf("To insert after a value: \n");
                        printf("Enter the element to insert: ");
                        scanf("%d",&element);
                        printf("Enter the value to insert after: ");
                        scanf("%d",&n);
                        l=insertaftervalue(l,element,n);
                        printf("After inserting at value: \n");
                        display(l);
                        break;
            case 11: n=count(l);
                    printf("The total count: %d\n",&n);
                    break;
        }
    } while (x<20);
}