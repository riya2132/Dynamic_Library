#define MAX 6
int queue[MAX];
int front3=-1;
int rear3=-1;
int isfulldq()
{
	if(front3==0&&rear3==MAX-1||front3==rear3+1)
		return 1;
	else
		return 0;
}
int isemptydq()
{
	if(front3==-1)
		return 1;
	else
		return 0;
}
void enqueuerear(int d)
{
	if(isfulldq())
		{
		printf("\n overflow");
		}
	if(front3==-1)
		{
		front3=0;
		rear3=0;
		}
	if(rear3==MAX-1)
		rear3=0;
	else
	rear3=rear3+1;
	queue[rear3]=d;
}
int dequeuefront()
{
	if(isemptydq())
		{
		printf("\nunderflow");
		}
	int a=queue[front3];
	if(front3==rear3)
		{
			front3=-1;
			rear3=-1;
		}
	if(front3==MAX-1)
		front3=0;
	else
	front3=front3+1;
	return a;
}
void enqueuefront(int d)
{
	if(isfulldq())
		{
		printf("\n overflow");
		}
	if(front3==-1)
		{
		front3=0;
		rear3=0;
		}
	if(front3==0)
		{
		front3=MAX-1;
		}
	else
	front3=front3-1;
	queue[front3]=d;
}
int dequeuerear()
{
	if(isemptydq())
		{
		printf("\nunderflow");
		exit(1);
		}
	int a=queue[rear3];
	if(front3==rear3)
		{
			front3=0;
			rear3=0;
		}
	 if(rear3==0)
		rear3=MAX-1;
	else
	rear3=rear3-1;
	return a;
}
void displaydq()
{
	int i;
	printf("\nqueue elements are:");
	i=front3;
	if(front3<rear3)
	{
		while(i<=rear3)
		{
		printf("%d ",queue[i]);
		i++;
		}
	}
	else
	{
	while(i<=MAX-1)
		{
		printf("%d ",queue[i]);
		i++;
		}
	i=0;
	while(i<=rear3)
		{
		printf("%d ",queue[i]);
		i++;
		}
	}
}
void dequeue1()
{
	int c,d,item;
	while(1)
	{
		printf("\n1.enqueuerear\n2.enqueuefront\n3.dequeuerear\n4.dequeuefront\n5.display\n6.exit\nenter ur choice:");
		scanf("%d",&c);
		system("cls");
		switch(c)
		{
			case 1:
				printf("\nenter element to be enqueued:");
				scanf("%d",&d);
				enqueuerear(d);
				break;
            case 2:
				printf("\nenter element to be enqueued:");
				scanf("%d",&d);
				enqueuefront(d);
				break;
			case 3:
				item=dequeuerear();
				printf("\nitem deleted is:%d",item);
				break;
            case 4:
                item=dequeuefront();
				printf("\nitem deleted is:%d",item);
				break;
			case 5:
				displaydq();
				break;
			case 6:
				return;
		}
 	}
}
