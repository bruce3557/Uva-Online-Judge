#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

int n,m, N;
int map[150][150];
int pre[150];

bool find(int now, int ed) {
	if(now == ed)	return true;
	
	for(int i=0;i<N;++i) {
		if(pre[i] != -1 || !map[now][i])	continue;
		pre[i] = now;
		if( find(i, ed) ) {
			--map[now][i];
			++map[i][now];
			return true;
		}
	}
	return false;
}

int Flow(int st, int ed) {
	int sum = 0;
	while(1) {
		for(int i=0;i<N;++i)
			pre[i] = -1;
		pre[0] = 0;
		if( !find(st,ed) )	return sum;
		++sum;
	}
}

int main() {
	
	while( scanf("%d %d",&n,&m) && n+m ) {
		int st = 0, ed = n+m+1;
		N = n+m+2;
		memset(map, 0, sizeof(map));
		
		int sum = 0;
		for(int i=1;i<=n;++i) {
			int x;
			scanf("%d",&x);
			sum += x;
			map[st][i] = x;
		}
		
		for(int i=1;i<=m;++i) {
			int x;
			scanf("%d",&x);
			map[i+n][ed] = x;
		}
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				map[i][j+n] = 1;
		
		int total = Flow(st,ed);
		if(total == sum) {
			for(int i=1;i<=n;++i) {
				vector<int> ans;
				for(int j=1;j<=m;++j)
					if(map[j+n][i])
						ans.push_back(j);
				if(ans.size() > 0) {
					printf("%d",ans[0]);
					for(int j=1;j<ans.size();++j)
						printf(" %d",ans[j]);
				}
				puts("");
			}
		} else {
			puts("0");
		}
	}
	
	return 0;
}
