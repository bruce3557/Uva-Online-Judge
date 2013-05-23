#include <stdio.h>
#include <string.h>

int n,s[100010];
long long ans[30][100010];

void Solve() {

}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",s+i);
		for(i=0;i<=20;i++)
			memset(ans[i],0,sizeof(int)*(n+1));
		
		Solve();
		
		int query;
		scanf("%d",&query);
		while( query-- ) {
		
		}
	}
	
	return 0;
}
