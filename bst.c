#include<stdio.h>
struct node* case_a(struct node *root,struct node *prev,struct node *ptr);
struct node* case_b(struct node *root,struct node *prev,struct node *ptr);
struct node* case_c(struct node *root,struct node *prev,struct node *ptr);
struct node
{
    int key;
    struct node *lchild;
    struct node *rchild;
}*root;
struct node *createbst(int x)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=x;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
struct node* insertbst(struct node *root,int x)
{
    if(root==NULL)
    {
        root=createbst(x);
            return root;
    }

    if(x<root->key)
        root->lchild=insertbst(root->lchild,x);
    else
        root->rchild=insertbst(root->rchild,x);
        return root;
}
void inorder(struct node *root)
{
    if(root==NULL)
            return;
        inorder(root->lchild);
        printf("%d ",root->key);
        inorder(root->rchild);
}
void preorder(struct node *root)
{
    if(root==NULL)
            return;
        printf("%d ",root->key);
        preorder(root->lchild);
        preorder(root->rchild);
}
void postorder(struct node *root)
{
    if(root==NULL)
            return;
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->key);
}
void traversebst(struct node *root)
{
    if(root==NULL)
        return (root->key);
        traversebst(root->rchild);
        printf("%d ",root->key);
        traversebst(root->lchild);
}
struct node* deleten(struct node *root,int key)
{
    struct node *prev,*ptr=root;
    while(ptr!=NULL)
    {
        if(key==ptr->key)
            break;
            prev=ptr;
        if(key<ptr->key)
            ptr=ptr->lchild;
        else
            ptr=ptr->rchild;
    }
    if(prev==NULL)
        printf("\nnot found");
    else if(ptr->lchild==NULL&&ptr->rchild==NULL)    //node has no lchild and rchild i.e leafnode
        root=case_a(root,prev,ptr);
    else if(ptr->lchild==NULL||ptr->rchild==NULL)
        root=case_b(root,prev,ptr);
    else
        root=case_c(root,prev,ptr);
    return root;
}
struct node* case_a(struct node *root,struct node *prev,struct node *ptr)
{
        if(prev==NULL)
            root=NULL;
        else if(ptr=prev->lchild)
            prev->lchild=NULL;
        else
            prev->rchild=NULL;
        free(ptr);
        return root;
}
struct node* case_b(struct node *root,struct node *prev,struct node *ptr)
{
        struct node *child;
        if(ptr->lchild!=NULL)
            child=ptr->lchild;
        else
            child=ptr->rchild;
            if(prev==NULL)
                root=child;
            else if(ptr=prev->lchild)
                prev->lchild=child;
            else
                prev->rchild=child;
            free(ptr);
        return root;
}
struct node* case_c(struct node *root,struct node *prev,struct node *ptr)
{
        struct node *succ,*presuc;
        succ=ptr->rchild;
        presuc=NULL;
        while(succ->lchild!=NULL)
        {
            presuc=succ;
            succ=succ->lchild;
        }
        ptr->key=succ->key;
        if(succ->lchild==NULL && succ->rchild==NULL)
            root=case_a(root,presuc,succ);
        else
            root=case_b(root,presuc,succ);
        return root;
}
int height(struct node *root)
{
    int hleft,hright;
    if(root==NULL)
        return 0;
    hleft=height(root->lchild);
    hright=height(root->rchild);
    if(hleft>=hright)
        return 1+hleft;
    else
        return 1+hright;
}
void bst()
{
    int c,d;
    struct node *root=NULL;
    while(1)
    {
        printf("\n1.insert node\n2.traverse inorder\n3.preorder\n4.postorder\n5.delete node\n6.height\n7.quit\nenter ur choice:");
        scanf("%d",&c);
        system("cls");
        switch(c)
        {
        case 1:
            printf("\nenter data to be inserted:");
            scanf("%d",&d);
            root=insertbst(root,d);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("\nenter data to be deleted:");
            scanf("%d",&d);
            root=deleten(root,d);
            break;
        case 6:
            height(root);
            break;
        case 7:
            return;
        }
    }
}
