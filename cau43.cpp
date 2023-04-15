#include<stdio.h>
//===========================================
int snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
//===========================================
int nhanBinhphuongColap(int a, int p, int n)
{
	int b = 1;
	if(p == 0) return b;
	int t = p % 2;
	p = p / 2;
	if(t == 1) b = a;
	int A = a;
	for(p; p > 0; p = p / 2)
	{
		t = p % 2;
		A = (A * A) % n;
		if(t == 1) b = (A * b) % n;
	}
	return b;
}
//===========================================
int main()
{
	int a, p, n;
	printf("Nhap n(0 < n < 1000): ");
	scanf("%d", &n);
	while(n > 1000 || n < 0)
	{
		printf("Nhap lai n: ");
		scanf("%d", &n);	
	}
	printf("Nhap p: ");
	scanf("%d", &p);
	for(a = 1; a < n; a++)
	{
		int k = nhanBinhphuongColap(a, p, n);
		if(snt(k) == 1) printf("%d\n", a);	
	}	
}
