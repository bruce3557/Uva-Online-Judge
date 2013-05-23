#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,s[1000010];
int used[100000];

int main() {

	int i,j;
	int ans1,ans2;
	int cnt,num;
	
	while(scanf("%d",&n) != EOF) {
		memset(used,0,sizeof(used));
		
		for(i=1;i<=n;i++) {
			scanf("%d",s+i);
			used[s[i]]++;
		}
		
		std::sort(s+1,s+1+n);
		
		cnt = num = 0;
		
		if(n & 1) {
			ans1 = s[(n+1)/2];
			cnt = used[ans1];
			printf("%d %d 1\n",ans1,cnt);
		} else {
			ans1 = s[n/2], ans2 = s[n/2+1];
			if(ans1 == ans2)
				cnt = used[ans1];
			else
				cnt = used[ans1]+used[ans2];
			num = ans2-ans1+1;
			printf("%d %d %d\n",ans1,cnt,num);
		}
		
	}

	return 0;
}
