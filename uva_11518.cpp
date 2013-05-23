#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

int n,m,q;
vector<int> e[10010];
bool used[10010];

void go(int u) {
	used[u] = true;
	int size = e[u].size();
	for(int i=0;i<size;++i) {
		int v = e[u][i];
		if(used[v])	continue;
		go(v);
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&m,&q);
		memset(used, 0, sizeof(used));
		for(int i=1;i<=n;++i)
			e[i].clear();
		for(int i=0;i<m;++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
		}
		while(q--) {
			int x;
			scanf("%d",&x);
			if( used[x] )	continue;
			go(x);
		}
		int count = 0;
		for(int i=1;i<=n;++i)
			if(used[i])
				++count;
		printf("%d\n",count);
	}	
	return 0;
}
