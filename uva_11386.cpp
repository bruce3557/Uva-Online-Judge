#include <stdio.h>
#include <algorithm>

int s[5010];

int main() {

	int i,j,k,tmp,n,a,b,t;
	long long ans;
	
	while(scanf("%d",&n) != EOF) {
	
		for(i=1;i<=n;i++)
			scanf("%d",s+i);
		
		std::sort(s+1,s+1+n);
		
		ans = t = 0;
		for(i=1;i<=n;i++) {
			j = 1, k = i-1;
			while(s[k] == s[i]) k--;
			while(j < k) {
				if(s[j] == s[i]-s[k]) {
					if(s[j] == s[k]) {
						ans += (k-j+1)*(k-j)/2;
						break;
					} else {
						tmp = s[j];
						a = b = 0;
						while(s[j] == tmp)
							a++,j++;
						tmp = s[k];
						while(s[k] == tmp)
							b++,k--;
						ans += a*b;
					}
				}
				else if(s[i]-s[k] > s[j])
					j++;
				else
					k--;
			}
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
