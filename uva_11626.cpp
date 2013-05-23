#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,len;
int anslen,ans[100010];
struct node {
	int x,y;
	
	bool operator < (const node &t) const {
		return x < t.x || (x == t.x && y < t.y);
	}
}Convex[100010];

void Input() {
	len = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int a,b;
		char c;
		scanf("%d %d %c",&a,&b,&c);
		Convex[len++] = (node){a,b};
	}
}

long long cross_product(int a,int b,int c) {
	long long dax,day,dbx,dby;
	dax = (Convex[b].x-Convex[a].x);
	dby = (Convex[c].y-Convex[a].y);
	day = (Convex[b].y-Convex[a].y);
	dbx = (Convex[c].x-Convex[a].x);
	return (dax*dby-day*dbx);
}

void FindConvex() {
	anslen = 0;
	
	for(int i=0;i<len;i++) {
		while(anslen >= 2 && cross_product(ans[anslen-2],ans[anslen-1],i) < 0)	anslen--;
		ans[anslen++] = i;
	}
	
	int t = anslen+1;
	for(int i=len-2;i>=0;i--) {
		while(anslen >= t && cross_product(ans[anslen-2],ans[anslen-1],i) < 0)	anslen--;
		ans[anslen++] = i;
	}
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		Input();
		std::sort(Convex,Convex+len);
		
		FindConvex();
		printf("%d\n",anslen-1);
		for(int i=0;i<anslen-1;i++)
			printf("%d %d\n",Convex[ans[i]].x,Convex[ans[i]].y);
	}
	
	return 0;
}
