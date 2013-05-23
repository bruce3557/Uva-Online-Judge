#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int n;
struct node {
	double x, y;
	
	void get() { scanf("%lf%lf",&x,&y); }
	
	bool operator < (const node &t) const {
		return (x < t.x);
	}
} pt[110];

inline double dist(const node &a, const node &b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			pt[i].get();
		
		std::sort(pt, pt+n);
		//puts("VVVVVVV");
		double high=pt[n-1].y;
		double length = 0.00;
		for(int i=n-2;i>=0;--i)
			if(pt[i].y > high) {
				length += dist(pt[i], pt[i+1])*(pt[i].y-high)/(pt[i].y-pt[i+1].y);
				high = pt[i].y;
			}
		printf("%.2lf\n", length);
	}
	
	return 0;
}
