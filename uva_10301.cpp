#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps (1e-9)

int n;
int count;
bool used[110];
bool map[110][110];
struct node {
	double x,y,r;
	
	void get() {
		scanf("%lf%lf%lf",&x,&y,&r);
	}
}ring[110];

bool overlap(int i, int j) {
	double dx = (ring[i].x-ring[j].x);
	double dy = (ring[i].y-ring[j].y);
	double dist = dx*dx+dy*dy;
	if(sqrt(dist)+ring[j].r <= ring[i].r || sqrt(dist)+ring[i].r <= ring[j].r)	return false;
	return (dist < (ring[i].r+ring[j].r)*(ring[i].r+ring[j].r));
}

void go(int now) {
	++count;
	used[now] = true;
	for(int i=0;i<n;++i)
		if(!used[i] && map[now][i])
			go(i);
}

int main() {

	while(scanf("%d",&n) && n!=-1) {
		for(int i=0;i<n;++i)
			ring[i].get();
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				map[i][j] = false;
		
		for(int i=0;i<n;++i)	
			for(int j=i+1;j<n;++j)
				if(overlap(i,j))
					map[i][j] = map[j][i] = true;
					
		int Max=0;
		memset(used,false,sizeof(used));
		for(int i=0;i<n;++i)
			if(!used[i]) {
				count = 0;
				go(i);
				if(count > Max)	Max = count;
			}
		
		if(Max == 1)
			printf("The largest component contains %d ring.\n",1);
		else
			printf("The largest component contains %d rings.\n",Max);
	}

	return 0;
}
