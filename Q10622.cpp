#include <stdio.h>
#define MAX 100000

bool notp[MAX+10];

int len;
long long prime[50000];

void pprime() {
	int i,j,k;
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k) 
		if(notp[i] == 0) {
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
		}
	prime[0] = 2, prime[1] = 3;
	len = 2;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
}

int main() {

	int i,min,cnt,flag;
	long long n,tmp,a;
	
	pprime();
	while(scanf("%lld",&n) && n) {
		min = 50, tmp = a = n;
		flag  = 0;
		if(n < 0)	tmp = -n, a=-n;
		for(i=0;i<len && prime[i]<=a/prime[i];i++)
			if(a % prime[i] == 0) {
				flag = 1;
				break;
			}
		if(flag) {
			for(i=0;i<len && prime[i]<=a;i++) {
				cnt = 0;
				while(tmp % prime[i] == 0) {
					tmp /= prime[i];
					cnt++;
				}
			
				if(n < 0) {
					while(cnt && cnt % 2 == 0)
						cnt /= 2;
					if(cnt && min > cnt)	min = cnt;
				}
				else if(cnt && min > cnt)	min = cnt;
			}
		} else {
			min = 1;
		}
		printf("%d\n",min);
	}
	
	return 0;
}
