#include<stdio.h>
//============================================

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
		if(t == 1) b = A * b % n;
	}
	return b;
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

int ganNhat(int n)
{
	int smallerk, biggerk;
	if(n % 2 == 0)
	{
		smallerk = n - 1;
		biggerk = n - 1;
	}else
	{
		smallerk = n - 2;
		biggerk = n + 2;
	}
	while(snt(smallerk) == 0)
	{
		smallerk-=2;
	}
	while(snt(biggerk) == 0)
	{
		biggerk+=2;
	}
	if(n - smallerk > biggerk - n)
	{
		return biggerk;
	}
	return smallerk;
}

void ketqua(int a, int n)
{
	printf("k: %d, a^k mod n: %d", ganNhat(n), nhan(a, ganNhat(n), n));
}

//============================================
int main()
{
	int n, a;
	printf("Nhap ma sinh vien(n): ");
	scanf("%d", &n);
	printf("Nhap SBD(a): ");
	scanf("%d", &a);
	ketqua(a, n);
}
