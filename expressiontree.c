#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int tope=-1;
struct node* stack[MAX];
struct node
{
    int value;
    struct node *lchild;
    struct node *rchild;
};
void pushe(struct node *ptr)
{
	if(tope==(MAX-1))
	{
		printf("stack overflow");
		return;
	}
	stack[++tope]=ptr;
}
struct node* pope()
{
	if(tope==-1)
	{
		printf("stack underflow");
 	}
	struct node* item=stack[tope--];
	return item;
}
void inordere(struct node *root)
{
    if(root==NULL)
            return;
        inorder(root->lchild);
        printf("%c ",root->value);
        inorder(root->rchild);
}
struct node *createex(int x)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->value=x;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
int op(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
        return 1;
        else
        return 0;
}
struct node *createtree(char *a)
{
    int i;
    struct node *temp,*t,*r,*s,*root;
    for(i=0;i<strlen(a);i++)
    {
        if(!op(a[i]))
        {  t=createex(a[i]);
           pushe(t);
        }
        else
        {
            r=pope();
            s=pope();
            temp=createex(a[i]);
            temp->rchild=r;
            temp->lchild=s;
            pushe(temp);
        }
    }
    root=pope();
    return root;
}
void exptree()
{
    struct node *root;
    char *postfix="abc*-def/+/";

    root=createtree(postfix);
    printf("\ninorder traversal of postfix expression :");
    inordere(root);
    return;
}
