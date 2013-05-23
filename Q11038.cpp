#include <stdio.h>
#include <string.h>

long long f(int n) {
	if(n < 0)	return 1;
	long long sum=0,i;
	//sum = n/10;
	for(i=1;i*10<n;i*=10) {
		long long tmp = (n/i)%10;
		if(tmp) 
			sum += (n/(i*10))*i;
		else
			sum += n%i+(n/(i*10)-1)*i+1;
	}
	return sum+1;
}

int main() {
	int n,m;
	
	while(1) {
		scanf("%d %d",&n,&m);
		if(n < 0 || m < 0)	break;
		printf("%lld\n",f(m)-f(n-1)+(n==0));
	}
	
	return 0;
}
