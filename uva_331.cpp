#include <stdio.h>
#include <string.h>

int n;
int s[10], ans, cnt;

bool check() {
	for(int i=0;i<n-1;++i)
		if(s[i] > s[i+1])	return false;
	return true;
}

void go(int now) {
	if( check() ) {
		if(cnt > now) {
			ans = 1;
			cnt = now;
		} else if(cnt == now) {
			++ans;
		}
		return;
	}
	for(int i=0;i<n-1;++i)
		if(s[i] > s[i+1]) {
			int tp = s[i];
			s[i] = s[i+1];
			s[i+1] = tp;
			go(now+1);
			tp = s[i];
			s[i] = s[i+1];
			s[i+1] = tp;
		}
}

int main() {
	int cases=0;
	
	while( scanf("%d",&n) && n) {
		for(int i=0;i<n;++i)
			scanf("%d", s+i);
		
		if(check()) {
			printf("There are 0 swap maps for input data set %d.\n", ++cases);
			continue;
		}
		
		cnt = 1000000;
		ans = 0;
		go(0);
		printf("There are %d swap maps for input data set %d.\n", ans, ++cases);
	}
	
	return 0;
}
