#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int n;
struct node {
	double x, y;
	
	void get() {
		scanf("%lf%lf",&x,&y);
	}
	
	bool operator < (const node &t) const {
		return (x < t.x || (x == t.x && y < t.y));
	}
	
}pt[10010];

inline double Dist(const node &a, const node &b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline double abs(double x) {
	return (x < 0) ? (-x) : (x);
}

int main() {
	
	while(scanf("%d",&n) && n) {
		double min = 10000;
		for(int i=0;i<n;++i)
			pt[i].get();
		std::sort(pt, pt+n);
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j) {
				if(pt[j].x-pt[i].x >= min)	break;
				if(abs(pt[i].y-pt[j].y) >= min)	continue;
				double dist=Dist(pt[i], pt[j]);
				if(dist < min)	min = dist;
			}
		
		if(min >= 10000)	puts("INFINITY");
		else	printf("%.4lf\n",min);
	}
	
	return 0;
}
