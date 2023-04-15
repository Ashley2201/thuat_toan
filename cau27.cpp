#include<stdio.h>

int ucln(int a, int b)
{
	int A = a, B = b, r;
	while(B > 0)
	{
		r = A % B;
		A = B;
		B = r;
	}
	return A;
}

int snt(int n)
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
	for(int i = 1; i < 1000; i++)
	{
		for(int j = i; j < 1000; j++)
		{
			if(snt(ucln(i , j)) == 1) printf("(%d, %d)\t", i, j);
		}
	}
}
