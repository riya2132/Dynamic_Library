#include<stdio.h>
struct node
{  int data;
   struct node *next;
}*last;
struct node* createcl(int x)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;
	return t;
}
void insertbcl(struct node *t)
{
	if(last==NULL)
	{
		last=t;
		last->next=last;
		return;
	}
	struct node *p=last->next;
	t->next=p;
	last->next=t;
}
void insertecl(struct node *t)
{
	t->next=last->next;
	last->next=t;
	last=t;
}
void insertncl(struct node* t,int item)
{
	struct node* p=last->next;
	do
	{
		if(p->data==item)
		{
			t->next=p->next;
			p->next=t;
			if(p==last)
			{
				last=t;
			}
		}
	p=p->next;
	}while(p!=last->next);
}
void deletecl(int item)
{  struct node *t;
	if(last==NULL)
	{
		printf("list is empty");
		return;
	}
	if(last->next==last && last->data==item)
	{
		t=last;
		last=NULL;
		free(t);
		return;
	}
	struct node *p=last->next;
	if(p->data==item)
	{
		struct node *t=p;
		last->next=t->next;
		free(t);
		return;
	}
	while(p->next!=last)
	{
		if(p->next->data==item)
		{
			struct node *t=p->next;
			p->next=t->next;
			free(t);
			return;
		}
	p=p->next;
	}
	if(last->data==item)
	{
		struct node *t=last;
		p->next=last->next;
		last=p;
		free(t);
		return;
	}
}
void printcl()
{
	struct node *p=last->next;
	printf("list is:");
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=last->next);
	printf("\n");
}
void cirll()
{
	int d,c,i;
	struct node*t;
	struct node *last=NULL;
	while(1)
	{
		printf("1.inserting at beginning\n2.inserting at end\n3.inserting at nth pos\n4.del the node\n5.print the list\n6.quit\n");
		printf("enter ur choice:");
		scanf("%d",&c);
		system("cls");
		switch(c)
		{
		case 1:
			printf("enter data to be inserted:");
			scanf("%d",&d);
			t=createcl(d);
			insertbcl(t);
			break;
		case 2:
			printf("enter data to be inserted:");
			scanf("%d",&d);
			t=createcl(d);
			insertecl(t);
			break;
		case 3:
			printf("enter data to be inserted:");
			scanf("%d",&d);
			t=createcl(d);
			printf("enter after which node to be inserted:");
			scanf("%d",&i);
			insertncl(t,i);
			break;
		case 4:
			printf("enter data to be deleted:");
			scanf("%d",&d);
			deletecl(d);
			break;
		case 5:
			printcl();
			break;
		case 6:
			return;
			break;
		}
	}
}
