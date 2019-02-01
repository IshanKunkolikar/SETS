#ifndef XYZ
#define XYZ

typedef struct Node_tag
{
	int data;
	struct Node_tag* next;
	
} node;

node* create();
int is_element_of(node* lptr,int x);
node* add(node* lptr,int x);
void intersection(node* lptr1,node* lptr2);
void   difference(node* lptr1,node* lptr2);
void  subset(node* lptr1,node* lptr);
void Remove(node** lptr,int x);
node* build(int x,node* lptr);
void is_empty(node* lptr);
void enumerate(node* lptr);
int size(node* lptr);
void Union(node*,node*);
void rearrange(node **head);
void reverselist(node **head) ;


#endif 
