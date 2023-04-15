#include<stdio.h>

int snt(int n){
	if(n<2){
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
	int n;
	scanf("%d", &n);
	int k = 0;
	int q = 0;
	int p = 0;
	int s = 0;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			p += i;
			s++;
			if(snt(i) == 1){
				k++;
				q +=i;
			}
		}
	}
	printf("%d ", n + p + s - q - k);
	
}
