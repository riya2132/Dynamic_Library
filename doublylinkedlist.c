#include<stdio.h>
struct node
{
	int inf;
	struct node *prev;
	struct node *next;
};
struct node *head;
struct node *createdl(int data)
{
	struct node * t=(struct node *)malloc(sizeof(struct node));
	t->inf=data;
	t->prev=NULL;
	t->next=NULL;
	return t;
}
void insertbdl(struct node *t)
{
	if(head ==NULL)
	{
		head=t;
		return;
	}
	t->next=head;
	t->prev=NULL;
	head->prev=t;
	head=t;
}
void insertedl(struct node *t)
{
	if(head==NULL)
	{
		head=t;
		return;
	}
	struct node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	t->prev=p;
	p->next=t;
}
void insertafterdl(struct node *t,int item)
{ 	struct node *p=head;
	while(p->next!=NULL)
	{
	if(p->inf==item)
	{
		t->prev=p;
		t->next=p->next;
		p->next->prev=t;
		p->next=t;
	}
	p=p->next;
	}
}
void deletedl(int item)
{
	if(head==NULL)
		{
			printf("list is empty");
			return;
		}
	if(head->inf==item)
	{
		struct node *t;
		t=head;
		head->next->prev=NULL;
		head=head->next;
		free(t);
		return;
	}
	struct node *t=head;
	while(t->next!=NULL)
	{
		if(t->inf==item)
		{
			struct node* tm;
			tm=t;
			tm->prev->next=tm->next;
			tm->next->prev=tm->prev;
			free(tm);
		}
	t=t->next;
	}
	if(t->inf==item)
	{
		t->prev->next=NULL;
		free(t);
		return;
	}
}
void reversedl()
{
	struct node *p,*q;
	p=head;
	q=p->next;
	p->next=NULL;
	p->prev=q;
	while(q!=NULL)
	{
		q->prev=q->next;
		q->next=p;
		p=q;
		q=q->prev;
	}
	head=p;
}
void printdl()
{  struct node *temp=head;
   printf("list is:");
   while(temp!=NULL)
   {
         printf("%d ",temp->inf);
         temp=temp->next;
   }
   printf("\n");
}
void doublyll()
{ 	head=NULL;
	int c,a,item;
	struct node *t;

	while(1)
	{
		printf("1.insert beginning\n2.insert end\n3.insert at nth pos\n4.del a node\n5.print\n6.reverse\n7.quit\n");
		printf("enter ur choice:");
		scanf("%d",&c);
		system("cls");
	switch(c)
	{
	case 1:
		printf("enter element to be inserted:");
		scanf("%d",&a);
		t=createdl(a);
		insertbdl(t);
                break;
	case 2:
		printf("enter element to be inserted:");
		scanf("%d",&a);
		t=createdl(a);
		insertedl(t);
		break;
	case 3:
		printf("enter element to be inserted:");
		scanf("%d",&a);
		t=createdl(a);
		printf("enter item after which u want to insert:");
		scanf("%d",&item);
		insertafterdl(t,item);
		break;
	case 4:
		printf("enter item to be deleted");
		scanf("%d",&item);
		deletedl(item);
		break;
	case 5:
		printdl();
		break;
	case 6:
		reversedl();
		printdl();
		break;
	case 7:
		return;
		break;
	}
	}
}

