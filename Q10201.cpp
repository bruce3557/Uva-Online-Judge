#include <stdio.h>
#include <string.h>

int n,s[110],cost[110];

int main() {
	int t;
	int i;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		i=0;
		while(scanf("%d%d",s+i,cost+i) && s[i] != n)	i++;
	}
	
	return 0;
}
