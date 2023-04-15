#include<stdio.h>
//=======================================================
int nghichdao(int a, int p)
{
	int r, q, y1 = 1, y2 = 0, y, v = p;
	if(a == 0)
	{
		y = 0;
		return y;
	}
	while(a > 0)
	{
		q = v / a;
		r = v - q * a;
		y = y2 - q * y1;
		v = a;
		a = r;
		y2 = y1;
		y1 = y;	
	}
	while(y2 < 0)
	{
		y2 = y2 + p;
	}
	return y2;
}
//=======================================================
int main()
{
	int a, p;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap p: ");
	scanf("%d", &p);
	if(nghichdao(a, p) != 0)
	{
		printf("Nghich dao cua a trong truong p la: %d", nghichdao(a, p));
	}
	else printf("a khong co nghich dao trong truong p");
	
}
