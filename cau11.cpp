#include<stdio.h>

int sangnt(int sang[], int n){
	int tong = 0;
	for(int i = 2; i <= n; i++){
		sang[i] = 1;
	}
	for(int i = 2; i <= n; i++){
		if(sang[i] == 1){
			for(int j = i + i; j <= n; j+=i){
				sang[j] = 0;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(sang[i] == 1){
			tong+=i;
		}
	}
	return tong;	
}

int main(){
	int n;
	scanf("%d", &n);
	int sang[n+1];
	printf("%d", sangnt(sang, n));
}
