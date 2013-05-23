#include <stdio.h>
#include <string.h>
#include <algorithm>

int N[25],n;
int convex[25][110],convex_len[25];
bool used[25];
double area[25];
struct node {
	int x,y;
	
	node operator - (const node &t) {
		node tmp;
		tmp.x = x-t.x;
		tmp.y = y-t.y;
		return tmp;
	}
	
	bool operator < (const node &t) const {
		return x < t.x || (x == t.x && y < t.y);
	}
} point[25][110];

int cross_product(int now,int o,int a,int b) {
	node v1 = point[now][a]-point[now][o];
	node v2 = point[now][b]-point[now][o];
	return v1.x*v2.y-v1.y*v2.x;
}

void FindConvexHull(int now) {
	std::sort(point[now],point[now]+N[now]);

	int tmp = 0;
	for(int i=0;i<N[now];i++) {
		while(tmp >= 2 && cross_product(now,convex[now][tmp-2],convex[now][tmp-1],i) <= 0)	tmp--;
		convex[now][tmp++] = i;
	}
	int t = tmp+1;
	for(int i=N[now]-2;i>=0;i--) {
		while(tmp >= t && cross_product(now,convex[now][tmp-2],convex[now][tmp-1],i) <= 0)	tmp--;
		convex[now][tmp++] = i;
	}
	
	convex_len[now] = tmp;
}

double ABS(double x) {
	return x < 0 ? (-x) : x;
}

double Calc_Area(int now) {
	double sum = 0.00;
	
	for(int i=1;i<convex_len[now];i++) {
		int p1 = convex[now][i-1];
		int p2 = convex[now][i];
		sum += point[now][p1].x*point[now][p2].y-point[now][p1].y*point[now][p2].x;
	}
	
	return 0.5*sum;
}

int main() {
	
	n = 0;
	while(scanf("%d",&N[n]) && N[n] != -1) {
		for(int i=0;i<N[n];i++)
			scanf("%d%d",&point[n][i].x,&point[n][i].y);
		
		FindConvexHull(n);
		area[n] = Calc_Area(n);
		used[n] = false;
		n++;
	}	
	
	node missle;
	while(scanf("%d%d",&missle.x,&missle.y) != EOF) {
		for(int i=0;i<n;i++) {
			double sum = 0.00;
			for(int j=1;j<convex_len[i];j++) {
				int p1 = convex[i][j-1];
				int p2 = convex[i][j];
				sum += ABS(missle.x*point[i][p1].y+point[i][p1].x*point[i][p2].y+point[i][p2].x*missle.y
				      -point[i][p1].x*missle.y-point[i][p2].x*point[i][p1].y-missle.x*point[i][p2].y);
			}
			if(0.5*sum == area[i]) {
				used[i] = true;
				break;
			}
		}
	}
	
	double ans = 0.00;
	for(int i=0;i<n;i++)
		ans += area[i]*used[i];
	printf("%.2lf\n",ans);

	return 0;
}
