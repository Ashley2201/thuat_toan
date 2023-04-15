#include<stdio.h>
//================================
int nhanBinhPhuongCoLap(int a, int k, int n)
{
	int b = 1;
	if(k == 0) return b;
	int t = k % 2;
	k = k / 2;
	if(t == 1) b = a;
	int A = a;
	for(k; k > 0; k = k / 2)
	{
		t = k % 2;
		A = (A * A) % n;
		if(t == 1) b = (A * b) % n;
	}
	return b;
}
//================================
int snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
//================================
int main()
{
	int a, k, n, check = 1;
	printf("Nhap a(a < 1000): ");
	scanf("%d", &a);
	printf("Nhap k(k < 1000): ");
	scanf("%d", &k);
	printf("Nhap n(n < 1000): ");
	scanf("%d", &n);
	if(a >= 1000)
	{
		check = 0;
		printf("a khong hop le\n");
	}
	if(k >= 1000)
	{
		check = 0;
		printf("k khong hop le\n");
	} 
	if(n >= 1000)
	{
		check = 0;
		printf("n khong hop le\n");
	} 
	if(check == 1){
		if(snt(nhanBinhPhuongCoLap(a, k, n)) == 1) printf("\nYES");
		else printf("NO");
	}
}

