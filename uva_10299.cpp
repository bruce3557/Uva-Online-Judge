#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
int pcnt;
int prime[80010];
int answer[1000010];
bool notp[100010];

inline void Build() {
	notp[0] = notp[1] = 1;
	for(int i=1;i<=1000000;++i)
		answer[i] = -1;
	for(int i=4;i<=100000;i+=2)
		notp[i] = 1;
	for(int i=9;i<=100000;i+=3)
		notp[i] = 1;
	int i,k;
	for(i=5,k=2;i*i<=100000;i+=k,k=6-k)
		if(!notp[i])
			for(int j=i*i;j<=100000;j+=i)
				notp[j] = 1;
	pcnt=0;
	for(int i=2;i<=100000;++i)
		if(!notp[i])
			prime[pcnt++] = i;
}

int Phi(int now, int ptr) {
	if(now == 1)	return 1;
	if(now <= 1000000 && answer[now] != -1)	return answer[now];
	if(now <= 100000 && notp[now] == 0)	return answer[now] = (now-1);
	if(ptr >= pcnt)	return now-1;
	int temp=now;
	int bound=(int)sqrt(temp);
	for(int i=ptr;i<pcnt && prime[i] <= bound;++i)
		if(temp%prime[i] == 0) {
			int count=1;
			while(temp%prime[i] == 0)	count*=prime[i],temp/=prime[i];
			return (count-count/prime[i])*Phi(temp, i+1);
		}
	if(temp != 1)	return (temp-1);
	return 1;
}

int main() {
	Build();

	answer[1]=0;
	while(scanf("%d",&n) && n) {
		if(n == 1) { puts("0"); continue; }
		int ans = Phi(n,0);		
		printf("%d\n",ans);
	}
	
	return 0;
}
