#include<stdio.h>

int tonguoc(int n){
	int s = 0;
	for(int i = 1; i <= n/2; i++){
		if(n % i == 0){
			s+=i;
		}
	}
	return s;
}

int main(){
	int n;
	scanf("%d", &n);
	int k[n];
	for(int i = 1; i < n; i++){
		int j = 1;
		while(j < n){
			if(i == k[j]){
				i++;
				break;
			}
			j++;
		}
		if(i == tonguoc(tonguoc(i))){
			
			if(i != tonguoc(i)){
				printf("%d %d\n", i, tonguoc(i));
				k[i] = tonguoc(i);
			}		
		}
	}
}
