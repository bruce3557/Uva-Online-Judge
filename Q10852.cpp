#include <stdio.h>
#include <string.h>
#define MAX (10000)

int ans[MAX+10];
int len,prime[2000];
bool notp[MAX+10];

void Build_Prime() {
	notp[0] = notp[1] = 1;
	for(int i=4;i<=MAX;i+=2)	notp[i] = 1;
	for(int i=9;i<=MAX;i+=3)	notp[i] = 1;
	for(int i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	prime[0] = 2, prime[1] = 3;
	len = 2;
	for(int i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
}

void Process() {
	Build_Prime();
	
	for(int i=1;i<=10000;i++) {
		int max = -1,ptr;
		for(int j=0;j<len && prime[j] <= i;j++) {
			int p = (int)(i/prime[j]);
			int temp = i-(p*prime[j]);
			if( temp > max ) {
				max = temp;
				ptr = prime[j];
			}
		}
		ans[i] = ptr;
	}
	
}

int main() {
	int t,n;
	Process();
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	
	return 0;
}
