#include<stdio.h>
#include<math.h>

void sangera(long long sang[],long long n){
	for(long long  i = 2; i <= n; i++){
		sang[i] = 1;
	}
	for(long long i = 2; i <= n; i++){
		if(sang[i] == 1){
			for(long long j = i + i; j <= n; j+=i){
				sang[j] = 0;
			}
		}
	}
}

void snt(long long min, long long max, long long sang[]){
	for(long long i = min; i < max; i++){
		if(sang[i] == 1){
			printf("%d\n", i);
		}
		
	}
}



int main(){
	int n;
	scanf("%d", &n);
	long long max = (int)pow(10, n);
	long long min = (int)pow(10, n-1);
	long long sang[max];
	sangera(sang, max);
	snt(min, max, sang);	
}
