#include <stdio.h>
#include <string.h>

int n;
char car[65010];
bool notp[65010];

unsigned int bm(unsigned int a,unsigned int b) {
	if(b == 0)	return 1;
	unsigned int k = bm(a,b/2)%n;
	k = (k*k)%n;
	if(b % 2) {
		return (k*a)%n;
	} else {
		return k;
	}
}

int main() {
	int i,j,k;
	
	for(i=4;i<65000;i+=2)
		notp[i] = 1;
	for(i=9;i<65000;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i*i<65000;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<65000;j+=i)
				notp[j] = 1;
	
	while(scanf("%d",&n) && n) {
		if(car[n] == 1) {
			printf("The number %d is a Carmichael number.\n",n);
		} else if(car[n] == 2) {
			printf("%d is normal.\n",n);
		} else {
			if(n % 2 == 0 || notp[n] == 0) {
				car[n] = 2;
				printf("%d is normal.\n",n);
				continue;
			}
			for(i=2;i<n;i++)
				if(bm(i,n) != i)
					break;
			if(i >= n && notp[n] == 1) {
				car[n] = 1;
				printf("The number %d is a Carmichael number.\n",n);
			} else {
				car[n] = 2;
				printf("%d is normal.\n",n);
			}
		}
	}
	
	return 0;
}
