#include <stdio.h>
#include <string.h>
#include <queue>

using std::priority_queue;
int n;

struct node {
	int x;
	bool operator < (const node &t) const {
		return x>t.x;
	}
};

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(n == 0) {
			puts("0");
			continue;
		}
		if(n == 1) {
			puts("1");
			continue;
		}
		
		priority_queue<node> factor;
		int tmp = n;
		while(tmp > 1) {
			if(tmp % 2)	break;
			factor.push((node){2});
			tmp /= 2;
		}
		
		while(tmp > 1) {
			if(tmp % 3)	break;
			factor.push((node){3});
			tmp /= 3;
		}
		
		while(tmp > 1) {
			if(tmp % 5)	break;
			factor.push((node){5});
			tmp /= 5;
		}
		
		while(tmp > 1) {
			if(tmp % 7)	break;
			factor.push((node){7});
			tmp /= 7;
		}
		
		if(tmp > 1) {
			puts("-1");
			continue;
		}
		
		if(factor.size() < 2) {
			printf("%d\n",factor.top());
			continue;
		}
		
		while(1) {
			node a,b;
			a = factor.top();
			factor.pop();
			b = factor.top();
			factor.pop();
			if(a.x*b.x >= 10) {
				factor.push(a);
				factor.push(b);
				break;
			}
			factor.push((node){a.x*b.x});
		}
		
		while( !factor.empty() ) {
			printf("%d",factor.top().x);
			factor.pop();
		}
		puts("");
	}
	
	return 0;
}
