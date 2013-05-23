#include <stdio.h>

int s[50010],n;

int main() {

	int i,j,q,target,len;
	int st,ed,mid;
	scanf("%d",&n);
	
	for(i=len=0;i<n;i++) {
		scanf("%d",&j);
		if(s[len-1] != j)		s[len++] = j;
	}
	
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&target);
		st = 0, ed = len;
		while(st < ed) {
			mid = (st+ed)/2;
			if(s[mid] == target)
				break;
			else if(s[mid] < target)
				st = mid+1;
			else
				ed = mid;
		}
		if(st >= ed) {
			if(ed == 0) {
				printf("X %d\n",s[0]);
				continue;
			}
			if(st >= len) {
				printf("%d X\n",s[len-1]);
				continue;
			}
			printf("%d %d\n",s[ed-1],s[ed]);
		} else {
			if(mid == 0 && mid == len-1) {
				printf("X X\n");
				continue;
			}
			if(mid == 0) {
				printf("X %d\n",s[mid+1]);
			} else if(mid == len-1) {
				printf("%d X\n",s[mid-1]);
			} else {
				printf("%d %d\n",s[mid-1],s[mid+1]);
			}
		}
	}
	
	return 0;
}
