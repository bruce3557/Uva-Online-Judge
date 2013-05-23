#include <stdio.h>
#include <string.h>

int n;
bool notp[1000010];
int prime[400010],len;
int ANS[1000010],counter[1000010];

int main() {
	int i,j,k;
	for(i=4;i<=1000000;i+=2)	notp[i] = true;
	for(i=9;i<=1000000;i+=3)	notp[i] = true;
	for(i=5,k=2;i<=1000000/i;i+=k,k=6-k)
		if(notp[i] == false)
			for(j=i*i;j<=1000000;j+=i)
				notp[j] = true;
	
	len = 2;
	prime[0] = 2,prime[1] = 3;
	for(i=5,k=2;i<=1000000;i+=k,k=6-k)
		if(notp[i] == false)
			prime[len++] = i;
	for(i=0;i<len;i++)
		for(long long jj=prime[i];jj<=1000000;jj*=prime[i])
			counter[jj] = prime[i];
	
	ANS[1] = 1, ANS[2] = 2;
	ANS[3] = 6, ANS[4] = 2;
	ANS[5] = 6, ANS[6] = 6;
	for(n=7;n<=1000000;n++) {
		if(counter[n]) {
			if(counter[n] == 5) {
				int tmp = counter[n]*ANS[n-1];
				while(tmp % 10 == 0)	tmp /= 10;
				ANS[n] = tmp%10;
			} else {
				ANS[n] = (counter[n]*ANS[n-1])%100;
			}
		} else {
			ANS[n] = ANS[n-1];
		}
	}
	
	while(scanf("%d",&n) && n)
		printf("%d\n",ANS[n]%10);
	
	return 0;
}
