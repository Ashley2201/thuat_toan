#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//=============================================
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
//=============================================
int getrand(int min, int max)
{
	srand((int)time(0));
	return min + (int)(rand() % (max - min + 1));
}
//=============================================
int millerRabin(int n, int t)
{
	if(n < 2) return 0;
	int s, r;
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
		int d = getrand(2, n - 2);
		int y = nhanBinhphuongColap(d, r, n);
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
}
//=============================================
int main()
{
	int n, t, min;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	printf("Nhap tham so an toan: ");
	scanf("%d", &t);
	int a[n];
	srand((int)time(0));
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			do
			{
				a[i] = getrand(2, 100);//neu max > 100 thi van chay duoc nhung se mat thoi gian
			}
			while(millerRabin(a[i], t) == 0 || a[i] <= 0);
		}
		else
		{
			do
			{
				a[i] = getrand(2, 100);
			}
			while(millerRabin(a[i], t) == 0 || a[i] <= 0|| a[i] == a[i - 1]);
		}
		printf("a[%d] = %d\n", i, a[i]);
	}
	min = (a[1] - a[0]) >= 0 ? (a[1] - a[0]) : (a[0] - a[1]);
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int tmp = (a[j] - a[i]) >= 0 ? (a[j] - a[i]) : (a[i] - a[j]);
			if(tmp < min) min = tmp;	
		}
	}
	printf("Khoang cach nho nhat giua 2 phan tu = %d", min);
}
