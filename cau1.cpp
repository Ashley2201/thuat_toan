#include<stdio.h>
//==========================================
int qp(int n)
{
	if(n < 6) return 0;
	int dem = 2;
	for(int i = 2; i <= (n / 2) + 1; i++)
	{
		if(n % i == 0) dem++;
		if(dem > 4) return 0;
	}
	if(dem == 4) return 1;
	return 0;
}
//==========================================
int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i = 0; i <= n; i++)
	{
		if(qp(i) == 1) printf("%d\n", i);
	}	
}
