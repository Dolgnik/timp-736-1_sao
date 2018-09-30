#include<stdio.h>
int main()
{
	int num;
	int count = 0;
	int n;
	scanf("%d",&n);
	while(n !=0)
	{
		n--;
		scanf("%d",&num);
		if(num > 0)
		{
			count +=1;
		}
	}
	printf("%d\n",count);
	return 0;
}
