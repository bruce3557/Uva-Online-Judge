#include <stdio.h>
#include <string.h>
#define MAX (1000000)

int n;
int len,pri[100000];
char notp[MAX+10];

void Build_Prime() {
	memset(notp,0,sizeof(notp));
	notp[0] = notp[1] = 1;
	for(int i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = 1;
	int i,j,k;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	len = 2;
	pri[0] = 2, pri[1] = 3;
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			pri[len++] = i;
}

int main() {
	int i,j,k;
	Build_Prime();
	
	while(scanf("%d",&n) && n) {
		for(i=1;pri[i]*2 <= n;i++)
			if(notp[n-pri[i]] == 0)	break;
		
		if(pri[i]*2 > n)	puts("Goldbach's conjecture is wrong.");
		else	printf("%d = %d + %d\n",n,pri[i],n-pri[i]);
	}

	return 0;
}
