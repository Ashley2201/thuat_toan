#include<stdio.h>
//================================================================
void sangnt(int sang[], int b)
{
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
}
//================================================================
void kiemtra(int sang[], int a, int b)
{
	int dem = 0;
	for(int i = a; i <= b; i++)
	{
		if(sang[i] == 1)
		{
			for(int j = 1; j * j <= b; j++)
			{
				for(int k = j + 1; k * k <= b; k++)
				{
					if((k * k) + (j * j) == i) dem++;
				}
			}
		}
	}
	printf("%d", dem);
}
//============================================================
int main()
{
	int a, b;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	int sang[b+1];
	sangnt(sang, b);
	kiemtra(sang, a, b);
}
