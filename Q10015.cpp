#include <stdio.h>
#include <string.h>
#define MAX 32700

char notp[40010];
int next[3600],prime[3530],len,pre[3600],ans[3600];

int main() {
	
	int i,j,k,ptr,n;
	
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
		
	prime[0] = 2, prime[1] = 3;
	len = 2;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0) {
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
			prime[len++] = i;
		}
		
	while(scanf("%d",&n) && n) {
		
		if( ans[n] ) {
			printf("%d\n",ans[n]);
			continue;
		}
		
		for(i=1;i<n;i++)
			next[i] = i+1;
			
		for(i=2;i<=n;i++)
			pre[i] = i-1;
			
		pre[1] = n;
		next[n] = 1;
		ptr = 1, i = 0;
		
		while(next[ptr] != ptr) {
			
			for(j=1;j<prime[i];j++)
				ptr = next[ptr];
				
			next[pre[ptr]] = next[ptr];
			pre[next[ptr]] = pre[ptr];
			ptr = next[ptr];
			i++;
			
		}
		
		printf("%d\n",ans[n] = ptr);
		
	}
	
	return 0;
}
