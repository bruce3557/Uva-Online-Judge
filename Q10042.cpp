#include <stdio.h>
#define MAX 39000

int len,prime[20000];
bool notp[MAX+10];

void pprime() {
	int i,j,k;
	notp[0] = notp[1] = 1;
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0) {
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
		}
	len = 2;
	prime[0] = 2,prime[1] = 3;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
}

int go(int x) {
	int sum = 0;
	while(x > 0) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}

bool smith(int n) {
	int i,j,sum1,sum2,tmp;
	int t;
	sum1 = sum2 = 0;
	tmp = n;
	while(tmp > 0) {
		sum1 += tmp%10;
		tmp /= 10;
	}
	tmp = n;
	for(i=0;i<len && prime[i] <= n/ prime[i];i++)
		if(n%prime[i] == 0) {
			tmp = 1;
			break;
		}
	if(tmp == n)	return 0;
	
	tmp = n;
	for(i=0;i<len && prime[i] <= n/prime[i];i++) {
		t = go(prime[i]);
		while(tmp % prime[i] == 0) {
			sum2 += t;
			tmp /= prime[i];
		}
	}
	if(tmp > 1)
		sum2 += go(tmp);
	
	return sum1 == sum2;
}

int main() {

	int t,n;
	
	pprime();
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(n++;smith(n) == 0;n++);
		printf("%d\n",n);
	}

	return 0;
}
