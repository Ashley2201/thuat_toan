#include<stdio.h>

void sangnt(int sang[], int l, int r)
{
	for(int i = 2; i <= r; i++)
	{
		sang[i] = i;
	}
	for(int i = 2; i <= r; i++)
	{
		if(sang[i] == i)
		{
			for(int j = i + i; j <= r; j+=i)
			{
				sang[j] = 0;
			}
		}
	}
	for(int i = l; i <= r; i++)
	{
		for(int j = i + 1; j <= r; j++)
		{
			printf("%d\t", sang[i] * sang[j]);
		}
	}
}


int main()
{
	int l, r;
	printf("Nhap l: ");
	scanf("%d", &l);
	printf("Nhap r: ");
	scanf("%d", &r);
	
	int sang[r];
	sangnt(sang, l, r);
}
