#include<stdio.h>
#include<math.h>

void sangnt(int sang[], int n)
{
	for(int i = 2; i < n; i++)
	{
		sang[i] = 1;
	}
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 1)
		{
			for(int j = i + i; j < n; j+=i)
			{
				sang[j] = 0;
			}
		}
	}
}

int nhan(int n, int a)
{
	int x = 0, N = n - 1;
	while(n - 1 > (int)pow(2, x))
	{
		x++;
	}
	int X = x - 1, p[x];
	while(X >= 0)
	{
		if(N >= (int)pow(2, X))
		{
			N = N - (int)pow(2, X);
			p[X] = 1;
		}else
		{
			p[X] = 0;
		}
		X--;
	}
	int b, A = a;
	if(p[0] == 1)
	{
		b = a;
	}else
	{
		b = 1;
	}
	for(int i = 1; i < x; i++)
	{
		A = (A * A) % n;
		if(p[i] == 1)
		{
			b = (A * b) % n;
		}
	}
	return b;
}

int ucln(int a, int b)
{
	int r, A = a, B = b;
	while(B > 0)
	{
		r = A % B;
		A = B;
		B = r;
	}
	return A;
}

void carmicheal(int n, int sang[])
{
	int dem = 0;
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 0)
		{
			for(int a = 2; a < i; a++)
			{
				if(ucln(a, i) == 1)
				{
					if(nhan(i, a) != 1) break;
				}
				if(a == i - 1)
				{
					dem++;
				}
			} 
		}
	}
	printf("%d", dem);
}

int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int sang[n];
	
	sangnt(sang, n);
	carmicheal(n, sang);
}
