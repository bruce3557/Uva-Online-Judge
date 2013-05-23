//seg = N+2*P

#include <stdio.h>
#include <string.h>

int n;

struct Point {
	double x,y;
};

struct node {
	int x1,y1,x2,y2;
	
	void get() {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	}
} line[1010];

struct Vector {
	double vx,vy;
};

inline double cross(Vector a, Vector b) {
	return (a.vx*b.vy-a.vy*b.vx);
}

inline bool Intersection(int a, int b) {
	Vector tp, rp, dp;
	tp.vx = line[a].x2-line[a].x1; tp.vy = line[a].y2-line[a].y1;
	rp.vx = line[b].x1-line[a].x1; rp.vy = line[b].y1-line[a].y1;
	dp.vx = line[b].x2-line[a].x1; dp.vy = line[b].y2-line[a].y1;
	return (cross(tp, rp)*cross(tp, dp) < 0);
}

int main() {
	int t;
	int c=0;
	
	scanf("%d",&t);
	while(t--) {
		if(c)	puts("");
		else	c=1;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			line[i].get();
		
		int sum=0;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(Intersection(i, j))
					++sum;
		
		printf("%d\n",n+sum*2);
	}
	
	return 0;
}
