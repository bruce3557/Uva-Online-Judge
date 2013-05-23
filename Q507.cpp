#include <stdio.h>

int s[20010];

int main() {

	int t,c=0;
	int n,i,start,end,tmp;
	long long sum,max;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		
		for(i=1;i<=n-1;i++)
			scanf("%d",s+i);
		
		sum = max = 0;
		start = end = tmp = 1;
		
		for(i=1;i<=n-1;i++) {
			sum += s[i];
			if(sum < 0) {
				sum = 0;
				tmp = i+1;
			}
			if(sum > max) {
				max = sum;
				start = tmp;
				end = i;
			} else if(sum == max && end-start < i-tmp) {
				end = i;
				start = tmp;
			}
		}
		
		if(max <= 0)
			printf("Route %d has no nice parts\n",++c);
		else
			printf("The nicest part of route %d is between stops %d and %d\n",++c,start,end+1);
		
	}

	return 0;
}
