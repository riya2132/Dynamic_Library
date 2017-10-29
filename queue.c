#define MAX 20
int queue[MAX];
int front1=-1;
int rear1=-1;
int isfullq()
{
	if(rear1==MAX-1)
		return 1;
	else
		return 0;
}
int isemptyq()
{
	if(front1==-1||front1==rear1+1)
		return 1;
	else
		return 0;
}
void enqueue(int d)
{
	if(isfullq())
		{
		printf("\n overflow");
		}
	if(front1==-1)
		front1=0;
	rear1=rear1+1;
	queue[rear1]=d;
}
int dequeue()
{
	if(isemptyq())
		{
		printf("\nunderflow");
		}
	int a=queue[front1];
	front1=front1+1;
	return a;
}
int noelementsq()
{
	return rear1-front1+1;
}
void displayq()
{
	int i;
	printf("\nqueue elements are:");
	for(i=front1;i<=rear1;i++)
		printf("%d\n",queue[i]);
}
void queue1()
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
				enqueue(d);
				break;
			case 2:
				item=dequeue();
				printf("\nitem deleted is:%d",item);
				break;
			case 3:
				displayq();
				break;
			case 4:
				printf("\n%d",noelementsq());
				break;
			case 5:
				return;
		}
 	}
}
