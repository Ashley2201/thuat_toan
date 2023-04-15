#include<stdio.h>

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
	int a, b, c, m, l;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	printf("Nhap c: ");
	scanf("%d", &c);
	printf("Nhap m: ");
	scanf("%d", &m);
	printf("Nhap l: ");
	scanf("%d", &l);
	int t;
	if(m > l)
	{
		t = m;
		m = l;
		l = t;
	}
	int d;
	for(int i = m + 1; i < l; i++)
	{	if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) break;
		d = a*i*i + b*i + c;
		if(snt(d) == 1)
		{
			printf("%d\t", i);
		}
	}
}
