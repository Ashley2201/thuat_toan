#include<stdio.h>

bool snt(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int  i = 2; i <= n; i++){
		if(i + 2 <= n){
			if(snt(i) == 1 && snt(i + 2) == 1){
				printf("%d\t%d\n", i, i + 2);
			}
		}	
	}
}
