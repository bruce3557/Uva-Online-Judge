#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAX (99999999)

using std::vector;
using std::queue;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int n,m;
int cango[1010][1010];
int used[1010][1010];
char map[1010][1010];
struct node {
	int x,y,cnt;
}J;
vector<node> F;

inline void Input() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",map[i]);
	
	memset(cango,0,sizeof(cango));
	F.clear();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			if(map[i][j] == 'J')
				J = (node){i,j,0};
			if(map[i][j] == 'F')
				F.push_back((node){i,j,0});
			used[i][j] = MAX;
		}
}

inline int Solve() {
	queue<node> Q;
	int s = F.size();
	for(int i=0;i<s;i++) {
		Q.push((node){F[i].x,F[i].y,0});
		used[F[i].x][F[i].y] = 1;
	}
	while( !Q.empty() ) {
		node t = Q.front();
		for(int i=0;i<4;i++) {
			int tx = t.x+dx[i];
			int ty = t.y+dy[i];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] >= MAX && map[tx][ty] != '#') {
				used[tx][ty] = used[t.x][t.y]+1;
				Q.push((node){tx,ty,0});
			}
		}
		Q.pop();
	}
	while( !Q.empty() )	Q.pop();
	//Q.clear();
	
	if(used[J.x][J.y] >= 2) { Q.push((node){J.x,J.y,1}); }
	cango[J.x][J.y] = 1;
	while( !Q.empty() ) {
		node t = Q.front();
		if(t.x == 0 || t.y == 0 || t.x == n-1 || t.y == m-1)	return t.cnt;
		for(int i=0;i<4;i++) {
			int tx = t.x+dx[i];
			int ty = t.y+dy[i];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m && used[tx][ty] > t.cnt+1 && cango[tx][ty] == 0 && map[tx][ty] == '.') {
				cango[tx][ty] = t.cnt+1;
				Q.push((node){tx,ty,t.cnt+1});
			}
		}
		Q.pop();
	}	
	
	return -1;
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		Input();
		int num = Solve();
		if(num == -1)	puts("IMPOSSIBLE");
		else		printf("%d\n",num);
	}
	
	return 0;
}
