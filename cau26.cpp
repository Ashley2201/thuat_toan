#include<stdio.h>
//=========================================================
void sapxep(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
//=========================================================
void sangnt(int sang[], int n)
{
	int a[n], k = 0;
	for(int i = 2; i < n; i++)
	{
		sang[i] = 1;
	}
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 1)
		{
			for(int j = i + i; j < n; j+=i)
			{
				sang[j] = 0;
				if(j % (i * i) == 0)
				{
					a[k] = j;
					k++;
				}
			}
		}
	}
	sapxep(a, k);
	for(int i = 0; i < k; i++)
	{
		printf("%d\n", a[i]);
	}
}
//=================================================================
int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int sang[n+1];
	sangnt(sang, n);
}
