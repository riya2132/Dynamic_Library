#define MAX 20
int priqueue[MAX];
int front=-1;
int rear=-1;
void check(int data)
{
	int i,j;
	for(i=0;i<=rear;i++)
	{
		if(data>=priqueue[i])			//element with higher priority at front end always
		{
		for(j=rear+1;j>i;j--)
		{
			priqueue[j]=priqueue[j-1];
		}
		priqueue[i]=data;
		return;
		}
	}
priqueue[i]=data;
}
void insertpq(int data)
{
	if(front==-1&&rear==-1)				//inserting first element
	{
		front=0;
		rear=0;
		priqueue[rear]=data;
		return;
	}
	else						//elements inserted acc to priority
		check(data);
	rear=rear+1;
}
void deletepq(int item)
{
	if(front==-1 && rear==-1)
		{printf("\nqueue empty");
			return;
		}
	int i,j;
	for(i=0;i<rear;i++)
	{
	if(item==priqueue[i])
	{
		for(j=i;j<=rear;j++)
		{
		priqueue[j]=priqueue[j+1];
		}
	}
	}
	rear=rear-1;
	if(rear==-1)
		front=-1;
}
int noelementspq()
{
	return(rear-front+1);
}
void displaypq()
{
	int i;
	printf("\nqueue elements are:");
	for(i=front;i<=rear;i++)
		printf("%d\n",priqueue[i]);
}
void prique()
{
	int c,d,item;
	while(1)
	{
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.no of elements\n5.exit\nenter ur choice:");
		scanf("%d",&c);
		system("cls");
		switch(c)
		{
			case 1:
				printf("\nenter element to inserted:");
				scanf("%d",&d);
				insertpq(d);
				break;
			case 2:
				printf("\nenter item to be deleted:");
				scanf("%d",&item);
				deletepq(item);
				break;
			case 3:
				displaypq();
				break;
			case 4:
				printf("\nno of elements:%d",noelementspq());
				break;
			case 5:
				return;
		}
 	}
}
