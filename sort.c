void selection_sort(int a[],int n)
{
    int i,j,temp;
     for(i=0;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void bubble_sort(int a[],int n)
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
int part(int *a,int f,int e)
{int pivot,i,ipivot,temp;
    pivot=a[e];
    ipivot=f;
    for(i=f;i<=(e-1);i++)
    {

        if(a[i]<=pivot)
        {
            temp=a[i];
            a[i]=a[ipivot];
            a[ipivot]=temp;
            ipivot=ipivot+1;
        }
    }
    temp=a[e];
    a[e]=a[ipivot];
    a[ipivot]=temp;
    return ipivot;
}
void quick_sort(int *a,int f,int e)
{int ipivot;
    if(f>=e)
        return;
        ipivot=part(a,f,e);
        quick_sort(a,f,ipivot-1);
        quick_sort(a,ipivot+1,e);
}
void div_conq(int arr[],int low,int up)
{
    int temp[60];
    int mid;
    if(low<up)
    {
    mid=(low+up)/2;
    div_conq(arr,low,mid);
    div_conq(arr,mid+1,up);
    mergea(arr,temp,low,mid,mid+1,up);
    out_arr(arr,temp,low,up);
    }
}
void mergea(int arr[],int temp[],int low1,int up1, int low2,int up2)
{
    int i=low1,j=low2,k=low1;
    while(i<=up1 &&j<=up2)
    {
        if(arr[i]<=arr[j])
           {
            temp[k++]=arr[i++];

             }
        else
        {
            temp[k++]=arr[j++];


        }
    }
    while(i<=up1)
    {
        temp[k++]=arr[i++];


    }
    while(j<=up2)
    {
        temp[k++]=arr[j++];
     }
}
void out_arr(int arr[],int temp[],int low,int up)
{
  int i;
  for(i=low;i<=up;i++)
  {
      arr[i]=temp[i];
  }
}
void count_sort(int *a,int n,int k,int *b)
{
    int i ,j,l,m,c[k];
    for(i=0;i<k;i++)
    {
        c[i]=0;
    }
    for(j=0;j<n;j++)
        c[a[j]]=c[a[j]]+1;
    for(m=1;m<k;m++)
        c[m]=c[m]+c[m-1];
    for(l=n-1;l>=0;l--)
    {
        b[c[a[l]]-1]=a[l];
        c[a[l]]=c[a[l]]-1;
    }
     printf("\nsorted array elements are:");
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
}
void sorta()
{
    int *a,n,i,k,front,c;
    printf("enter size of array:");
    scanf("%d",&n);
    front=0;
    int end=n-1;
    int b[n];
    a=malloc(n*sizeof(int));
    printf("\nenter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
    {
        printf("\n1.selection\n2.bubble\n3.quick\n4.merge\n5.count\n6.quit\nenter ur choice:");
        scanf("%d",&c);
        system("cls");
        switch(c)
        {
        case 1:
            selection_sort(a,n);
            printf("sorted array elements are:");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            break;
        case 2:
            bubble_sort(a,n);
            printf("\narray after sorting:");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            break;
        case 3:
            quick_sort(a,front,end);
            printf("sorted array elements are:");
            for(i=0;i<n;i++)
            printf("%d ",a[i]);
            break;
        case 4:
            div_conq(a,0,n-1);
            printf("\n Sorted Array is :");
            for(i=0;i<n;i++)
            {
            printf("%d ",a[i]);
            }
            break;
        case 5:
             printf("\nenter count of range of values to be added:");
            scanf("%d",&k);
            count_sort(a,n,k,b);
            break;
        case 6:
            return;
        }
    }
}
