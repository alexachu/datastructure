#include<conio.h>
#include<stdio.h>
	int stack[100],top,choice,n,x,i;
	void push(void);
	void pop(void);
	void display(void);
	void main()
	{
		clrscr();
		top=-1;
		printf("Enter the size of stack:");
		scanf("%d",&n);
		printf("Stack operation using array:");
		printf("\n\t..........................");
		printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT\n");
		do
		{
			printf("\nEnter the choice:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
				{
					push();
					break;
				}
				case 2:
				{
					pop();
					break;
				}
				case 3:
				{
					display();
					break;
				}
				case 4:
				{
					exit(0);
				}
				default:printf("Invalid operation\n");
			}
		}while(choice!=4);
		getch();
	}
		void push()
		{
			if(top>=n-1)
			{
				printf("Stack is overflow\n");
			}
			else
			{
				printf("Enter the element:");
				scanf("%d",&x);
				top++;
				stack[top]=x;
			}
		}
		void pop()
		{
			if(top<=-1)
			{
				printf("Stack is underflow\n");
			}
			else
			{
			printf("The popped element is %d\n",stack[top]);
			top--;
			}
		}
		void display()
		{
			if(top>=0)
			{
				printf("The elements of the stack:\n");
				for(i=top;i>=0;--i)
				printf("\n%d",stack[i]);
			}
			else
			{
			printf("The stack is Empty\n");
			}
		}
OUTPUT

Enter the size of stack:4
Stack operation using array:
	..............................
	1.PUSH
	2.POP
	3.DISPLAY
	4.EXIT
Enter the choice:1
Enter the element:6

Enter the choice:1
Enter the element:8

Enter the choice:1
Enter the element:4

Enter the choice:2
The popped element is 4

Enter the choice:3
The elements of the stack:

8
6
Enter the choice:


