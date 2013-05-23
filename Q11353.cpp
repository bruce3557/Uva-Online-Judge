#include <stdio.h>
#include <algorithm>
#define MAX 2000000

struct node {
	int num,len;
	bool operator < (node t) const {
		return (len < t.len || (len == t.len && num < t.num));
	}
} s[MAX+10];

char notp[MAX+10];
int prime[200000],np;

int main() {

	int i,j,k;
	int n,c = 0;
	
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	
	prime[0] = 2, prime[1] = 3;
	np = 2;
	
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime[np++] = i;
	
	s[1] = (node){1,1};
	
	for(i=2;i<=MAX;i++) {
		s[i].num = i;
		if(notp[i] == 0) {
			s[i].len = 1;
			continue;
		}
		for(j=0;j<np && prime[j]<=i;j++)
			if(i % prime[j] == 0) {
				s[i].len = s[i/prime[j]].len+1;
				break;
			}
	}
	
	std::sort(s+1,s+MAX+1);
	
	while(scanf("%d",&n) && n) {
		printf("Case %d: %d\n",++c,s[n]);
	}
	
	return 0;
}
