#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *prev;
 struct node *next;
 int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main ()
{#include<stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct dequeue
{
	int data[MAX];
	int rear,front;
}dequeue;

void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueF(dequeue *p,int x);
int dequeueF(dequeue *p);
int dequeueR(dequeue *p);
void print(dequeue *p);

void main()
{
	int i,x,op,n;
	dequeue q;

	initialize(&q);

	do
	{
	printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
	printf("\n6.Print\n7.Exit\n\nEnter your choice:");
	scanf("%d",&op);

	switch(op)
	{
	case 1: printf("\nEnter number of elements:");
	scanf("%d",&n);
	initialize(&q);
	printf("\nEnter the data:");

	for(i=0;i<n;i++)
	{
	scanf("%d",&x);
	if(full(&q))
	{
	printf("\nQueue is full!!");
	exit(0);
	}
	enqueueR(&q,x);
	}
	break;

	case 2: printf("\nEnter element to be inserted:");
	scanf("%d",&x);

	if(full(&q))
	{
	printf("\nQueue is full!!");
	exit(0);
	}

	enqueueR(&q,x);
	break;

	case 3: printf("\nEnter the element to be inserted:");
	scanf("%d",&x);

	if(full(&q))
	{
	printf("\nQueue is full!!");
	exit(0);
	}

	enqueueF(&q,x);
	break;

	case 4: if(empty(&q))
	{
	printf("\nQueue is empty!!");
	exit(0);
	}

	x=dequeueR(&q);
	printf("\nElement deleted is %d\n",x);
	break;

	case 5: if(empty(&q))
	{
	printf("\nQueue is empty!!");
	exit(0);
	}

	x=dequeueF(&q);
	printf("\nElement deleted is %d\n",x);
	break;

	case 6: print(&q);
	break;

	default: break;
	}
	}while(op!=7);
}

void initialize(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}

int empty(dequeue *P)
{
	if(P->rear==-1)
	return(1);

	return(0);
}

int full(dequeue *P)
{
	if((P->rear+1)%MAX==P->front)
	return(1);

	return(0);
}

void enqueueR(dequeue *P,int x)
{
	if(empty(P))
	{
	P->rear=0;
	P->front=0;
	P->data[0]=x;
	}
	else
	{
	P->rear=(P->rear+1)%MAX;
	P->data[P->rear]=x;
	}
}

void enqueueF(dequeue *P,int x)
{
	if(empty(P))
	{
	P->rear=0;
	P->front=0;
	P->data[0]=x;
	}
	else
	{
	P->front=(P->front-1+MAX)%MAX;
	P->data[P->front]=x;
	}
}

int dequeueF(dequeue *P)
{
	int x;

	x=P->data[P->front];

	if(P->rear==P->front)	//delete the last element
	initialize(P);
	else
	P->front=(P->front+1)%MAX;

	return(x);
}

int dequeueR(dequeue *P)
{
	int x;

	x=P->data[P->rear];

	if(P->rear==P->front)
	initialize(P);
	else
	P->rear=(P->rear-1+MAX)%MAX;

	return(x);
}

void print(dequeue *P)
{
	if(empty(P))
	{
	printf("\nQueue is empty!!");
	exit(0);
	}

	int i;
	i=P->front;

	while(i!=P->rear)
	{
	printf("\n%d",P->data[i]);
	i=(i+1)%MAX;
	}

	printf("\n%d\n",P->data[P->rear]);
}
int choice =0;
 while(choice != 9)
 {
 printf("\n*********Main Menu*********\n");
 printf("\nChoose one option from the following list ...\n");
 printf("\n===============================================\n");
 printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last \n 6.Delete at specified\n 7.Search\n 8.Show\n 9.Exit \n");
 printf("\nEnter your choice?\n");
 scanf("\n%d",&choice);
 switch(choice)
 {
 case 1:
 insertion_beginning();
 break;
 case 2:
 insertion_last();
 break;
 case 3:
 insertion_specified();
 break;
 case 4:
 deletion_beginning();
 break;
 case 5:
 deletion_last();
 break;
 case 6:
 deletion_specified();
 break;
 case 7:
 search();
 break;
 case 8:
 display();
 break;
 case 9:
 exit(0);
 break;
 default:
 printf("Please enter valid choice..");
 }
 }
}
void insertion_beginning()
{
 struct node *ptr;
 int item;
 ptr = (struct node *)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 printf("\nEnter Item value");
 scanf("%d",&item);

 if(head==NULL)
 {
 ptr->next = NULL;
 ptr->prev=NULL;
 ptr->data=item;
 head=ptr;
 }
 else
 {
 ptr->data=item;
 ptr->prev=NULL;
 ptr->next = head;
 head->prev=ptr;
 head=ptr;
 }
 printf("\nNode inserted\n");
}

}
void insertion_last()
{
 struct node *ptr,*temp;
 int item;
 ptr = (struct node *) malloc(sizeof(struct node));
 if(ptr == NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 printf("\nEnter value");
 scanf("%d",&item);
 ptr->data=item;
 if(head == NULL)
 {
 ptr->next = NULL;
 ptr->prev = NULL;
 head = ptr;
 }
 else
 {
 temp = head;
 while(temp->next!=NULL)
 {
 temp = temp->next;
 }
 temp->next = ptr;
 ptr ->prev=temp;
 ptr->next = NULL;
 }

 }
 printf("\nnode inserted\n");
 }
