void linearsearch(int a[],int n,int d)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==d)
		{
		flag=1;
		break;
		}
	}
	if(flag==1)
		printf("data %d found at index %d\n",a[i],i);
	else
		printf("not found");
}
void bubblesort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{	int flag=0;
		for(j=0;j<=(n-i-1);j++)
		if(a[j]>=a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			flag=1;
		}
	if(flag==0)
	break;
	}
}
void binarysearch(int a[],int l,int r,int d)
{
	int mid;
	mid=l+(r-l)/2;
	if(a[mid]==d)
		{
		printf("data %d found at %d",a[mid],mid);
		return;
		}
	if(a[mid]>d)
		binarysearch(a,l,mid-1,d);
	else
		binarysearch(a,mid+1,r,d);
}
int minimum(int x,int y)
{
	return (x<y?x:y);
}
int fibonaccisearch(int *a,int n,int x)
{
	int f2=0;
	int f1=1;
	int f=f1+f2;
	while(f<n)
	{
		f2=f1;
		f1=f;
		f=f1+f2;
	}
	int offset=0;
	while(f>1)
	{
		int i=minimum(offset+f2,n-1);
		if(a[i]<x)
		{
			f=f1;
			f1=f2;
			f2=f-f1;
			offset=i;
		}
		else if(a[i]>x)
		{
			f=f2;
			f1=f1-f2;
			f2=f2-f1;
		}
		else
			return i;
	}
	return -1;
}
void searcha()
{
    int n,i,d,c,l=0,r,index;
	printf("\nenter size of array:");
	scanf("%d",&n);
	r=n-1;
	int a[n];
	printf("\nenter elements of array:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nenter data to be searched:");
	scanf("%d",&d);
    while(1)
    {
        printf("\n1.linear\n2.binary\n3.fibonacci\n4.quit\nenter ur choice:");
        scanf("%d",&c);
        system("cls");
        switch(c)
        {
        case 1:
            linearsearch(a,n,d);
            break;
        case 2:
            bubblesort(a,r+1);
            binarysearch(a,l,r,d);
            break;
        case 3:
             bubblesort(a,n);
             index=fibonaccisearch(a,n,d);
              printf("\nelement found at index:%d",index);
                break;
        case 4:
            return;
        }
    }
}
