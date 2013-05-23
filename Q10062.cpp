#include <stdio.h>
#include <string.h>
#include <algorithm>

int n;
char s[1010];

struct node {
	int a,sum;
	
	bool operator < (const node &t) const {
		return sum < t.sum || (sum == t.sum && a > t.a);
	}
} G[150];

int main() {
	int i,j,c=0;
	
	while(gets(s) != NULL) {
		if(c)	puts("");
		else	c = 1;
		memset(G,0,sizeof(G));
		n = strlen(s);
		for(i=0;i<n;i++)
			G[s[i]].sum++;
		for(i=0;i<129;i++)
			G[i].a = i;
		std::sort(G,G+150);
		for(i=0;i<150;i++)
			if(G[i].sum != 0) {
				printf("%d %d\n",G[i].a,G[i].sum);
			}
	}
	
	return 0;
}
