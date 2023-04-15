#include<stdio.h>
#include<string.h>
//==============================================
void badCharacter(char p[], int m, int bc[])//ham tinh L(x)
{
	for(int i = 0; i < 256; i++)//khoi tao mang -1
	{
		bc[i] = -1;
	}
	for(int i = 0; i < m; i++)
	{
		bc[p[i]] = i;
	}//bay gio, chi co cac ky tu trong chuoi P moi co gia tri khac -1
}
//==============================================
int max(int a, int b)
{
	return a > b ? a : b;
}
//==============================================
void boyerMoore(char p[], char t[], int m, int n)
{
	int idx = 0, bc[256];
	badCharacter(p, m, bc);
	while(idx <= (n - m))
	{
		int j = m - 1;
		while(j >= 0 && p[j] == t[idx + j])
		{
			j--;
		}
		if(j < 0)
		{
			printf("Tim thay chuoi P trong chuoi T tai vi tri: %d\n", idx);
			idx += (idx + m < n) ? m - bc[t[idx + m]] : 1;//tinh buoc nhay de tiep tuc thuc hien doi sanh
		}
		else
		{
			idx += max(1, j - bc[t[idx + j]]);
		}
	}
}
//==============================================
int main()
{
	int m, n;
	printf("Nhap do dai chuoi P: ");
	scanf("%d", &m);
	
	printf("Nhap do dai chuoi T: ");
	scanf("%d", &n);
	
	char p[m + 1], t[n + 1];
	printf("Nhap chuoi T: ");
	fflush(stdin);
	gets(t);
	
	printf("Nhap chuoi P: ");
	fflush(stdin);
	gets(p);
	
	boyerMoore(p, t, m, n);
}
