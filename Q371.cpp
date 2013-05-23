#include <stdio.h>
#define MAX 10000000

long long s[MAX+1];

int main() {
	
	long long L,V,max,max_ptr;
	long long i,j,sum,tmp;
	s[1] = 3;
	
	while(scanf("%lld%lld",&L,&V) && L+V) {
		
		if(V < L) {
			tmp = L;
			L = V;
			V = tmp;
		}
		max = 0;
		for(i=L;i<=V;i++) {
			if(i <= MAX) {
				if(s[i]) {
					if(s[i] > max) {
						max = s[i];
						max_ptr = i;
					}
				} else {
					sum = 0, tmp = i;
					
					while(tmp > 1) {
						
						if(tmp & 1)
							tmp = tmp*3+1;
						else
							tmp /= 2;
							
						sum++;
							
					}
					
					s[i] = sum;
					if(s[i] > max) {
						max = s[i];
						max_ptr = i;
					}
				}
			} else {
				
				sum = 0, tmp = i;
				while(tmp > 1) {
					if(tmp & 1)
						tmp = tmp*3+1;
					else
						tmp /= 2;
					sum++;
				}		
				
				if(sum > max){
					max_ptr = i;
					max = sum;
				}
				
			}
			
		}
		
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",L,V,max_ptr,max);
		
	}
	
	return 0;
}
