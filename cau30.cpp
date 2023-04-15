#include<stdio.h>
//===============================================================

int nhan(int a, int k, int n)
{
	int b = 1;

	if(k == 0) return b;
	int t = k % 2;
	k = k / 2;
	
	int A = a;
	if(t == 1) b = a;
	
	for(k; k > 0; k = k / 2)
	{
		t = k % 2;
		A = (A * A) % n;
		if(t == 1)
		{
			b = (A * b) % n;
		}
	}
	return b;
}

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

void sangnt(int sang[], int n)
{
	sang[0] = 0;
	sang[1] = 0;
	for(int i = 2;i < n; i++)
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

void tongCarmicheal(int n, int sang[])
{
	int tong = 0;
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 0)
		{
			for(int a = 1; a < i; a++)
			{
				if(ucln(a, i) == 1)
				{
					if(nhan(a, i - 1, i) != 1) break;	
				}
				if(a == i - 1) tong = tong + i;
			}
		}
	}
	printf("%d", tong);
}

//===============================================================
int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int sang[n];
	sangnt(sang, n);
	tongCarmicheal(n, sang);
}
