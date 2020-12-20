#include<conio.h>
#include<stdio.h>
#define MAX 10
int cq[MAX];
int item;
int front=-1;
int rear=-1;
void insert();
void display();
int del();
int main()
{
	int choice,item;
	clrscr();
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("Enter the element:");
			scanf("%d",&item);
			insert(item);
			break;
		case 2:del();
			break;
		case 3:display();
			break;
		case 4:exit(4);
		default:printf("wrong choice");
		}
	}
}
void insert(int item)
{
	if(front==(rear+1)%MAX)
	{
		printf("circular queue is overflow\n");
	}
	else
	{
		if(rear==-1)
		{
			rear=front=0;
		}
		else
		{
		rear=(rear+1)%MAX;
		}
		cq[rear]=item;
	}
}
int del()
{
	if(front==-1)
	{
		printf("circular queue is empty\n");
	}
	else
	{
	item=cq[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=(front+1)%MAX;
	}

}
 return item;
}
void display()
{
	int i;
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",cq[i]);
		}
	}
	else
	{
		for(i=front;i<MAX;i++)
		{
			printf("%d\n",cq[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d\n",cq[i]);
		}
	}
}
OUTPUT

1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:1
Enter your element:4
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:1
Enter your element:6
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:1
Enter your element:9
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:2
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:3
6
9




