#include<stdio.h>
int main()
{
	int num,proz=1,n,n0=0;
	scanf("%d",&n);
	if(n0==n)
	{
		proz=0;
	};
	while(n0!=n)
	{	
		scanf("%d",&num);
		n0++;
		proz=proz*(num-n0);
	};
	printf("%d\n",proz);
	return 0;
}
