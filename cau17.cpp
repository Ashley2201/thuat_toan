#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool snt(int n)
{
	if(n < 2) return 0;
	for(int  i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int x = 1;
	int d = 1;
	if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0)
	{
		while(snt(d) == 0)
		{
			d = a*x*x +b*x + c;
			x++;
		}
		printf("%d", x);
	}
}
