#include <stdio.h>

int gcd(int a,int b) {
	if(b == 0)	return a;
	return gcd(b,a%b);	
}

char is_prime(int x) {
	if(x & 1 == 0)	return 0;
	
	for(long long i = 3;i*i<=x;i+=2)
		if(x % i == 0)
			return 0;
			
	return 1;
}

int main() {

	int n,m;
	int i,tmp;
	char flag;

	while(scanf("%d%d",&n,&m) != EOF) {
		
		if(m <= n) {
			printf("%d divides %d!\n",m,n);
			continue;
		}
		
		if(is_prime(m)) {
			printf("%d does not divied %d!\n",m,n);
			continue;
		}
		
		flag = 0;
		tmp = m;
		for(i=2;i<=n;i++) {
			tmp /= gcd(i,tmp);
			
			if(tmp == 1) {
				flag = 1;
				break;
			}
			
		}
		
		if(flag)
			printf("%d divides %d!\n",m,n);
		else
			printf("%d does not divide %d!\n",m,n);
		
	}
	
	return 0;
}
