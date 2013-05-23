#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX (32767)
using std::vector;

int n;
int pcnt,prime[5000];
int cnt[5000];
bool notp[33000];
struct node {
	int num, count;
	
	node() {
		count=0;
	}
	
	bool operator < (const node &t) const {
		return num > t.num;
	}
};

void Sieve() {
	notp[0] = notp[1] = 1;
	for(int i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = 1;
	int i,k;
	for(i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if(!notp[i])
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	pcnt = 0;
	for(int i=2;i<=MAX;++i)
		if(!notp[i])
			prime[pcnt++] = i;
}

int main() {

	Sieve();
	
	int a,b;
	char c;
	while(1) {
		scanf("%d%c",&a,&c);
		if(a == 0)	break;
		n = 1;
		while(1) {
			scanf("%d%c",&b,&c);
			for(int i=0;i<b;++i)	n*=a;
			if(c == '\n')	break;
			scanf("%d%*c",&a);
		}
		//puts("VVVVVVVVVVVVVVV");
		--n;
		memset(cnt,0,sizeof(cnt));
		/*
		for(int i=0;i<pcnt;++i)
			printf("%d ",prime[i]);
		puts("");
		*/
		for(int i=0;i<pcnt;++i) {
			while(n && (n%prime[i] == 0)) {
				++cnt[i];
				n/=prime[i];
			}
		}
		//puts("EEEEEEEEEEEEEEE");
		//fflush(stdout);
		vector<node> ans;
		for(int i=0;i<pcnt;++i)
			if(cnt[i]) {
				node temp;
				temp.num = prime[i];
				temp.count = cnt[i];
				ans.push_back(temp);
			}
		std::sort(ans.begin(),ans.end());
		int size=ans.size();
		for(int i=0;i<size-1;++i)
			printf("%d %d ",ans[i].num,ans[i].count);
		printf("%d %d\n",ans[size-1].num,ans[size-1].count);
	}

	return 0;
}
