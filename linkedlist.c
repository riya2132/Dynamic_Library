#include<stdio.h>
struct node
{  int data;
   struct node *next;
}*head;
void insertbll(int x)
{
struct node* t=(struct node *)malloc(sizeof(struct node));
t->data=x;
t->next=NULL;
t->next=head;
head=t;
}
void insertell(int x)
{  struct node *t=(struct node*)malloc(sizeof(struct node));
   (*t).data=x;
   (*t).next=NULL;
   if(head==NULL)
   {
   head=t;}
else{
   struct node* temp=head;
   while(temp->next!=NULL)
       {
         temp=temp->next;
       }
    temp->next=t;
    }
}
void insertnll(int x,int n)
{  struct node *t=(struct node*)malloc(sizeof(struct node));
   (*t).data=x;
   (*t).next=NULL;
   if(n==1)
{  t->next=head;
   head=t;
   return;
}
struct node *temp=head;
int i;
for(i=0;i<n-2;i++)
{
      temp=temp->next;
}
      t->next=temp->next;
      temp->next=t;


}
void printll()
{  struct node *temp=head;
   printf("\nlist is:");
   while(temp!=NULL)
   {
         printf("%d ",temp->data);
         temp=temp->next;
   }
   printf("\n");
}
void deletell(int n)
{       int i;
        struct node *temp=head;
        if(n==1)
        {
             head=temp->next;
             return;
        }
        for(i=0;i<n-2;i++)
        {
               temp=temp->next;
        }
        struct node*t=temp->next;
        temp->next=temp->next->next;
        free(t);

}
void searchll(int x)
{
	struct node*t=head;
	int i=0;
	while(t!=NULL)
	{     i++;
		if(t->data==x)
			{
			printf("pos=%d\n",i);
			return;
		}
		t=t->next;
        }
}
void reversell()
{
	struct node *c,*prev,*t;
	c=head;
	prev=NULL;
	while(c!=NULL)
	{
		t=c->next;
		c->next=prev;
		prev=c;
		c=t;
	}
 	head=prev;
}
void linkedlist()
{
head=NULL;
int i,n,t,m,x,c;
while(1)
{
printf("\n1.inserting at beginning\n2.inserting at end\n3.inserting at nth pos\n4.del the node\n5.search pos of element\n6.reverse the list\n7.display\n8.quit\nenter ur choice:");
scanf("%d",&t);
system("cls");
switch(t)
{
case 1:
       printf("\nenter no of nodes to be inserted:");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {printf("\nenter element:");
        scanf("%d",&x);
        insertbll(x);
       }
       break;
case 2:
        printf("\nenter no of nodes to be inserted:");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {printf("\nenter element:");
        scanf("%d",&x);
        insertell(x);
        }
        break;
case 3:
       printf("\nenter element:");
        scanf("%d",&x);
        printf("\nenter pos:");
        scanf("%d",&m);
        insertnll(x,m);
        break;
case 4:
       printf("\nenter node to be deleted:");
       scanf("%d",&m);
       deletell(m);
        break;
case 5:
	printf("\nenter data to be searched:");
 	scanf("%d",&x);
	searchll(x);
    break;
case 6:
	reversell();
	break;
case 7:
    printll();
    break;
case 8:
    return;
}
}
}
