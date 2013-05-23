#include <stdio.h>
#include <string.h>

const int MAX=50000;

bool notp[50010];
int np;
int prime[30000];
int ans[50010];

void Build() {
	notp[0] = notp[1] = true;
	for(int i=4;i<=MAX;i+=2)	notp[i] = true;
	for(int i=9;i<=MAX;i+=3)	notp[i] = true;
	int i,k;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if( !notp[i] )
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = true;
	np=2;
	prime[0] = 2; prime[1] = 3;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if( !notp[i] )
			prime[np++] = i;
	ans[1] = 0;
	ans[2] = 1;
	for(int i=3;i<=MAX;++i) {
		if( !notp[i] )
			ans[i] = i-1;
		else {
			int temp = i;
			int sum = i;
			for(int j=0;j<np && prime[j] <= i && temp;++j)
				if(temp%prime[j] == 0) {
					sum = sum-sum/prime[j];
					temp /= prime[j];
				}
			ans[i] = sum;
		}
	}
	for(int i=2;i<=MAX;++i)
		ans[i] += ans[i-1];
}

int main() {

	Build();
	
	int n;
	while(scanf("%d",&n) && n)
		printf("%d\n",ans[n]*2+1);

	return 0;
}
