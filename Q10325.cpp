#include <stdio.h>
#include <algorithm>

int d[20];
char isdiv[20];

int main() {
	int n,m,ans,another;
	int i,j;
	
	while(scanf("%d%d",&n,&m) != EOF) {
	
		for(i=0;i<m;i++) {
			scanf("%d",d+i);
			isdiv[i] = 0;
		}
		std::sort(d,d+m);
		
		for(i=0;i<m;i++)
			for(j=0;j<i;j++)
				if(d[i]%d[j] == 0)
					isdiv[i] = 1;
		
		for(i=0;i<m;i++) 
			if(isdiv[i] == 0)
				printf("%d ",d[i]);
		puts("");
		
		//another = n/d[0];
		ans = n-n/d[0];
		//if(n%d[0] == 0) ans++;
		printf("%d ",ans);
		for(i=1;i<m;i++)
			if(isdiv[i] == 0)  {
				//another = ans/d[i];
				long long t = (long long)ans*d[i]-ans;
				if(t % d[i])
					ans -= ans/d[i]+1;
				else
					ans -= ans/d[i];
				printf("%d ",ans);
			}
		puts("");
		
		printf("%d\n",ans);
	}
	
	return 0;
}
