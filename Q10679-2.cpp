#include <stdio.h>
#include <string.h>
#include <algorithm>

int sa[100010],n,len;
char T[100010],P[1010];

bool cmp(int a,int b) {
	return T[a] < T[b];
}

void build() {
	int i,j;
	n = strlen(T);
	for(i=0;i<n;i++)
		sa[i] = i;
	std::sort(sa,sa+n,cmp);
}

inline bool search() {
	int st = 0, ed = n, mid, c;
	while(st < ed) {
		mid = (st+ed)/2;
		c = strncmp(T+sa[mid],P,len);
		if(c == 0)	return true;
		else if(c < 0)	st = mid+1;
		else			ed = mid;
	}
	return false;
}

int main() {
	int t,m;
	bool result;
	
	scanf("%d%*c",&t);
	while(t--) {
		gets(T);
		build();
		scanf("%d%*c",&m);
		while(m--) {
			gets(P);
			len = strlen(P);
			result = search();
			if(result)
				puts("y");
			else
				puts("n");
		}
	}
	
	return 0;
}
