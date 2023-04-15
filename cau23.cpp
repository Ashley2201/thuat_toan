#include<stdio.h>
#include<stdbool.h>
//======================================================
bool snt(int n)
{
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}
//======================================================
void sangera(int sang[], int a, int b)
{
	int tong = 0;
	
	for(int i = 2; i <= b; i++)
	{
		sang[i] = 1;
	}
	
	for(int i = 2; i <= b; i++)
	{
		if(sang[i] == 1)
		{
			for(int j = i + i; j <= b; j+=i)
			{
				sang[j] = 0;
			}
		}
	}

	for(int i = a; i <= b; i++)
	{
		if(sang[i] == 1)
		{
			tong+=i;
		}
	}
	if(snt(tong) == 1)
	{
		printf("YES");
	}else
	{
		printf("NO");
	}
}
//===============================================
int main()
{
	int a, b;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	
	int sang[b];
	
	sangera(sang, a, b);
}
