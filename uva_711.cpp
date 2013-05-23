#include <stdio.h>
#include <string.h>
#include <set>

using std::set;

int n[10], sum;
//bool dp[120010];

bool Input() {
	sum = 0;
	for(int i=1;i<=6;++i) {
		scanf("%d",n+i);
		sum += i*n[i];
	}
	return (n[1]+n[2]+n[3]+n[4]+n[5]+n[6]);
}

int main() {
	int cases = 0;
	while( Input() ) {
		printf("Collection #%d:\n",++cases);
		if(sum & 1) {
			puts("Can't be divided.\n");
			continue;
		}
		int goal = sum/2;
		//memset(dp, 0, sizeof(dp));
		set<int> S;
		S.insert(0);
		//dp[0] = 1;
		bool find = false;
		for(int i=6;i>0;--i) {
			if( S.find(goal) != S.end() ) {
				find = true;
				break;
			}
			set<int> next = S;
			for(set<int>::iterator it=S.begin();it != S.end();++it) {
				int x = (*it);
				for(int j=0;j*2<=n[i];++j) {
					//x += i;
					if(x > goal)	break;
					next.insert( x+i*j );
					next.insert( x+i*(n[i]-j) );
					if(next.find(goal) != next.end()) {
						find = true;
						break;
					}
				}
				if(find)	break;
			}
			if(find)	break;
			S = next;
		}
		if(find)	puts("Can be divided.\n");
		else		puts("Can't be divided.\n");
	}

	return 0;
}
