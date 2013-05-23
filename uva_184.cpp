#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using std::vector;
using std::set;

struct node {
	int x, y;
	
	bool operator < (const node &t) const {
		return (x < t.x || ( x == t.x && y < t.y ) );
	}
};

vector<node> S;

int main() {
	int tx, ty;
	
	while(scanf("%d%d",&tx,&ty) && tx+ty) {
		set< vector<node> > Q;
		S.clear();
		S.push_back((node){tx,ty});
		while(scanf("%d%d",&tx,&ty) && tx+ty)
			S.push_back((node){tx,ty});
		std::sort(S.begin(), S.end());
		int size = S.size();
		for(int i=0;i<size;++i)
			for(int j=i+1;j<size;++j) {
				int dx = S[i].x-S[j].x;
				int dy = S[i].y-S[j].y;
				vector<node> tmp;
				tmp.push_back(S[i]);
				tmp.push_back(S[j]);
				for(int k=0;k<size;++k)
					if(k != i && k != j) {
						int ddx = S[k].x-S[i].x;
						int ddy = S[k].y-S[i].y;
						if(dy*ddx == dx*ddy)	tmp.push_back(S[k]);
					}
					
				if(tmp.size() <= 2)	continue;
				std::sort(tmp.begin(), tmp.end());
				Q.insert(tmp);
			}
		
		if(Q.size() == 0) {
			puts("No lines were found");
		} else {
			puts("The following lines were found:");
			for(set< vector<node> >::iterator it=Q.begin(); it != Q.end();++it) {
				int siz = it->size();
				for(int i=0;i<siz;++i)
					printf("(%4d,%4d)",(*it)[i].x,(*it)[i].y);
				puts("");
			}
		}
	}

	return 0;
}
