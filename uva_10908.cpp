#include <stdio.h>
#include <string.h>

int n,m;
char map[110][110];

inline bool fit(int len,int a,int b) {
	if(a-len < 0 || b-len < 0 || a+len >= n || b+len >= m)	return false;
	char test=map[a][b];
	for(int i=a-len;i<=a+len;++i)
		for(int j=b-len;j<=b+len;++j)
			if(map[i][j] != test)
				return false;
	return true;
}

int main() {
	int t;
	int Q;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&m,&Q);
		for(int i=0;i<n;++i)
			scanf("%s",map[i]);
		printf("%d %d %d\n",n,m,Q);
		int limit=(n<m)?n:m;
		while(Q--) {
			int a,b;
			scanf("%d%d",&a,&b);
			int st=0,ed=limit;
			while(st < ed) {
				int mid=(st+ed)/2;
				if(fit(mid,a,b))
					st = mid+1;
				else
					ed = mid;
			}
			printf("%d\n",2*ed-1);
		}
	}
	
	return 0;
}
