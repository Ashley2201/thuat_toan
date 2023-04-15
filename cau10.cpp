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

void dem(int n){
	int k = 0, t = 0;
	if(snt(n) == 1) t++;
	for(int i = 2; i <= n/2; i++){
		if(n % i == 0){
			k++;
			if(snt(i) == 1){
				t++;
			}
		}
	}
	printf("%d, %d", k + 2, t);
}

int main(){
	int n;
	scanf("%d", &n);
	dem(n);
}
