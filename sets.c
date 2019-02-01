#include<stdio.h>
#include<stdlib.h>
#include"sets.h"

int size(node* lptr)
{
	int count=0;
	while(lptr!=NULL)
	{
		count++;
		lptr=lptr->next;
	}
	
return count;
}
void is_empty(node* lptr)
{
	if(lptr==NULL)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
node* create()
{
	node* tptr;
	tptr=NULL;
	return tptr;

}
int is_element_of(node* lptr,int x)
{	
	node *nptr;
	nptr=lptr;
	int flag=0;
	if(lptr==NULL)
	{
		printf("This is an empty set\n");
	}
	else
	{
		while(nptr!=NULL)
		{
			if(nptr->data==x)
			{
				flag=1;
			}
			nptr=nptr->next;
		}
		
	
		
	}	
	return flag;

}
node* add(node* lptr,int x)
{
	node* nptr;
	nptr=(node*)malloc(sizeof(node));
	if(is_element_of( lptr, x))
	{
		printf("This is an element of set\n");
	}
	else
	{
		printf("added\n");
		if(nptr!=NULL)
		{
			nptr->data=x;
			nptr->next=lptr;
			lptr=nptr;
		}
	}
return lptr;


}
void  intersection(node* lptr1,node* lptr2)
{
	
	node* nptr1=lptr1;
	node* nptr2=lptr2;
	int flag=0,d;
	while(nptr1!=NULL)
	{
		d=nptr1->data;
		while(nptr2!=NULL&&flag==0)
		{	
			if(nptr2->data==d)
			{
				printf("%d\n",d);
				
				flag=1;
			}
			nptr2=nptr2->next;
		}
		nptr2=lptr2;
		flag=0;
		nptr1=nptr1->next;

		
	}


	
}
void  difference(node* lptr1,node* lptr2)
{
	node* kptr=NULL;
	node* nptr1=lptr1;
	node* nptr2=lptr2;
	int flag=0,d;
	while(nptr1!=NULL)
	{
		d=nptr1->data;
		while(nptr2!=NULL&&flag==0)
		{	
			if(nptr2->data==d)
			{
				
				flag=1;
			}
			nptr2=nptr2->next;
		}
		if(flag==0)
		{
			add(kptr,d);
			printf("%d\n",d);
		}
		nptr2=lptr2;
		flag=0;
		nptr1=nptr1->next;

		
	}
	
}
void subset(node* lptr1,node* lptr2)
{
	
	int count=0;
	node* nptr1=lptr1;
	node* nptr2=lptr2;
	int flag=0,flag2=0,d;
	while(nptr1!=NULL)
	{
		d=nptr1->data;
		while(nptr2!=NULL)
		{	
			if(nptr2->data==d)
			{
				
				count++;
			}
			nptr2=nptr2->next;
		}
		
		nptr2=lptr2;
		
		nptr1=nptr1->next;
	}
		if(size(lptr2)==count)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	
	
}

void Remove(node** llp,int x)
{
	node *temp=*llp,*prev;
	if(temp!=NULL&&temp->data==x)
	{
		*llp=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL&&temp->data!=x)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		return;
	}
	prev->next=temp->next;
	free(temp);
}
node* build(int x,node* lptr)
{
	int i,no,n;
	for(i=0;i<x;i++)
	{
		scanf("%d",&no);
		lptr=add(lptr,no);
	}
return lptr;
}

void enumerate(node* lptr)

{
	printf("\n\n");
	//rearrange(&lptr);
	while(lptr!=NULL)
	{
		printf("%d\n",lptr->data);
		lptr=lptr->next;
	}
}
void Union(node* lptr1,node* lptr2)
{
	difference(lptr1,lptr2);
	difference(lptr2,lptr1);
	intersection(lptr1,lptr2);
}

void rearrange(node **head) 
{ 
    
    node *slow = *head, *fast = slow->next; 
    while (fast && fast->next) 
    { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
  
    node *head1 = *head; 
    node *head2 = slow->next; 
    slow->next = NULL; 
  
   
    reverselist(&head2); 
  
   
    *head = (node*)malloc(sizeof(node)); 
  
 
    node *curr = *head; 
    while (head1 || head2) 
    { 
       
        if (head1) 
        { 
            curr->next = head1; 
            curr = curr->next; 
            head1 = head1->next; 
        } 
  
      
        if (head2) 
        { 
            curr->next = head2; 
            curr = curr->next; 
            head2 = head2->next; 
        } 
    } 
  

    *head = (*head)->next; 
} 
void reverselist(node **head) 
{ 
   
    node *prev = NULL, *curr = *head, *next; 
  
    while (curr) 
    { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
  
    *head = prev; 
} 



