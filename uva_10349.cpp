#include <stdio.h>
#include <string.h>

int n, m, N;
int pre[510];
char map[50][50];
int f[510][510];
bool used[50][50];
bool color[50][50];

int find(int now) {
	if(now == N)	return 1;
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
		pre[0] = 0;
		if( !find(0) )	return sum;
		++sum;
	}
}

int main() {
	int t;
	for(int i=1;i<=40;++i) {
		if(i%2)
			color[1][i] = true;
		else
			color[1][i] = false;
	}
	for(int i=2;i<=40;++i)
		for(int j=1;j<=40;++j) {
			if(color[i-1][j])
				color[i][j] = false;
			else
				color[i][j] = true;
		}
	
	scanf("%d",&t);
	while(t--) {
		memset(map, 0, sizeof(map));
		memset(f, 0, sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%s",map[i]+1);
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(color[i][j] && map[i][j] == '*') {
					if(i-1 > 0 && map[i-1][j] == '*')	f[i*m+j-1][(i-1)*m+j-1] = 1;
					if(i+1 <= n && map[i+1][j] == '*')	f[i*m+j-1][(i+1)*m+j-1] = 1;
					if(j-1 > 0 && map[i][j-1] == '*')	f[i*m+j-1][i*m+j-2] = 1;
					if(j+1 <= m && map[i][j+1] == '*')	f[i*m+j-1][i*m+j] = 1;
				}
		N = (n+1)*m+1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j) {
				if( color[i][j] && map[i][j] == '*' )
					f[0][i*m+j-1] = 1;
				else if(!color[i][j] && map[i][j] == '*')
					f[i*m+j-1][N] = 1;
			}
			
		memset(used,0,sizeof(used));
		int sum = Flow();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if( color[i][j] && map[i][j] == '*' && !used[i][j]) {
					if((i-1) > 0 && !used[i-1][j] && map[i-1][j] == '*' && f[(i-1)*m+j-1][i*m+j-1] > 0)
						used[i][j] = used[i-1][j] = 1;
					else if((i+1) <= n && !used[i+1][j] && map[i+1][j] == '*' && f[(i+1)*m+j-1][i*m+j-1] > 0)
						used[i][j] = used[i+1][j] = 1;
					else if((j-1) > 0 && !used[i][j-1] && map[i][j-1] == '*' && f[i*m+j-2][i*m+j-1] > 0)
						used[i][j] = used[i][j-1] = 1;
					else if((j+1) <= m && !used[i][j+1] && map[i][j+1] == '*' && f[i*m+j][i*m+j-1] > 0)
						used[i][j] = used[i][j+1] = 1;
				}
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(map[i][j] == '*' && !used[i][j])
					++sum;
		
		printf("%d\n",sum);
	}	
	
	return 0;
}
