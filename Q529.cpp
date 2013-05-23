#include <stdio.h>

int n,limit;
int ans[20],ty;

int log(int num) {
	int t = 0;
	while(num > 1) {
		if(num & 1)	t++;
		num = num>>1;
		t++;
	}
	return t;
}

bool go(int now) {
	if(now > limit || ans[now-1]*(1<<(limit-now)) < n)	return false;
	if(ans[now-1] == n)	return true;
	
	for(int i=now-1;i>=0;i--)
		if(ans[now-1]+ans[i] <= n) {
			ans[now] = ans[now-1]+ans[i];
			if( go(now+1) )	return true;
			ans[now] = 0;
		}
	
	return false;
}

int main() {

	while(scanf("%d",&n) && n) {
		ans[0] = 1;
		ty = log(n)+1;
		
		for(limit=1;limit<=ty;limit++)
			if( go(1) )	break;
		
		for(int i=0;i<limit-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[limit-1]);
	}

	return 0;
}