void insertion_specified()
{
 struct node *ptr,*temp;
 int item,loc,i;
 ptr = (struct node *)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
 printf("\n OVERFLOW");
 }
 else
 {
 temp=head;
 printf("Enter the location");
 scanf("%d",&loc);
 for(i=0;i<loc;i++)
 {
 temp = temp->next;
 if(temp == NULL)
 {
 printf("\n There are less than %d elements", loc);
 return;
 }
 }
 printf("Enter value");
 scanf("%d",&item);
 ptr->data = item;
 ptr->next = temp->next;
 ptr -> prev = temp;
 temp->next = ptr;
 temp->next->prev=ptr;
 printf("\nnode inserted\n");
 }
}
void deletion_beginning()
{
 struct node *ptr;
 if(head == NULL)
 {
 printf("\n UNDERFLOW");
 }
 else if(head->next == NULL)
 {
 head = NULL;
 free(head);
 printf("\nnode deleted\n");
 }
 else
 {
 ptr = head;
 head = head -> next;
 head -> prev = NULL;
 free(ptr);
 printf("\nnode deleted\n");
 }

}
void deletion_last()
{
 struct node *ptr;
 if(head == NULL)
 {
 printf("\n UNDERFLOW");
 }
 else if(head->next == NULL)
 {
 head = NULL;
 free(head);
 printf("\nnode deleted\n");
 }
 else
 {
 ptr = head;
 if(ptr->next != NULL)
 {
 ptr = ptr -> next;
 }
 ptr -> prev -> next = NULL;
 free(ptr);
 printf("\nnode deleted\n");
 }
}
void deletion_specified()
{
 struct node *ptr, *temp;
 int val;
 printf("\n Enter the data after which the node is to be deleted : ");
 scanf("%d", &val);
 ptr = head;
 while(ptr -> data != val)
 ptr = ptr -> next;
 if(ptr -> next == NULL)
 {
 printf("\nCan't delete\n");
 }
 else if(ptr -> next -> next == NULL)
 {
 ptr ->next = NULL;
 }
 else
 {
 temp = ptr -> next;
 ptr -> next = temp -> next;
 temp -> next -> prev = ptr;
 free(temp);
 printf("\nnode deleted\n");
 }
}
void display()
{
 struct node *ptr;
 printf("\n printing values...\n");
 ptr = head;
 while(ptr != NULL)
 {
 printf("%d\n",ptr->data);
 ptr=ptr->next;
 }
}
void search()
{
 struct node *ptr;
 int item,i=0,flag;
 ptr = head;
 if(ptr == NULL)
 {
 printf("\nEmpty List\n");
 }
 else
 {
 printf("\nEnter item which you want to search?\n");
 scanf("%d",&item);
 while (ptr!=NULL)
 {
 if(ptr->data == item)
 {
 printf("\nitem found at location %d ",i+1);
 flag=0;
 break;
 }
 else
 {
 flag=1;
 }
 i++;
 ptr = ptr -> next;
 }
 if(flag==1)
 {
 printf("\nItem not found\n");
 }
 }

}
