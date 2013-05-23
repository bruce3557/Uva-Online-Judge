#include <stdio.h>

int n,t[22];
long long s[10010];

int main() {
	int i,j;
	for(i=1;i<=21;i++)
		t[i] = i*i*i;
	s[0] = 1;
	for(i=1;i<=21;i++)
		for(j=t[i];j<=10000;j++)
			s[j] += s[j-t[i]];
		
	while(scanf("%d",&n) != EOF)
		printf("%lld\n",s[n]);
	
	return 0;
}
