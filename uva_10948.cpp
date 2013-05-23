#include <stdio.h>
#include <string.h>
#define MAX (1000000)

int n;
int prime[MAX],pcnt;
bool notp[MAX+10];

void Build() {
	notp[0] = notp[1] = true;
	for(int i=4;i<=MAX;i+=2)
		notp[i] = true;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = true;
	int i=5,k=2;
	for(;i*i<=MAX;i+=k,k=6-k)
		if(!notp[i] )
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = true;
	pcnt=0;
	for(int i=2;i<=MAX;++i)
		if(notp[i] == false)
			prime[pcnt++] = i;
}

int main() {
	Build();
	
	while(scanf("%d",&n) &&n) {
		printf("%d:\n",n);
		int ans=-1;
		for(int i=0;i<pcnt && prime[i] < n;++i)
			if(notp[n-prime[i]] == false) {
				ans = prime[i];
				break;
			}
		if(ans == -1)
			puts("NO WAY!");
		else
			printf("%d+%d\n",ans,n-ans);
	}

	return 0;
}
