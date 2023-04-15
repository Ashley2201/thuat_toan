#include<stdio.h>
#include<math.h>
#include<stdbool.h>


bool snt(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int daonguoc(int n){
	
	int r;
	int s = 0;
	int j = 0;
	
	if(n < 10) return n;
	
	while(n > (int)pow(10, j)){
		j++;
	}
	
	while(n > 0){
		r = n % 10;
		n = n/10;
		s = s + r * (int)pow(10, j - 1);
		j--;
	}
	
	return s;
	
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 2; i < n; i++){
		if(snt(i) == 1){
			if(snt(daonguoc(i)) == 1){
				printf("%d\n", i);
			}
		}
	}
}
