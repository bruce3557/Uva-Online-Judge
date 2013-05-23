#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int n;
int Round,rt;
int ans[20], num[20];
int min_t;
int min_v;
int dp;
double Extra;
char used[20];
struct node {
	int x,y,v,l,id;
	
	void get() { scanf("%d%d%d%d",&x,&y,&v,&l);	}
	
	bool operator < (const node &t) const {	return (x < t.x || (x == t.x && y < t.y)); }
}tree[20], pt[20], ptt[20];

int CounterClockwise(int a,int b,int c) {
	return (tree[a].x*(tree[b].y-tree[c].y)+tree[b].x*(tree[c].y-tree[a].y)+tree[c].x*(tree[a].y-tree[b].y));
}

double Calc(int a, int b) {
	double dx = (double)tree[a].x-tree[b].x;
	double dy = (double)tree[a].y-tree[b].y;
	return sqrt(dx*dx+dy*dy);
}

double Convex_Hull() {	
	std::sort(pt,pt+Round);
	//FindLower
	int anslen = 0;
	int app[20];
	for(int i=0;i<Round;i++) {
		while(anslen >= 2 && CounterClockwise(app[anslen-2],app[anslen-1],pt[i].id) <= 0)	anslen--;
		app[anslen++] = pt[i].id;
	}
	
	//FindUpper
	int tmp = anslen+1;
	for(int i=Round-2;i>=0;i--) {
		while(anslen >= tmp && CounterClockwise(app[anslen-2],app[anslen-1],pt[i].id) <= 0)	anslen--;
		app[anslen++] = pt[i].id;
	}
	
	double dist=0;
	for(int i=1;i<anslen;++i)
		dist += Calc(app[i], app[i-1]);

	return dist;
}

void go(int now, int sum) {
	if(min_v < sum)	return;
	
	if(now > n) {
		if(min_v > sum || (min_v == sum && rt < min_t)) {
			Round=0;
			double ssum=0;
			for(int i=1;i<=n;++i) {
				if(!used[i])
					pt[Round++] = tree[i];
				else
					ssum += tree[i].l;
			}
			double temp = Convex_Hull();
			
			if(ssum > temp) {
				Extra = ssum-temp;
				min_v = sum;
				min_t = rt;
				dp = rt;
				for(int i=0;i<rt;++i)
					ans[i] = num[i];
			}
		}
		return;
	}
	go(now+1, sum);
	
	used[now] = 1;
	num[rt++] = now;
	go(now+1, sum+tree[now].v);
	--rt;
	used[now] = 0;
}

int main() {
	int c=0;
	while(scanf("%d",&n) && n) {
		if(c)	puts("");
		for(int i=1;i<=n;++i) {
			tree[i].get();
			tree[i].id = i;
		}
		
		printf("Forest %d\n",++c);		
		memset(used,0,sizeof(used));
		min_v = min_t = 99999999;
		Round = rt = dp = 0;
		go(1,0);
		printf("Cut these trees:");
		//print the trees
		for(int i=0;i<dp;++i)
			printf(" %d",ans[i]);
		puts("");
		printf("Extra wood: %.2lf\n", Extra);		
	}

	return 0;
}
