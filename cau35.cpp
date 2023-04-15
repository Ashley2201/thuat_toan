#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//=======================================================
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
//=======================================================
int getrand(int min, int max)
{
	srand((int)time(0));
	return min + (int)(rand() % (max - min + 1));
}
//=======================================================
int millerRabin(int a, int n, int t)
{
	int s, r;
	if((n - 1) % 2 == 1)
	{
		s = 0;
		r = n - 1;
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
		a = getrand(2, n - 2);
		int y = nhanBinhphuongColap(a, r, n);
		if(y != 1 && y != n - 1)
		{
			int j = 1;
			while(j < s && y != n - 1)
			{
				y = (y * y) % n;
				if(y == 1)
				{
					return 0;
				}
				j = j + 1;
			}
			if(y != n - 1) return 0;
		}
	}
	return 1;
}
//=======================================================
int main()
{
	int a, n, t;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap t: ");
	scanf("%d", &t);
	if(millerRabin(a, n, t) == 1)
	{
		printf("Nguyen to");
	}
	else printf("Hop so");
	printf("\nXac suat dung cua thuat toan: %f", pow(0.25, t));
}
