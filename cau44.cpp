#include<stdio.h>
//==============================================================
int nghichdao(int a, int p)
{
	int r, q, y1 = 1, y2 = 0, y, v = p;
	if(a == 0) return 0;
	while(a > 0)
	{
		q = v / a;
		r = v - q * a;
		v = a;
		a = r;
		y = y2 - q * y1;
		y2 = y1;
		y1 = y;
	}
	while(y2 < 0)
	{
		y2 = y2 + p;
	}
	return y2;
}
//==============================================================
void nhap(int a[], int n, int p)
{
	for(int i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d cua mang: ", i + 1);
		scanf("%d", &a[i]);
		if(a[i] >= p) a[i] = a[i] % p;
	}
}
//==============================================================
int main()
{
	int p, n;
	printf("Nhap p: ");
	scanf("%d", &p);
	printf("Nhap so phan tu mang A: ");
	scanf("%d", &n);
	int a[n], b[n];
	nhap(a, n, p);
	for(int i = 0; i < n; i++)
	{
		b[i] = nghichdao(a[i], p);
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ^ -1 = %d\n", a[i], b[i]);
	}
}
