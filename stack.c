#define MAX 20
int top1=-1;
int stack[MAX];
int isemptys()
{
    if(top1==-1)
        return 1;
    else
        return 0;
}
int isfulls()
{
    if(top1==MAX-1)
        return 1;
    else
        return 0;
}
void push(int data)
{
	if(isfulls())
	{
		printf("stack overflow");
		return;
	}
	stack[++top1]=data;
}
int pop()
{
	if(isemptys())
	{
		printf("stack underflow");
 	}
	int item=stack[top1--];
	return item;
}
void displays()
{
	int i;
	if(top1==-1)
	printf("stack is empty");
	printf("stack elements are:\n");
	for(i=top1;i>=0;i--)
	printf("%d",stack[i]);
printf("\n");
}
void stack1()
{
	int a,c,d,i=0,j,p;
	while(1)
	{
		printf("1.push\n2.pop\n3.display\n4.quit\n\n");
		printf("enter ur choice:");
		scanf("%d",&c);
		system("cls");
		switch(c)
		{
		case 1:
			printf("\nenter element to be pushed");
			scanf("%d",&a);
			push(a);
			break;
		case 2:
			printf("\npoped item is %d",pop());
			break;
		case 3:
			displays();
			break;
		case 4:
			return;
		}
	}
}


