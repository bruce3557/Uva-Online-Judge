//be careful about the vertical line and horizontal line

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using std::vector;

bool used[1000];
char str[1000010];
int size;
struct node {
	long long x, y;
}p, pivot[10010], S[10010];

bool comp(const node &a, const node &b) {
	long long adx = a.x-p.x;
	long long ady = a.y-p.y;
	long long bdx = b.x-p.x;
	long long bdy = b.y-p.y;
	return	(ady*bdx < bdy*adx);
}

int main() {
	int t;
	long long tx, ty;
	int c=0;
	while(1) {
		gets(str);
		if(sscanf(str,"%d",&t) == 1)	break;;
	}
	gets(str);
	while(t--) {
		size = 0;
		while(1) {
			if(gets(str) == NULL)	break;
			if( sscanf(str, "%lld%lld",&tx,&ty) < 2)	break;
			pivot[size] = (node){tx,ty};
			++size;
		}
		
		if(c)	puts("");
		else	c=1;
		
		int maxx = 0;
		for(int i=0;i<size;++i) {
			p = pivot[i];
			int cnt = 1;
			int ssize = 0;
			for(int j=0;j<size;++j) {
				if(i == j)	continue;
				if(pivot[i].x == pivot[j].x)	++cnt;
				else {
					S[ssize] = pivot[j];
					++ssize;
				}
			}
			if(cnt > maxx)	maxx = cnt;
			std::sort(S,S+ssize,comp);
			int pp = 0;
			cnt = 2;
			for(int j=1;j<ssize;++j) {
				if(S[j].x == p.x && S[j].y == p.y)	continue;
				long long dx = S[j].x-p.x;
				long long dy = S[j].y-p.y;
				long long ddx = S[j-1].x-p.x;
				long long ddy = S[j-1].y-p.y;
				if( dy*ddx == ddy*dx ) {
					++cnt;
				}else {
					if(cnt > maxx)	maxx = cnt;
					cnt = 2;
					pp = j;
				}
			}
			if(cnt > maxx) maxx = cnt;
		}
		
		printf("%d\n",maxx);
	}

	return 0;
}
