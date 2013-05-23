#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

int n,m;
using std::vector;

struct node {
	int val, id;
	
	node(){}
	node(int _val, int _id) {
		val = _val;
		id = _id;
	}
	
	bool operator < (const node &t) const {
		return (val > t.val || (val == t.val && id < t.id));
	}
};

int main() {

	while( scanf("%d%d",&n,&m) && n+m ) {
		vector<node> s1, s2;
		vector<int> ans[n+2];
		for(int i=1;i<=n;++i) {
			int x;
			scanf("%d",&x);
			s1.push_back( node(x, i));
		}
		for(int i=1;i<=m;++i) {
			int x;
			scanf("%d",&x);
			s2.push_back( node(x, i) );
		}
		//printf("%d %d\n",s1.size(), s2.size());
		bool suc = true;
		std::sort(s1.begin(), s1.end());
		for(int i=0;i<n;++i) {
			//printf("s1 %d\n",s1[i].id);
			std::sort(s2.begin(), s2.end());
			int num = s1[i].val;
			for(int j=0;num > 0 && j<m;++j) {
				//printf("s2 %d\n", s2[j].id);
				if(s2[j].val <= 0) {
					suc = false;
					break;
				}
				ans[s1[i].id].push_back(s2[j].id);
				--s2[j].val;
				--num;
			}
			//puts("");
			fflush(stdout);
			if(num > 0)	suc = false;
			if(!suc)	break;
		}
		//puts("ZZ");
		if(suc) {
			puts("1");
			for(int i=1;i<=n;++i) {
				if(ans[i].size() > 0) {
					std::sort(ans[i].begin(), ans[i].end());
					printf("%d",ans[i][0]);
					for(int j=1;j<ans[i].size();++j)
						printf(" %d",ans[i][j]);
				}
				puts("");
			}
		} else {
			puts("0");
		}
	}
	
	return 0;
}
