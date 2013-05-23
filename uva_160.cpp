#include <stdio.h>

int prime[110],num[110][110],len;
bool notp[110];

void pprime() {
	int i,j,k;
	for(i=4;i<=100;i+=2)
		notp[i] = 1;
	for(i=9;i<=100;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i<=10;i+=k,k=6-k)
		if(notp[i] == 0) {
			for(j=i*i;j<=100;j+=i)
				notp[j] = 1;
		}
	len = 2;
	prime[0] = 2, prime[1] = 3;
	for(i=5,k=2;i<=100;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[len++] = i;
}

void precalculate() {
	int i,j,tmp;
	for(i=2;i<=100;i++) {
		tmp = i;
		for(j=0;j<len && prime[j]<=i;j++)
			while(tmp%prime[j] == 0) {
				num[i][j]++;
				tmp /= prime[j];
			}
	}
	for(i=3;i<=100;i++)
		for(j=0;j<=100;j++)
			num[i][j] += num[i-1][j];
}

int main() {
	
	int n,i;
	
	pprime();
	precalculate();

	while(scanf("%d",&n) && n) {
		printf("%3d! =",n);
		for(i=0;num[n][i];i++) {
			if(i!=0 && i%15 == 0)	printf("\n%9d",num[n][i]);
			else					printf("%3d",num[n][i]);
		}
		puts("");
	}
	
	return 0;
}
