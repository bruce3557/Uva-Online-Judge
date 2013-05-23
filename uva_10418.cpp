#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX (999999999)
using std::queue;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int w,h,n,m,N;
int pre[150];
int f[210][210];
int map[150][150];
int cost[150][150];
int rest[150][150];
int limit[150];
int st, ed;

struct node {
	int x, y;
	
	void get() {
		scanf("%d%d",&x,&y);
	}
} red[60], green[60], hol[120], gold;

struct BFS {
	int x, y, count, color;
};

int find(int now) {
	if(now == ed)	return 1;
	for(int i=0;i<=N;++i)
		if(pre[i] == -1 && f[now][i] > 0) {
			pre[i] = now;
			if(find(i)) {
				--f[now][i];
				++f[i][now];
				return 1;
			}
		}
	return 0;
}

inline int Flow() {
	int sum=0;
	while(1) {
		for(int i=0;i<=N;++i)
			pre[i] = -1;
		if( !find(st) )	return sum;
		++sum;
	}
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		for(int i=0;i<110;++i)
			for(int j=0;j<110;++j)
				cost[i][j] = MAX;
	
		scanf("%d%d%d%d",&w,&h,&n,&m);
		for(int i=0;i<n;++i)
			red[i].get();
		for(int i=0;i<n;++i)
			green[i].get();
		gold.get();
		for(int i=0;i<m;++i) {
			int x, y, r;
			scanf("%d%d%d",&x,&y,&r);
			hol[i] = (node){x, y};
			limit[i] = r;
		}
		for(int i=1;i<=w;++i)	
			for(int j=1;j<=h;++j)
				scanf("%d",&map[i][j]);
		
		//Red
		for(int i=0;i<n;++i) {
			for(int j=1;j<=w;++j)
				for(int k=1;k<=h;++k)
					rest[j][k] = MAX;
			queue<BFS> Q;
			Q.push((BFS){red[i].x, red[i].y, 0, 0});
			rest[red[i].x][red[i].y] = 0;
			while( !Q.empty() ) {
				BFS tp = Q.front();
				Q.pop();
				int tx=tp.x;
				int ty=tp.y;
				for(int k=0;k<4;++k)
					if( tx+dx[k] > 0 && tx+dx[k] <= w && ty+dy[k] > 0 && ty+dy[k] <= h && rest[tx+dx[k]][ty+dy[k]] > tp.count) {
						if(tp.color == 0) {
							if(map[tx+dx[k]][ty+dy[k]] >= map[tx][ty]) {
								rest[tx+dx[k]][ty+dy[k]] = tp.count;
								Q.push((BFS){tx+dx[k], ty+dy[k], tp.count, tp.color});
							} else {
								if(rest[tx+dx[k]][ty+dy[k]] > tp.count+1) {
									rest[tx+dx[k]][ty+dy[k]] = tp.count+1;
									Q.push((BFS){tx+dx[k], ty+dy[k], tp.count+1, 1});
								}
							}
						} else {
							if(map[tx+dx[k]][ty+dy[k]] <= map[tx][ty]) {
								rest[tx+dx[k]][ty+dy[k]] = tp.count;
								Q.push((BFS){tx+dx[k], ty+dy[k], tp.count, tp.color});
							} else {
								if(rest[tx+dx[k]][ty+dy[k]] > tp.count+1) {
									rest[tx+dx[k]][ty+dy[k]] = tp.count+1;
									Q.push((BFS){tx+dx[k], ty+dy[k], tp.count+1, 0});
								}
							}
						}
					}
			}
			for(int j=0;j<m;++j)
				cost[i][j] = rest[hol[j].x][hol[j].y];
		}
		
		//Green
		for(int i=0;i<n;++i) {
			for(int j=1;j<=w;++j)
				for(int k=1;k<=h;++k)
					rest[j][k] = MAX;
			queue<BFS> Q;
			Q.push((BFS){green[i].x, green[i].y, 0, 1});
			rest[green[i].x][green[i].y] = 0;
			while( !Q.empty() ) {
				BFS tp = Q.front();
				Q.pop();
				int tx=tp.x;	int ty=tp.y;
				for(int k=0;k<4;++k)
					if( tx+dx[k] > 0 && tx+dx[k] <= w && ty+dy[k] > 0 && ty+dy[k] <= h && rest[tx+dx[k]][ty+dy[k]] > tp.count ) {
						if(tp.color) {
							if(map[tx+dx[k]][ty+dy[k]] <= map[tx][ty]) {
								rest[tx+dx[k]][ty+dy[k]] = tp.count;
								Q.push((BFS){tx+dx[k], ty+dy[k], tp.count, tp.color});
							} else {
								if(rest[tx+dx[k]][ty+dy[k]] > tp.count+1) {
									rest[tx+dx[k]][ty+dy[k]] = tp.count+1;
									Q.push((BFS){tx+dx[k], ty+dy[k], tp.count+1, 0});
								}
							}
						} else {
							if(map[tx+dx[k]][ty+dy[k]] >= map[tx][ty]) {
								rest[tx+dx[k]][ty+dy[k]] = tp.count;
								Q.push((BFS){tx+dx[k], ty+dy[k], tp.count, tp.color});
							} else {
								if(rest[tx+dx[k]][ty+dy[k]] > tp.count+1) {
									rest[tx+dx[k]][ty+dy[k]] = tp.count+1;
									Q.push((BFS){tx+dx[k], ty+dy[k], tp.count+1, 1});
								}
							}
						}
					}
			}
			for(int j=0;j<m;++j)
				cost[i+n][j] = rest[hol[j].x][hol[j].y];
		}
		
		//Build Flow Graph
		N = 2*n+m+1;
		st = N-1, ed = N;
		int up, low;
		up = 2*n+1; low = 0;
		while(low < up) {
			int i = (low+up)/2;
			memset(f, 0, sizeof(f));
			for(int j=0;j<n;++j)
				for(int k=0;k<m;++k) {
					if(cost[j][k] <= i)
						f[j][2*n+k] = 1;
					if(cost[j+n][k] <= i)
						f[j+n][2*n+k] = 1;
				}
			
			for(int j=0;j<n;++j)
				f[st][j] = f[st][j+n] = 1;
			for(int j=0;j<m;++j)
				f[2*n+j][ed] = limit[j];
			int sum = Flow();
			if(sum >= 2*n-i)
				up = i;
			else
				low = i+1;
		}
		
		printf("%d\n",up);
	}

	return 0;
}

