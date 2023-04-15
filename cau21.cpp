#include<stdio.h>
#include<stdbool.h>

int sangnt(int sang[], int n)
{
	int dem = 0;
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
			}
		}
	}
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 1)
		{
			dem++;
		}
	}
	return dem;
}

bool snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int a, b, t = 0, k;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	
	if(a > b)
	{
		k = a;
		a = b;
		b = k;
	}
	
	for(int i = a; i <= b; i++)
	{
		int sang[i+1];
		if(snt(sangnt(sang, i)) == 1) t++;
	}
	printf("%d", t);
}
