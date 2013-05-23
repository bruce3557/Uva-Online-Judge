#include <stdio.h>
#include <string.h>
#define MAX (10000)

int n,m;
bool notp[MAX+10];
int prime[MAX],pcnt;
int fac[MAX];

inline void Build() {
	for(int i=4;i<=MAX;i+=2)
		notp[i] = true;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = true;
	int i=5,k=2;
	for(;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = true;
	pcnt=2;
	prime[0]=2,prime[1]=3;
	i=5,k=2;
	for(;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[pcnt++] = i;
}

inline int Min(int a, int b) { return a<b?a:b; }

int main() {
	int t,c=0;
	Build();
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&m,&n);
		memset(fac,0,sizeof(fac));
		for(int i=2;i<=n;++i) {
			int temp = i;
			for(int j=0;temp > 1 && j<pcnt && prime[j] <= temp;++j)
				while(temp%prime[j] == 0) {
					++fac[j];
					temp /= prime[j];
				}
		}
		
		int max=99999999;
		int temp = m;
		for(int i=0;temp > 1 && i<pcnt && prime[i] <= temp;++i)
			if(temp%prime[i] == 0) {
				int count = 0;
				while(temp%prime[i] == 0) {
					++count;
					temp /= prime[i];
				}
				max = Min(max, fac[i]/count);
			}
		if(max == 0)
			printf("Case %d:\nImpossible to divide\n",++c);
		else
			printf("Case %d:\n%d\n",++c,max);
	}
	
	return 0;
}
