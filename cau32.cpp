#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//=========================================================

int ucln(int a, int b)
{
	int A = a, B = b;
	while(B > 0)
	{
		int r = A % B;
		A = B;
		B = r;
	}
	return A;
}

int snt(int n)//kiem tra so nguyen to
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}

int nghichdao(int a, int n)//tim nghich dao cua a voi modulo n
{
	int y0 = 0, y1 = 1, y;
	while(a > 0)
	{
		int r = n % a;
		if(r == 0) break;
		int q = n / a;
		y = y0 - q*y1;
		y0 = y1;
		y1 = y;
		n = a;
		a = r;
	}
	if(a > 1) return -1;//a khong kha nghich theo modulo n
	while(y < 0)
	{
		y+=n;
	}
	return y;
}

int nhan(int a, int k, int n)
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
	while(b < 0)
	{
		b+=n;
	}
	return b;
}

//=========================================================

int main()
{
	int p, q, e, n, k, c, m, d, sbd, o;
	srand((int)time(0));
	do//chon ngau nhien p
	{
		p = 100 + rand() % (500 + 1 - 100);
	}while(snt(p) == 0);
	printf("Chon p = %d\n", p);
	do//chon ngau nhien q
	{
		q = 100 + rand() % (500 + 1 - 100);
	}while(snt(q) == 0);
	printf("Chon q = %d\n", q);
	n = p * q;
	printf("Ta co: n = %d\n", n);
	k = (p - 1) * (q - 1);
	printf("Va O(n) = %d\n", k);
	for(int i = 3; i < k; i++)
	{
		if(ucln(i, k) == 1)
		{
			e = i;
			break;
		}
	}
	printf("Tinh duoc e = %d\n", e);
	d = nghichdao(e, k);
	printf("Va d = %d\n", d);
	printf("Nhap sbd: ");
	scanf("%d", &sbd);
	m = sbd + 123;
	c = nhan(m, e, n);
	printf("Tinh duoc c = %d\n", c);
	o = nhan(c, d, n);
	printf("Thong diep m = %d", o);
}
