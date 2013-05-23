#include <stdio.h>
#include <string.h>

int n,k,ans[5000010],len;
char used[5000010];

void go(int now) {
	if(used[now] >= 2)	return;
	
	ans[len++] = now;
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		memset(used,0,sizeof(int)*(2<<n));
		len = 0;
		go(0);
		printf("%d\n",ans[len-1-k]);
	}
	
	return 0;
}
