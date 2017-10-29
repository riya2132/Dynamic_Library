void inordert(char *a,int m,int k)
{
	if(k>m)
	return;
	inorder(a,m,2*k);
	printf("%c ",a[k]);
	inorder(a,m,2*k+1);
}
void preordert(char *a,int m,int k)
{
	if(k>m)
	return;
	printf("%c ",a[k]);
	preorder(a,m,2*k);
	preorder(a,m,2*k+1);
}
void postordert(char *a,int m,int k)
{
	if(k>m)
	return;
	postorder(a,m,2*k);
	postorder(a,m,2*k+1);
	printf("%c ",a[k]);
}
void tree()
{
	int c;
	int h,n;
	char t[11]={'\0','a','b','c','d','e','f','g','h','i','j'};
	while(1)
	{
		printf("\n1.inorder\n2.preorder\n3.postorder\n4.quit\nenter ur choice:\n");
		scanf("%d",&c);
		system("cls");
		switch(c)
		{
		case 1:
			inordert(t,10,1);
			break;
		case 2:
			preordert(t,10,1);
			break;
		case 3:
			postordert(t,10,1);
			break;
		case 4:
			return;
		}


	}
}


