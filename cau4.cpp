#include<stdio.h>

int snt(int n){
	if(n < 2){
		return 0;
	}else{
		for(int i = 2; i * i <= n; i++){
			if(n % i == 0){
				return 0;
			}
		}
		return 1;
	}
}

int main(){
	int min, max, s = 0;
	scanf("%d%d", &min, &max);
	for(int i = min;i <= max; i++){
		if(snt(i) == 1){
			s++;
		}
	}
	printf("%d", s);
}
