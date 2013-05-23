#include <stdio.h>
#include <string.h>

int n,m;
int A[210], B[210];
int map[310][310];
int pre[310];
int min;

int find_path(int now,int ed){
    if(now == ed)	return 1;
    for(int i = 1;i <= ed; i++)
	   if(pre[i] == -1 && map[now][i] > 0){
	       if( min > map[now][i] )     min = map[now][i];
	       pre[i] = now;
	       if( find_path(i,ed) == 1 ){
				map[now][i] -= min;	map[i][now] += min;
				return 1;
	       }
		}
    return 0;
}
inline int Maxflow(int st,int ed){
	int i,sum = 0;
	while(1){
		for(i=1;i<=ed;i++)    pre[i] = -1;
		min = 999999999;
		pre[st] = 0;
		if( find_path(st,ed) == 0 )	return sum;
		sum += min;
	} 
}

inline void read() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",A+i);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%d",B+i);
}

inline void Solve() {
	static int cases=0;
	int st, ed;
	memset(map, 0, sizeof(map));
	st = 0; ed = n+m+1;
	int cnt = 0;
	for(int i=1;i<=m;++i)
		if( !B[i] )
			++cnt;
	for(int i=1;i<=n;++i) {
		//if( !A[i] )	++cnt;
		for(int j=1;j<=m;++j)
			if( A[i] && (B[j]%A[i]) == 0 ) {
				map[i][j+n] = 1;
			} else if(A[i] == 0 && B[j] == 0) {
				map[i][j+n] = 1;
			}
	}
	for(int i=1;i<=n;++i)
		map[st][i] = 1;
	for(int j=1;j<=m;++j)
		map[j+n][ed] = 1;
	printf("Case %d: %d\n",++cases, Maxflow(st,ed));
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		read();
		Solve();
	}
	return 0;
}
