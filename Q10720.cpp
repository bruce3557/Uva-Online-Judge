#include <stdio.h>
#include <algorithm>

int n,s[10010],ans;

int main() {
	int i,j,cnt;
	
	while(scanf("%d",&n) && n) {
		ans = 0;
		for(i=0;i<n;i++)
			scanf("%d",s+i);
		for(i=0;i<n;i++) {
			if(s[i] > (n-1) || s[i] < 0)	break;
			ans += s[i];
		}
		if(i < n || ans % 2) {
			puts("Not possible");
			continue;
		}
		
		cnt = 0;
		for(i=0;i<n;i++) {
			std::sort(s,s+n);
			if(s[n-1] > 0) {
				for(j=n-2;j>n-2-s[n-1] && s[j] > 0;j--)
					s[j]--;
				if(n-2-j < s[n-1]) {
					cnt = 1;
					break;
				}
				s[n-1] = 0;
			} else break;
		}
		
		if(cnt)	puts("Not possible");
		else		puts("Possible");
	}
	
	return 0;
}
