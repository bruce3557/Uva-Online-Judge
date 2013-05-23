#include <stdio.h>
#include <string.h>
#include <algorithm>

int n;
int lis[1010];
int p[1010];
struct node {
	int w, s, id;

	bool operator < (const node &t) const {
		return (w < t.w);
	}
	
	bool get(int _id) {
		int x = scanf("%d%d",&w,&s);
		if(x == EOF)	return false;
		id = _id;
		return true;
	}
} ele[1010];

void Print(int now) {
	if(now == -1)	return;
	Print(p[now]);
	printf("%d\n",ele[now].id+1);
}

void Solve() {
	std::sort(ele, ele+n);
	for(int i=0;i<n;++i) {
		lis[i] = 1;
		p[i] = -1;
	}
	
	for(int i=1;i<n;++i)
		for(int j=0;j<i;++j)
			if( ele[i].w > ele[j].w && ele[i].s < ele[j].s && lis[i] < lis[j]+1 ) {
				lis[i] = lis[j]+1;
				p[i] = j;
			}
			
	int max = 0;
	int ptr = 0;
	for(int i=0;i<n;++i)
		if(max < lis[i]) {
			max = lis[i];
			ptr = i;
		}
	printf("%d\n",max);
	Print(ptr);
}

int main() {

	while( ele[n].get(n) )	++n;
	Solve();

	return 0;
}
