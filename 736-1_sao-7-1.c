#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void Rascheska(int *a, int n)
{
	const float fac = 1.247;
	int len = n/fac;
	int i=0;
	int buf;

	while(i < i+len)
	{
		i=0;
		while(i+len < n)
		{
			if(a[i] > a[i+len])
			{
				buf = a[i];
				a[i] = a[i+len];
				a[i+len] = buf;
				
				
			}
			i++;
		}
		len /= fac;
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
	Rascheska(a,n);
	for(i=0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	printf("\n");
}
