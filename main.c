
#include<stdio.h>
#include<stdlib.h>
#include"sets.h"
int main()
{
	int flag=0;
	int i,x,temp;
	char a='A';
	node* arr[2];
	i=1;

	while((i==1||i==2)&&flag==0)
	{
		
		printf("Do you want to work on set 1 or set 2 \n");
		scanf("%d",&i);
		if(i!=1&&i!=2)
		flag=1;
			
		
	
	
	if(flag==0)
	{
		printf("0:create\n1:build\n2:is element of\n3:Remove\n4:add\n5:is empty\n6:enumerate\n7:size\n");
	printf("8:union\n9:difference(1-2)\n10:intersection\n11:subset(2)\n12:difference(2-1)\n13:subset(1)\n");
	scanf("%d",&x);
		switch(x)
		{
			case 0:
			{
				arr[i]=create();
				break;
			}
			case 1:
			{
				printf("Enter the number of elements\n");
				scanf("%d",&temp);
				arr[i]=build(temp,arr[i]);
				break;
			}
			case 2:
			{
				scanf("%d",&temp);
				temp=is_element_of(arr[i],temp);
				if(temp==1)
				{
					printf("YES\n");
		
				}
				else
				{
					printf("NO\n");
				}
				break;
			}
			case 3:
			{
				scanf("%d",&temp);
				Remove(&arr[i],temp);
				break;
			}
			case 4:
			{
					scanf("%d",&temp);	
					arr[i]=add(arr[i],temp);
					break;
				
			}
			case 5:
			{
					is_empty(arr[i]);
					break;
			}
			case 6:
			{
					enumerate(arr[i]);
					break;
			}
			case 7:
			{
					temp=size(arr[i]);
					printf("%d\n",temp);
					break;
			}
			case 8:
			{
				Union(arr[1],arr[2]);
				break;
			}
			case 9:
			{
				difference(arr[1],arr[2]);	
				break;
			}
			case 10:
			{
				intersection(arr[1],arr[2]);
				break;
			}
			case 11:
			{
				subset(arr[1],arr[2]);
				break;
			}
			case 12:
			{
				difference(arr[2],arr[1]);	
				break;
			}
			case 13:
			{
				subset(arr[2],arr[1]);
				break;
			}
			default:
			{
				int flag=1;
				printf("Wrong Command\n");
				break;
			}
		}
	}
	
	
	
	}
	return 0;
}
