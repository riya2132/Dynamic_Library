#include<stdio.h>
typedef enum {true,false} boolean;
struct node
{
    int key;
    struct node *lchild;
    boolean lthread;
    struct node *rchild;
    boolean rthread;
}*root;
struct node *creatett(int data)
{
 struct node *tmp=(struct node *)malloc(sizeof(struct node));
 tmp->lthread=true;
 tmp->key=data;
 tmp->rthread=true;
 tmp->lchild=NULL;
 tmp->rchild=NULL;
 return tmp;
}
struct node* inserttt(struct node *root,int d)
{
    struct node *ptr=root,*tmp,*par=NULL;
    while(ptr!=NULL)
    {
        if(d==ptr->key)
        {
            printf("\nduplicate keys");
            break;
        }
        par=ptr;
        if(d<ptr->key)
        {
            if(ptr->lthread==false)
                ptr=ptr->lchild;
            else
                break;
        }
        else
        {
            if(ptr->rthread==false)
                ptr=ptr->rchild;
            else
                break;
        }
    }
     tmp=creatett(d);
    if(par==NULL)
        root=tmp;
    else if(d<ptr->key)
    {
        tmp->lchild=par->lchild;
        tmp->rchild=par;
        par->lthread=false;
        par->lchild=tmp;
    }
    else
    {
        tmp->rchild=par->rchild;
        tmp->lchild=par;
        par->rthread=false;
        par->rchild=tmp;
    }
    return root;
}
struct node *succ(struct node *ptr)
{
        if(ptr->rthread==true)
            ptr=ptr->rchild;
        else
        {
            ptr=ptr->rchild;
            while(ptr->lthread==false)
                ptr=ptr->lchild;
        }
        return ptr;
}
struct node *pred(struct node *ptr)
{
        if(ptr->lthread==true)
            ptr=ptr->lchild;
        else
        {
            ptr=ptr->lchild;
            while(ptr->rthread==false)
                ptr=ptr->rchild;
        }
        return ptr;
}
void inordertt(struct node *root)
{
    struct node *ptr=root;
    while(ptr->lthread==false)
        ptr=ptr->lchild;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->key);
        ptr=succ(ptr);
    }
}
void preordertt(struct node *root)
{
    struct node *ptr=root;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->key);
        if(ptr->lthread==false)
            ptr=ptr->lchild;
        else if(ptr->rthread==false)
            ptr=ptr->rchild;
        else
        {
            while(ptr!=NULL&&ptr->rthread==true)
                ptr=ptr->rchild;
            if(ptr!=NULL)
                ptr=ptr->rchild;
        }
    }
}
void deletett(struct node *root,int dkey)
{
    struct node *ptr=root,*par;
    while(ptr!=NULL)
    {
        if(dkey==ptr->key)
            break;
        par=ptr;
        if(dkey<ptr->key)
        {
            if(ptr->lthread==false)
                ptr=ptr->lchild;
            else
                break;
        }
        else
        {
             if(ptr->rthread==false)
                ptr=ptr->rchild;
            else
                break;
        }
    }
    if(ptr->lthread==true && ptr->rthread==true)
        root=casea(root,par,ptr);
    else if(ptr->lthread==true || ptr->rthread==true)
        root=caseb(root,par,ptr);
    else
        root=casec(root,par,ptr);
}
void casea(struct node* root,struct node* par,struct node* ptr)
{
    if(par==NULL)
        root=NULL;
    if(ptr==par->lchild)
    {
        par->lchild=ptr->lchild;
        par->lthread=true;
    }
    else
    {
        par->rchild=ptr->rchild;
        par->rthread=true;
    }
    free(ptr);
}
void caseb(struct node* root,struct node* par,struct node* ptr)
{
    struct node *child,*s,*p;
    if(ptr->lthread==false)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    if(par==NULL)
        root=child;
    else if(ptr==par->lchild)
        par->lchild=child;
    else
        par->rchild=child;
    s=succ(ptr);
    p=pred(ptr);
    if(ptr->lthread==false)
        p->rchild=s;
    else
    {
        s->lchild=p;
    }
    free(ptr);
}
void casec(struct node* root,struct node* par,struct node* ptr)
{
    struct node *succ,*presuc;
    presuc=ptr;
    succ=ptr->rchild;
    while(succ->lthread!=true)
    {
        presuc=succ;
        succ=succ->lchild;
    }
    ptr->key=succ->key;
    if(succ->lthread==true&&succ->rthread==true)
        casea(root,presuc,succ);
    else
        caseb(root,presuc,succ);
}
void threadedtree()
{
    int c,d;
    struct node*ptr,*root=NULL;
    while(1)
    {
        printf("\n1.insert node\n2.preorder\n3.inorder\n4.delete\n5.quit\nenter ur choice:");
        scanf("%d",&c);
        system("cls");
        switch(c)
        {
        case 1:
            printf("\nenter data to be inserted:");
            scanf("%d",&d);
            root=inserttt(root,d);
            break;
        case 2:
            preordertt(root);
            break;
        case 3:
            inordertt(root);
            break;
        case 4:
            printf("\nenter node to be deleted:");
            scanf("%d",&d);
            deletett(root,d);
            break;
        case 5:
            return;
        }
    }
}
