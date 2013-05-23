#include <stdio.h>

long long map[110][110];

int main() {
	
	int t,c=0,n;
	int i,j;
	char s[10],flag;
	
	scanf("%d",&t);
	
	while(t--) {
	
		scanf("%s%s%d",s,s,&n);
		
		flag = 0;		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++) {
				scanf("%lld",&map[i][j]);
				if(map[i][j] < 0)	flag = 1;
			}
		
		printf("Test #%d: ",++c);
		if(flag) {
			puts("Non-symmetric.");
			continue;
		}
			
		for(i=1;i<=n && flag == 0;i++)
			for(j=1;j<=n && flag == 0;j++)
				if(map[i][j] != map[n-i+1][n-j+1])
					flag = 1;
		
		if(flag)	puts("Non-symmetric.");
		else		puts("Symmetric.");
		
	}
	
	return 0;
}
