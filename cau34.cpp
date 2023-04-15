#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//==========================================================================

int nhanbinhphuongcolap(int a, int n, int k)
{
	int b = 1;
	if(k == 0) return b;
	
	int t = k % 2;
	k = k / 2;
	int A = a;
	if(t == 1)
	{
		b = a;
	}
	for(k; k > 0; k = k / 2)
	{
		t = k % 2;
		A = (A * A) % n;
		if(t == 1)
		{
			b = (A * b) % n;
		}
	}
	return b;
}

//=========================================================================
int getrand(int min, int max)
{
	return min + (int)(rand() % (max - min + 1));
}
//=========================================================================
int fermat(int n, int t)
{
	int a[t];
	for(int i = 0; i < t; i++)
	{
		a[i] = getrand(2, n - 2);
	}
	for(int i = 0; i < t; i++)
	{
		if(nhanbinhphuongcolap(a[i], n, n - 1) != 1)
		{
			return 0;
		}
	}
	return 1;
}
//==========================================================================
int snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
//==========================================================================
void ktra(int n, int t)
{
	for(int i = 2; i <= n; i++)
	{
		if(fermat(i, t) == 1 && snt(i) == 0) printf("%d\t", i);
	}
}
//==========================================================================
int main()
{
	int n, t;
	printf("Nhap n(n la so le): ");
	scanf("%d", &n);
	printf("Nhap t: ");
	scanf("%d", &t);
	if(fermat(n, t) == 1)
	{
		printf("Nguyen to");
	}
	else
	{
		printf("Hop so");
	}
	ktra(1000, t);
}
