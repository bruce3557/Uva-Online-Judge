#include <stdio.h>
#define MAX 100000000

bool notp[MAX+5];

int main() {
	int n,a,b,tmp,i,j,k;
	bool flag;
	
	notp[0] = notp[1] = 1;
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	
	for(i=5,k=2;i<=10000;i+=k,k=6-k)
		if(notp[i] == 0) {
			for(j=i*i;j<=MAX;j+=2*i)
				notp[j] = 1;
		}

	while(scanf("%d",&n) != EOF) {
		flag = 0;
		if((n & 1) == 0) {
			i = n/2;
			if((i & 1) == 0)	i--;
			if(2*i == n)	i -= 2;
			while(i > 1) {
				if(notp[i] == 0 && notp[n-i] == 0) {
					flag = 1;
					a = i, b = n-i;
					break;
				}
				i -= 2;
			}
		} else if(n-2 > 0 && notp[n-2] == 0) {
				a = 2, b = n-2;
				flag = 1;
		}
		
		if(flag)
			printf("%d is the sum of %d and %d.\n",n,a,b);
		else
			printf("%d is not the sum of two primes!\n",n);
		
	}
	
	return 0;
}
