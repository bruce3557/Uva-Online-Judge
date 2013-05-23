#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int n,m,len,anslen;
int set[510],ans[510];
char used[510];

struct node {
	double x,y;
}Node[510];

struct Edge {
	int a,b;
	double c;
	
	bool operator < (const Edge &t) const {
		return c<t.c;
	}
}e[510*510];

double Calc(int a,int b) {
	double t1,t2;
	t1 = Node[a].x-Node[b].x;
	t2 = Node[a].y-Node[b].y;
	return sqrt(t1*t1+t2*t2);
}

int Find(int now) {
	if(now == set[now])	return now;
	return set[now] = Find(set[now]);
}

double MST() {
	int i,sum;
	anslen = sum = 0;
	for(i=0;i<n;i++)
		set[i] = i;
	
	int limit = n-m-1;
	for(i=0;i<len && sum <= limit;i++) {
		int a = Find(e[i].a);
		int b = Find(e[i].b);
		if(a == b)	continue;
		sum++;
		set[a] = b;
		ans[anslen++] = i;
	}
	
	i = anslen-1;
	if(i < 0)	return 0.00;
	return e[ans[i]].c;
}

int main() {
	int t;
	int i,j;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&Node[i].x,&Node[i].y);
		
		len = 0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++) {
				double tmp = Calc(i,j);
				e[len++] = (Edge){i,j,tmp};
			}
		
		std::sort(e,e+len);
		printf("%.2lf\n",MST());
	}
	
	return 0;
}
