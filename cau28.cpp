#include<stdio.h>
#include<math.h>

int nhan(int n, int k, int a)//nhan binh phuong co lap tim so du
{
	int b = 1;
	if(k == 0) return b;
	
	int t = k % 2;
	k = k / 2;
	if(t == 1) b = a;
	int A = a;
	for(k; k > 0; k = k / 2)
	{	
		A = (A * A) % (n + 1);
		t = k % 2;
		if(t == 1)
		{
			b = (A * b) % (n + 1);
		}
	}
	return b;
}

void sangnt(int sang[], int n)//sang nguyen thuy tim hop so
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

int ucln(int a, int b)//tim uoc chung nho nhat
{
	int A = a, B = b, r;
	while(B > 0)
	{
		r = A % B;
		A = B;
		B = r;
	}
	return A;
}

void carmicheal(int n, int sang[])//tim so carmicheal
{
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 0)
		{
			for(int a = 1; a < i; a++)
			{
				if(ucln(i, a) == 1)
				{
					if(nhan(i - 1, i - 1, a) != 1) break;
				}
				if(a == i - 1)
				{
					printf("%d\t", i);
				}
			}		
		}	
	}
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
