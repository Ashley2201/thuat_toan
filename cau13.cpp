#include<stdio.h>
#include<stdbool.h>

bool snt(int n){
	if(n < 2) return 0;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

void tim(int n){
	for(int i = 3; i <= n; i++){
		if(snt(i) == 1){
			if(snt(i + 2) == 1 && snt(i - 2) == 1){
				printf("%d\t2\n", i);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	tim(n);
}
