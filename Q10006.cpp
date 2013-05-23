#include <stdio.h>

bool notp[100000];
int prime[20000];
int Cal[100000],len;

typedef unsigned int ui;

ui bm(ui b,ui p,ui m) {
	if(p == 0)	return 1;
	ui t = bm(b,p/2,m)%m;
	if(p % 2)
		return (t*t*b)%m;
	else
		return (t*t)%m;
}

bool test(ui t) {
	ui tmp;
	int count,i;
	for(i=0;i<len && prime[i]<=t/prime[i];i++)
		if(t % prime[i] == 0) {
			if((t-1)%(prime[i]-1))	return false;
			tmp = t;
			count = 0;
			while(tmp % prime[i] == 0) {
				tmp /= prime[i];
				count++;
				if(count >= 2)	return false;
			}
		}
	for(i=2;i<t;i++) {
		tmp = bm(i,t,t);
		if(tmp == i)	return true;
	}
	return false;
}

int main() {

	int n,i,j,k;
	bool t;
	notp[0] = notp[1] = 1;
	for(i=4;i<=65000;i+=2)
		notp[i] = 1;
	for(i=9;i<=65000;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i*i<=65000;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<=65000;j+=i)
				notp[j] = 1;
	len = 2;
	prime[0] = 2;
	prime[1] = 3;
	for(i=5,k=2;i<=65000;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
	
	while(scanf("%d",&n)!=EOF && n) {
		if(Cal[n] == 1)
			printf("The number %d is a Carmichael number.\n",n);
		else if(Cal[n] == 2)
			printf("%d is normal.\n",n);
		else {
			if(notp[n]) {
				t = test(n);
				if(t == true) {
					printf("The number %d is a Carmichael number.\n",n);
					Cal[n] = 1;
				} else {
					printf("%d is normal.\n",n);
					Cal[n] = 2;
				}
			} else {
				printf("%d is normal.\n",n);
				Cal[n] = 2;
			}
		}
	}
	return 0;
}
