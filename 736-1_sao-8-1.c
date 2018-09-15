#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int part(int *a, int l, int r)
{
        int q = a[(l+r)/2];
        int i = l;
        int j = r;
        int w = 0;

        while(i <= j)
        {
                while(a[i] < q)
                        i++;
                while(a[j] > q)
                        j--;
                if(i >= j)
                        break;
                w = a[i];
                a[i] = a[j];
                a[j] = w;
        }
        return j;
}


void Hoar(int *a, int l, int r)
{
	if(l < r)
	{
		int h = part(a, l, r);
		Hoar(a, l, h);
		Hoar(a, h+1, r);
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

	Hoar(a,0,n-1);

	for(i=0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	printf("\n");
}
