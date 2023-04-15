#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool snt(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}

int dao(int n){
	int r;
	int s = 0;
	int k = 2;
	while(n > 0){
		r = n % 10;
		n = n / 10;
		s = s + r * (int)pow(10, k);
		k--;
	}
	return s;
}

void tim(){
	for(int i = 5; i < 10; i++){
			if(snt(dao(i*i*i)) == 1){
				printf("%d\t", dao(i*i*i));
			}
	}
}

int main(){
	tim();
}
