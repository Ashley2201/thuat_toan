#include<stdio.h>
//========================================================================

void hienthi(int a[], int t){
    int check = 0;
    for(int i = t; i >= 0; i--){
        if(a[i] == 1 && i != 0 && check == 0){
            printf("x^%d  ", i);
            check = 1;
        } else if(a[i] == 1 && i != 0 && check == 1){
            printf("+  x^%d  ", i);
        } else if(a[i] == 1 && i == 0 && check == 0){
            printf("1", i);
        } else if(a[i] == 1 && i == 0 && check == 1){
            printf("+  1", i);
        }
    }
    printf("\n");
}

//------------------------------------------------------------------
void nhapdathuc(int a[], int k)
{
	for(int i = 0; i <= k; i++){
		int t;
		printf("Nhap he so cua x^%d: ", i);
		scanf("%d", &t);
		t = t % 2;
		a[i] = t;
	}
	printf("Da thuc vua nhap la: ");
	hienthi(a, k);
}

//------------------------------------------------------------------

void gandathucbang1(int a[], int k)
{
	for(int i = k; i > 0; i--)
	{
		a[i] = 0;
	}
	a[0] = 1;
}

//------------------------------------------------------------------

void gandathucbang0(int a[], int k)
{
	for(int i = 0; i <= k; i++)
	{
		a[i] = 0;
	}
}

//------------------------------------------------------------------

void dathucbang(int a[], int b[], int k)
{
	for(int i = 0; i <= k; i++)
	{
		a[i] = b[i];
	}
}

//------------------------------------------------------------------

int sosanh0(int a[], int k)
{
	for(int i = k; i >= 0; i--)
	{
		if(a[i] != 0) return 0;
	}
	
}

//------------------------------------------------------------------

int sosanh1(int a[], int k)
{
	for(int i = 1; i <= k; i++)
	{
		if(a[i] == 1) return 0;
	}
	if(a[0] == 1) return 1;
	else return 0;
}

//------------------------------------------------------------------

int cong(int a, int b)
{
    return a + b == 2 ? 0 : a + b;
}

//------------------------------------------------------------------

void congdathuc(int a[], int b[], int c[], int k)
{
	for(int i = 0; i <= k; i++)
	{
		c[i] = cong(a[i], b[i]);
	}
}

//----------------------------------------------------------------------------

void chiadathuc(int a[], int b[], int c[], int t){
    int tmp2[t + 1];
    dathucbang(tmp2, a, t);
    int lengb;
    for(int i = t; i >= 0; i--){
        if(b[i] == 1){
            lengb = i;
            break;
        }
    }
    while(1){
        int lengtmp2 = -1;
        for(int j = t; j >= 0; j--){
            if(tmp2[j] == 1){
                lengtmp2 = j;
                break;
            }
        }
        if(lengtmp2 - lengb < 0){
            break;
        }
        if(tmp2[lengtmp2] == 1 && lengtmp2 - lengb >= 0){
            c[lengtmp2 - lengb] = 1;
            int tmp3[t + 1];
            gandathucbang0(tmp3, t);
            for(int j = 0; j <= t; j++){
                if(b[j] == 1) tmp3[j + (lengtmp2 - lengb)] = 1;
            }
            congdathuc(tmp2, tmp3, tmp2, t);
        }
    }
}

//----------------------------------------------------------------------------

void nhandathuc(int a[], int b[], int c[], int g[], int t){
    int tmp[t * t + 1];
    gandathucbang0(tmp, t * t);
    for(int i = 0; i <= t; i++){
        if(a[i] == 1){
            int tmp1[t * t + 1];
            gandathucbang0(tmp1, t * t);
            for(int j = 0; j <= t; j++){
                if(b[j] == 1){
                    tmp1[i + j] = 1;
                }
            }
            congdathuc(tmp, tmp1, tmp, t * t);
        }
    }
    int tmp2[t * t + 1];
    dathucbang(tmp2, tmp, t * t);
    while(1){
        int lengtmp2 = -1;
        for(int j = t * t; j >= 0; j--){
            if(tmp2[j] == 1){
                lengtmp2 = j;
                break;
            }
        }
        if(lengtmp2 - t < 0){
            break;
        }
        if(tmp2[lengtmp2] == 1 && lengtmp2 - t >= 0){
            int tmp3[t * t + 1];
            gandathucbang0(tmp3, t * t);
            for(int j = 0; j <= t; j++){
                if(g[j] == 1) tmp3[j + (lengtmp2 - t)] = 1;
            }
            congdathuc(tmp2, tmp3, tmp2, t * t);
        }
    }

    for(int i = 0; i <= t; i++){
        c[i] = tmp2[i];
    }
}

//------------------------------------------------------------------------

void nghichdao(int a[], int p[], int t)
{
	int u[t + 1], v[t + 1], x1[t + 1], x2[t + 1], q[t + 1], r[t + 1], x[t + 1], tmp1[t + 1], tmp2[t + 1];
    for(int i = 0; i <= t; i++){
        u[i] = v[i] = x1[i] = x2[i] = q[i] = r[i] = x[i] = tmp1[i] = tmp2[i] = 0;
    }
    dathucbang(u, a, t);
    dathucbang(v, p, t);
    gandathucbang1(x1, t);
    gandathucbang0(x2, t);
    while(sosanh1(u, t) != 1){
        chiadathuc(v, u, q, t);
        gandathucbang0(tmp1, t);
        nhandathuc(q, u, tmp1, p, t);
        congdathuc(v, tmp1, r, t);
        gandathucbang0(tmp2, t);
        nhandathuc(q, x1, tmp2, p, t);
        congdathuc(x2, tmp2, x, t);
        dathucbang(v, u, t);
    	dathucbang(u, r, t);
        dathucbang(x2, x1, t);
        dathucbang(x1, x, t);
    }
    printf("\n\na(x) ^ -1 mod g(x) = ");
    hienthi(x1, t);
}

//========================================================================


int main()
{
	int a[4];
	printf("Nhap da thuc a(x): \n");
	nhapdathuc(a, 3);
	int b[4];
	printf("Nhap da thuc g(x): \n");
	nhapdathuc(b, 3);
	nghichdao(a, b, 3);
}
