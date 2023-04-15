#include<stdio.h>
#include<math.h>

void tach(int a[], int b, int t, int w)
{
	for(int i = t - 1; i >= 0; i--)
	{
		a[i] = b / (int)pow(2, w * i);
		b = b % (int)pow(2, w * i);
	}
}


void cong(int a[], int b[], int w, int t)
{
	int c[t];
	int r = 0;
	int k;
	for(int i = 0; i < t; i++)
	{
		k = a[i] + b[i];
		if(r == 1)
		{
			c[i] = (a[i] + b[i] + 1) % (int)pow(2, w);
		}else
		{
			c[i] = (a[i] + b[i]) % (int)pow(2, w);
		}
		
		if(k < (int)pow(2, w) && k >= 0)
		{
			r = 0;
		}else
		{
			r = 1;
		}
	}
	for(int i = 0; i < t; i++)
	{
		printf("%d, ", c[i]);
	}
}
int main()
{
	int a, b, w, t, m, p;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	printf("Nhap w: ");
	scanf("%d", &w);
	printf("Nhap p: ");
	scanf("%d", &p);
	
	m = (int)log2(p);
	
	t = ceil((float)m/w);
	printf("%d \n", t);
	
	int c[t], d[t];
	
	tach(c, a, t, w);
	tach(d, b, t, w);
	
	cong(c, d, w, t);
	 
}
