#include <stdio.h>
#include <string.h>

int n,s[50];
bool dp[30010];

int main() {

	int i,j,k,c=0,sum;
	bool flag;
	
	while(scanf("%d",&n) != EOF) {
		flag = sum = 0;
		for(i=0;i<n;i++) {
			scanf("%d",s+i);
			sum += s[i];
		}
		printf("Case #%d:",++c);
		
		for(i=0;i<n;i++)
			printf(" %d",s[i]);
		
		for(i=1;i<n && flag == 0;i++)
			for(j=0;j<i;j++)
				if(s[i] <= s[j]) {
					flag = 1;
					break;
				}
		
		if(flag) {
			puts("\nThis is not an A-sequence.");
			continue;
		}
		
		for(i=0;i<n;i++) {
			memset(dp,0,sizeof(bool)*(s[i]+1));
			dp[0] = 1;
			for(j=0;j<i;j++)
				for(k=s[i];k>=s[j];k--)
					if(dp[k-s[j]])
						dp[k] = 1;
			if(dp[s[i]]) {
				flag = 1;
				break;
			}
		}
		
		if(flag) {
			puts("\nThis is not an A-sequence.");
			continue;
		}
		puts("\nThis is an A-sequence.");
	}

	return 0;
}
