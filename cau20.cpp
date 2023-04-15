#include<stdio.h>

int gcd(int a, int b)
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

int main()
{
	int a, b, m, n, d;
	printf("Nhap m: ");
	scanf("%d", &m);
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap d: ");
	scanf("%d", &d);
	for(int i = m; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(gcd(i, j) == d) printf("%d, %d\n", i, j);
		}
	}
	
}
