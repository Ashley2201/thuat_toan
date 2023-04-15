#include<stdio.h>
#include<stdbool.h>

bool snt(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

void sangnt(int sang[], int n, int a[]){
	for(int i = 2; i <= n; i++){
		sang[i] = 1;
	}
	for(int i = 2; i <= n; i++){
		if(sang[i] == 1){
			for(int j = i + i; j <= n; j += i){
				sang[j] = 0;
			}
		}
	}
	int k = 0;
	for(int i = 2; i <= n; i++){
		if(sang[i] == 1){
			a[k] = i;
			k++;
		}
	}
	for(int i = 3; i <= k; i++){
		int tong = a[i] + a[i-1] + a[i-2] + a[i-3]; 
		if(tong < n){
			if(snt(tong) == 1){
				printf("%d\n%d\n%d\n%d\n", a[i-3], a[i-2], a[i-1], a[i]);
				break;
			}
		}
	}
}


int main(){
	int n;
	scanf("%d", &n);
	int sang[n+1];
	int a[n];
	sangnt(sang, n, a);
}
