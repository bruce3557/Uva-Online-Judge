#include <stdio.h>
#include <algorithm>
#define MAX 2147483647

struct node {
	int num,a,b;
	bool operator < (node t) const {
		return num < t.num || (num == t.num && b < t.b);
	}
}sum[1000010],diff[1000010];

int s[1010],n,len1,len2;

bool find(node& x) {
	int st,ed,mid;
	st = 0, ed = len1;
	while(st < ed) {
		mid = (st+ed)/2;
		if(sum[mid].num == x.num) {
			if((sum[mid].a != x.a && sum[mid].b != x.b) && (sum[mid].b != x.a && sum[mid].a != x.b)) {
				return 1;
			} else {
				st = mid+1;
			}
		} else if(sum[mid].num < x.num) {
			st = mid+1;
		} else {
			ed = mid;
		}
	}
	return 0;
}

int main() {
	int i,j,max;
	
	while(scanf("%d",&n) && n) {
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
			
		len1 = len2 = 0;
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				sum[len1++] = (node) {s[i]+s[j],s[i],s[j]};
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i != j)
					diff[len2++] = (node) {s[i]-s[j],s[j],s[i]};

		std::sort(sum,sum+len1);
		
		max = -MAX;
		for(i=0;i<len2;i++)
			if(find(diff[i]) && diff[i].b > max)
				max = diff[i].b;
		
		if(max != -MAX) {
			printf("%d\n",max);
		} else {
			puts("no solution");
		}
	}

	return 0;
}
