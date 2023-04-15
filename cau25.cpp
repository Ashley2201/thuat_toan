#include<stdio.h>
#include<string.h>
//=========================================================
void sangnt(int sang[], int n)
{
	sang[0] = 0;
	sang[1] = 0;
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
//=========================================================
void exec(int *mang, int vitri, int tong, char kq[], int m)
{
	if(vitri < -1) return;  
	if(tong == 0 && m == 0)
	{
		printf("%s\n", kq);
		return;
	}
	for(int i = vitri; i >= 0; i--)
    {
		if (tong >= mang[i])
        {
			char so[1000];
			char tem[1000];
			sprintf(so, "%d", mang[i]);
			strcpy(tem, kq);
			strcat(tem, so);
			strcat(tem, " ");
			exec(mang, i - 1, tong - mang[i], tem, m - 1);
		}
	}
}
//=========================================================
int main()
{
	int m, n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap m: ");
	scanf("%d", &m);
	while(n < 1 || n > 10000)
	{
		printf("Nhap lai n: ");
		scanf("%d", &n);
	}
	while(m < 3 || m > 100)
	{
		printf("Nhap lai m: ");
		scanf("%d", &m);
	}
	int sang[n], dem = 0;
	sangnt(sang, n);
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 1)
		{
			dem++;
		}
	}
	int a[dem], j = 0;
	for(int i = 2; i < n; i++)
	{
		if(sang[i] == 1)
		{
			a[j] = i;
			j++;
		}
	}
	char kq[] = " ";
	exec(a, dem - 1, n, kq, m);
}
