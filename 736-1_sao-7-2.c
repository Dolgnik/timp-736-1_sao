#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void Shell(int *a, int n)
{
	int i,j,k,a2;

	for(k=n/2; k>0; k/=2)
		for(i=k; i<n; i++)
		{
			a2 = a[i];
			for(j=i; j>=k; j-=k)
			{
				if(a2 < a[j-k])
					a[j] = a[j-k];
				else
					break;
			}
			a[j] = a2;
		}
}

int main()
{
	int *a;
	int n,i;
	
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for(i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	Shell(a,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	printf("\n");
}
