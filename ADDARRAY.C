#include<conio.h>
#include<stdio.h>
void main()
{
	int arr1[50],arr2[50],arr3[100],m,n,i,j,k;
	clrscr();
	printf("Enter the size of the array1:");
	scanf("%d",&m);
	printf("Enter sorted elements of array1:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter the size of the array2:");
	scanf("%d",&n);
	printf("Enter sorted elements of array2:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr2[i]);
	}
	i=0;
	j=0;
	k=0;
	while(i<m && j<n)
	{
		if(arr1[i] <= arr2[j])
		{
			arr3[k]=arr1[i];
			i++;
			k++;
		}
		else
		{
			arr3[k]=arr2[j];
			k++;
			j++;
		}
	}
	while(j<n)
		{
			arr3[k]=arr2[j];
			j++;
			k++;
		}
		while(i<m)
		{
			arr3[k]=arr1[i];
			i++;
			k++;
		}
	printf("Merged array is:");
	for(i=0;i<m+n;i++)
	{
		printf("%d",arr3[i]);
	}
	getch();
}
OUTPUT

Enter the size of the array1:5
Enter sorted elements of array1:2
3
4
5
6
Enter the size of the array2:3
Enter sorted elements of array2:6
8
9
Merged array is:23456689
