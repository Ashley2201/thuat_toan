#include<stdio.h>
//======================================
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
//======================================
int snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
//======================================
int main()
{
	int n, dem = 0;
	printf("Nhap kich thuoc mang A: ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
	{
		printf("Nhap A[%d]: ", i);
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(snt(ucln(a[i], a[j])) == 1) dem++;
		}
	}
	printf("\n%d", dem);
}
