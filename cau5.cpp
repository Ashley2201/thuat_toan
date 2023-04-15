#include<stdio.h>
//=========================================================
void sangnt(int sang[], int n)
{
	for(int i = 2; i <= n; i++)
	{
		sang[i] = 1;
	}
	for(int i = 2; i <= n; i++)
	{
		if(sang[i] == 1)
		{
			for(int j = i + i; j <= n; j+=i)
			{
				sang[j] = 0;
			}	
		}
	}
}
//=========================================================
int main()
{
	int a, b, tong = 0;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	int sang[b + 1];
	sangnt(sang, b);
	for(int i = a; i <= b; i++)
	{
		if(sang[i] == 1) tong+=i;
	}
	printf("%d", tong);
}
