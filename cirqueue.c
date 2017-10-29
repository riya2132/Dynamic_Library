#define MAX 10
int queue[MAX];
int front2=-1;
int rear2=-1;
int isfullcq()
{
	if(front2==0&&rear2==MAX-1||(front2==rear2+1))
		return 1;
	else
		return 0;
}
int isemptycq()
{
	if(front2==-1)
		return 1;
	else
		return 0;
}
void enqueuecq(int d)
{
	if(isfullcq())
		{
		printf("\n overflow");
		exit(1);
		}
	if(front2==-1)
		front2=0;
	if(rear2==MAX-1)
		rear2=0;
	else
		rear2=rear2+1;
	queue[rear2]=d;
}
int dequeuecq()
{
	if(isemptycq())
		{
		printf("\nunderflow");
		exit(1);
		}
	int a=queue[front2];
	if(front2==rear2)
		{
			front2=-1;
			rear2=-1;
		}
	 if(front2==MAX-1)
		front2=0;
	else
	front2=front2+1;
	return a;
}
void displaycq()
{
	int i;
	printf("\nqueue elements are:");
	i=front2;
	if(front2<=rear2)
	{
		while(i<=rear2)
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
	while(i<=rear2)
		{
		printf("%d ",queue[i]);
		i++;
		}
	}
}
int nofelecq()
{
	if(front2<=rear2)
		return(rear2-front2+1);
	else
		return(MAX-front2+rear2+1);

}
void cirqueue()
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
				printf("\nenter element to be enqueued:");
				scanf("%d",&d);
				enqueuecq(d);
				break;
			case 2:
				item=dequeuecq();
				printf("\nitem deleted is:%d",item);
				break;
			case 3:
				displaycq();
				break;
			case 4:
				printf("\nno of elements:%d",nofelecq());
				break;
			case 5:
				return;
		}
 	}
}
