#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void sorting(int *a, int l, int r)
{
	int max;
	int check = 0;

	while ((2 * l <= r) && (!check)) 
	{
		if (2 * l == r)
			max = 2 * l;
	else
		if (a[2 * l] > a[2 * l + 1])
			max = 2 * l;
		else
			max = 2 * l + 1;
	if (a[l] < a[max]) 
	{
		int q = a[l];
		a[l] = a[max];
		a[max] = q;
		l = max;
	}
	else
		check = 1;
	}
}

void Pyramid(int *a, int n) 
{
	int i;
	for (i = n/2 - 1; i >= 0; i--)
		sorting(a, i, n);
	for (i = n - 1; i >= 1; i--)
	{
		int q = a[0];
		a[0] = a[i];
		a[i] = q;
		sorting(a, 0, i - 1);
	}
}

int main()
{
	int *a;
	int n,i;
	
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for(i = 0; i<n; i++)
		scanf("%d", &a[i]);
	
	Pyramid(a, n);
	
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
	free(a);
	printf("\n");
}
