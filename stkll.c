#include<stdio.h>
struct node
{
  int data;
  struct node *next;
  };
 struct node *top=NULL;
void pushs(int a)
{
  struct node *t=(struct node *)malloc(sizeof(struct node));
  t->data=a;
  t->next=NULL;
  if(t==NULL)
    printf("stack overflow");
    t->next =top;
    top=t;
  }
int  pops()
 {if(top==NULL)
    printf("stack underflow");
   struct node *temp=top;
   int a=temp->data;
   top=top->next;
   free(temp);
   return a;
   }
void displaysl()
   {
     struct node *t=top;
     while(t!=NULL)
     {
       printf("%d ",t->data);
       t=t->next;
     }
     printf("\n");
   }
void stackll()
{
  int c,d,p;
  while(1)
  {
    printf("1.push\n2.pop\n3.display\n4.exit\nenter ur choice:");
    fflush(stdin);
    scanf("%d",&c);
    system("cls");
    switch(c)
    {
        case 1:
              printf("enter element to be pushed");
              scanf("%d",&d);
              pushs(d);
              break;
        case 2:
              p=pops();
              printf("poped item is:%d\n",p);
              break;
        case 3:
              printf("list is:");
              displaysl();
              break;
        case 4:
              return;
              break;

      }
    }
}

