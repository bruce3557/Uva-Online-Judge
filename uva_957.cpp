#include <stdio.h>
#include <string.h>

int Y, P;
int seq[100010];

inline bool read() {
	if(scanf("%d",&Y) == EOF)	return false;
	scanf("%d",&P);
	for(int i=0;i<P;++i)
		scanf("%d",seq+i);
	return true;
}

inline void Solve() {
	int maxi = 0;
	int from, to;
	//printf("%d %d\n",Y,P);
	for(int i=0;i<P;++i) {
		int st = i;
		int ed = P;
		int target = seq[i]+Y-1;
		while(st < ed) {
			int mid = (st+ed)/2;
			if( target >= seq[mid] )	st = mid+1;
			else	ed = mid;
		}
		//printf("%d %d\n",ed, i);
		int num = ed-i;
		if(maxi < num) {
			maxi = num;
			from = seq[i];
			to = seq[ed-1];
		}
	}
	printf("%d %d %d\n",maxi,from,to);
}

int main() {

	while( read() )
		Solve();

	return 0;
}
