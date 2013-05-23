#include <stdio.h>
#include <algorithm>

struct node {

	int num,mod;
	
	bool operator < (node t) const {
	
		if(mod < t.mod) {
			return 1;
		} else if(mod > t.mod) {
			return 0;
		} else {
				
			if(num & 1) {
				if(t.num & 1)	return num > t.num;
				else			return 1;
			} else {
				if(t.num & 1)	return 0;
				else			return num < t.num;
			}
						
		}
		
		return 1;
	}
	
} s[10010];

int main() {
	
	int i,j,n,m;
	
	while(scanf("%d%d",&n,&m) && n+m) {
	
		for(i=0;i<n;i++) {
			scanf("%d",&s[i].num);
			s[i].mod = s[i].num%m;
		}
		
		std::sort(s,s+n);
		
		printf("%d %d\n",n,m);
		for(i=0;i<n;i++)
			printf("%d\n",s[i].num);
	
	}
	
	puts("0 0");
	
	return 0;
}
