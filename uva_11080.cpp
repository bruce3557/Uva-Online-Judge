#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

int n, ne;
int cnt, cr[210], cs;
vector<int> e[210];

int go(int now, int crs) {
	int size = e[now].size();
	cr[now] = crs;
	if(crs == 1)	++cs;
	++cnt;
	for(int i=0;i<size;++i) {
		int x = e[now][i];
		if(cr[x]) {
			if(cr[x] == crs)	return -1;
			continue;
		} else {
			if( go(x, -crs) == -1)	return -1;
		}
	}
	return 0;
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&ne);
		
		for(int i=0;i<n;++i)
			e[i].clear();
		
		memset(cr, 0, sizeof(cr));
		
		while(ne--) {
			int u, v;
			scanf("%d%d",&u,&v);
			if(u == v)	continue;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		int ans = 0;
		bool suc = true;
		for(int i=0;i<n;++i) {
			if(cr[i])	continue;
			cs = cnt = 0;
			int x = go(i, -1);
			if(x == -1)	{
				suc = false;
				break;
			}
			
			if(cnt == 1) {
				++ans;
				continue;
			}
			
			if(cs < cnt-cs)
				ans += cs;
			else
				ans += cnt-cs;
		}
		
		if(suc)	printf("%d\n",ans);
		else	puts("-1");
	}

	return 0;
}
