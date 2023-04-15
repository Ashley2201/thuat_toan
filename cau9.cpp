#include<stdio.h>

int sangnt(int sang[], int n){
	int k = 0;
	for(int i = 2; i <= n; i++){
		sang[i] = 1;
	}
	for(int i = 2; i <= n; i++){
		if(sang[i] == 1){
			for(int j = i + i; j < n; j+=i){
				sang[j] = 0;
			}
		}	
	}
	for(int i = 2; i < n; i++){
		if(sang[i] == 1){
			k++;
		}
	}
	return k;
}

int main(){
	int n;
	scanf("%d", &n);
	int sang[n];
	printf("%d", sangnt(sang, n));
}
