#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//===================================================
int nhanBinhphuongColap(int a, int r, int n)
{
	int b = 1;
	if(r == 0) return b;
	int t = r % 2;
	r = r / 2;
	if(t == 1) b = a;
	int A = a;
	for(r; r > 0; r = r / 2)
	{
		t = r % 2;
		A = (A * A) % n;
		if(t == 1) b = (A * b) % n;
	}
	return b;
}
//===================================================
int getrand(int min, int max)
{
	srand((int)time(0));
	return min + (int)(rand() % (max - min + 1));
}
//===================================================
int snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
//===================================================
/*int millerRabin(int n, int t)
{
	if(n < 2) return 0;
	int r, s;
	if((n - 1) % 2 == 1)
	{
		r = n - 1;
		s = 0;
	}
	else
	{
		r = (n - 1) / 2;
		s = 1;
		while(r % 2 == 0)
		{
			r = r / 2;
			s++;
		}
	}
	for(int i = 0; i < t; i++)
	{
		int c = getrand(2, n - 2);
		int y = nhanBinhphuongColap(c, r, n);
		if(y != 1 && y != n - 1)
		{
			int j = 1;
			while(j < s && y != n - 1)
			{
				y = (y * y) % n;
				if(y == 1) return 0;
				j++;
			}
			if(y != n - 1) return 0;
		}
	}
	return 1;
}*/
//===================================================
int main()
{
	int p, q, a, t, dem = 0;
	//printf("Nhap t: ");
	//scanf("%d", &t);
	do
	{
		p = getrand(1, 999);	
	}
	while(snt(p) == 0);
	printf("So p duoc chon la: %d\n", p);
	do
	{
		q = getrand(1, 999);
	}
	while(snt(q) == 0 || p == q);
	printf("So q duoc chon la: %d\n", q);
	for(a = 1; a < 100; a++)
	{
		int k = nhanBinhphuongColap(a, p, q);
		if(snt(k) == 1)
		{
			printf("%d\n", a);
			dem++;
		}
	}
	if(dem == 0) printf("Khong co so a thoa man");
}
