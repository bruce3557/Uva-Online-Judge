#include <stdio.h>
#include <string.h>

bool notp[40000];
int n,m,len,prime[10010];
const int MAX = 32768;

int main() {
	int i,j,k,count;
	
	for(i=4;i<=MAX;i+=2)
		notp[i] = true;
	for(i=9;i<=MAX;i+=3)
		notp[i] = true;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == false)
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	len = 2;
	prime[0] = 2, prime[1] = 3;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == false)
			prime[len++] = i;
	
	while(scanf("%d",&n) && n) {
		count = 0;
		for(i=0;i<len && prime[i]*2 <= n;i++)
			if(notp[n-prime[i]] == false)
				count++;
		printf("%d\n",count);
	}
	
	return 0;
}
