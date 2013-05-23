#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, t;
int s[110];
bool dp[10010];

int main() {

	while( scanf("%d%d",&n,&t) && n+t ) {
		
		for(int i=1;i<=n;++i) {
			char str[100];
			scanf("%s", str);
			s[i] = 0;
			int len = strlen(str);
			for(int j=0;j<len;++j) {
				if(str[j] == '.')	continue;
				s[i] = s[i]*10+str[j]-'0';
			}
		}
		
		if(s[t] > 5000) {
			puts("100.00");
			continue;
		}
		
		int tp = s[1];
		s[1] = s[t];
		s[t] = tp;
		memset(dp, 0, sizeof(dp));
		dp[s[1]] = 1;
		for(int i=2;i<=n;++i)
			for(int j=10000;j-s[i] >= s[1];--j)
				if(dp[j-s[i]])	dp[j] = 1;
		
		int i;
		for(i=5001;i<=10000 && !dp[i];++i);
		
		double ans = (double)s[1]/(double)i;
		ans *= 100.00;
		printf("%.2lf\n", ans);
		
	}

	return 0;
}
