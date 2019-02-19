#include<stdio.h>
#include<stdlib.h>

struct node  //as we use this in  all the functions we should define this globally
{
	int data;
	struct node* link;
};

struct node* root = NULL;
int len;
int length();
void append(void);
void addatbegin(void);
void addafter(void);
void display(void);
void delete(void);

void main()

{
	
	int x;
	while(1)
	{
		printf("Single linked list operations \n");
		printf("1-Append\n2-Addatbegin\n3-Addafer\n4-length\n5-display\n6-delete\n7-quit\n");
	    printf("Enter ur choice- ");
	    scanf("%d",&x);
	    
	    switch(x)
	    {
	    	case 1: append();
	    		    break;
	    		    
	    	case 2: addatbegin();
					break;
			
			case 3: addafter();		
					break;
					
			case 4: len=length();
					printf("length=%d",len);
					
			case 5: display();			
					break;
					
			case 6: delete();
					break;
			
			
			default: printf("Invalid option\n");
						    
		}
	}
	
	
}

void append()
{
	struct node *temp, *p;
	temp=(struct node*)malloc(sizeof(struct node)); 
	printf("enter data-");
	scanf("%d",temp->data);
	
	if(root==NULL)
	{
		root=temp;
	}
	
	else
	{
		p=root; //store root value in p
		
		while(p->link!=NULL)
		{
			p=p->link;
		}
		
		p->link=temp; //temp value stored in p
		
	}
	
	}
	
	int length()
	{
		struct node *temp;
		int count=0;
		temp=(struct node*)malloc(sizeof(struct node));
		temp=root;
		
		while(temp != NULL)
		{
			count++;
			temp=temp->link;
		}
		
		return count;
	}
	
	void display()
	{
		 struct node* temp;
		 temp=root; 
		if(temp==NULL)
		{
			printf("\nList is empty\n");
		}
		
		else
		{
			while(temp != NULL)
			{
				temp=temp->link;
				printf("%d-->",temp->data);
				
			}
			printf("\n");
		}
	}
	
	void addatbegin()
	{
	  struct node *temp, *p;
	  int loc,len,i=1;
	  printf("Enter location- ");
	  scanf("%d",&loc);
	  
	  if(loc>len)
	  {
	  	printf("\ninvalid location\n");
	  }
	  
	  else
	  {
	  	p=root;
	  	
	  	while(i<(loc-1))
	  	{
	  		p=p->link;
	  		i++;	
		}
		
	  }
	  	
	  temp=(struct node*)malloc(sizeof(struct node));
	  printf("Enter data- ");
	  scanf("%d",&temp->data);
	  
	  
			if(root==NULL)
			{
				root=temp;
			}
	
	       else
	       {
	       	temp->link=p->link;
	       	p->link=temp;
		   }
	}
	
	
	void addafter()
	{
		struct node *temp, *p;
		int loc,len,i=1;
		
		printf("enter location- ");
		scanf("%d",&loc);
		
		if(loc>len)
		{
			printf("Invalid location\n");
		}
		else
		{
			p=root;
			
			while(i<loc)
			{
				p=p->link;
				i++;
			}
			
			temp=(struct node*)malloc(sizeof(struct node));
			printf("Enter data- ");
			scanf("%d",&temp->data);
			
			if(root==NULL)
			{
				root=temp;
			}
	
	       else
	       {
	       	temp->link=p->link;
	       	p->link=temp;
		   }
			
		}
		
	}
	
	void delete()
	{
		struct node *temp, *p;
		int loc;
		
		printf("Enter the location of node to be deleted- ");
		scanf("%d",&loc);
		 
		 if(loc>length())
		 {
		 	printf("invalied location\n");
		 }
		
		else if(loc==1)
		{
			temp=root;
			root=temp->link;
			temp->link=NULL;
			
			free(temp);
		}
		
		else
		{
		 	struct node *p, *q;
		 	int i=1;
		 	
		 	p=root;
		 	
		 	while(i<loc-1)
		 	{
		 		p=p->link;
		 		i++;
			}
			 q=p->link;
			 
			 p->link=q->link;
			 q->link=NULL;
			 
			 free(q);
			 
		}
		
	}
	





















