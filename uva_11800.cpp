#include <stdio.h>
#include <string.h>
#include <algorithm>
#define eps 1e-7

int n;
struct node {
	int x, y;
	
	void get() {
		scanf("%d%d",&x,&y);
	}
} pt[5];

int len[4];
int angle[4];

inline int cross(const node &o, const node &a, const node &b) {
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

inline int innerProduct(const node &a, const node &b, const node &c) {
	int v1x = b.x-a.x;	int v1y = b.y-a.y;
	int v2x = c.x-b.x;	int v2y = c.y-b.y;
	return (v1x*v2x+v1y*v2y);
}

inline bool Comp(const node &a, const node &b) {
	return (cross(pt[0], a, b) < 0);
}

inline int Dist(const node &a, const node &b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

inline int abs(int x) {
	return (x < 0) ? (-x) : x;
}

int main() {
	int cases=0;
	int t;
	
	scanf("%d",&t);
	while(t--) {
		for(int i=0;i<4;++i)
			pt[i].get();
		std::sort(pt+1, pt+4, Comp);
		pt[4] = pt[0];
		for(int i=0;i<3;++i) {
			len[i] = Dist(pt[i], pt[i+1]);
			angle[i] = innerProduct(pt[i], pt[i+1], pt[i+2]);
		}
		len[3] = Dist(pt[3], pt[4]);
		angle[3] = innerProduct(pt[3], pt[4], pt[1]);
		
		printf("Case %d: ", ++cases);
		if(angle[0] == angle[1] && angle[1] == angle[2] && angle[2] == angle[3] && angle[3] == 0) {
			if( len[0] == len[1] && len[1] == len[2] && len[2] == len[3] ) {
				puts("Square");
			} else {
				if(len[0] == len[2] && len[1] == len[3]) {
					puts("Rectangle");
				} else {
					puts("Ordinary Quadrilateral");
				}
			}
		} else {
			if(len[0] == len[1] && len[1] == len[2] && len[2] == len[3]) {
				puts("Rhombus");
			} else {
				if(len[0] == len[2] && len[1] == len[3]) {
					puts("Parallelogram");
				} else {
					if( (pt[1].y-pt[0].y)*(pt[3].x-pt[2].x) == (pt[3].y-pt[2].y)*(pt[1].x-pt[0].x) ||
					    (pt[2].y-pt[1].y)*(pt[4].x-pt[3].x) == (pt[4].y-pt[3].y)*(pt[2].x-pt[1].x) ) {
						puts("Trapezium");
					} else {
						puts("Ordinary Quadrilateral");
					}
				}
			}
		}
		
	}
	
	return 0;
}
