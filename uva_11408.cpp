#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX (5000000)

using std::vector;
int ans[MAX+10];
bool notp[MAX+10];

int main() {
	int i,j,k;
	vector<int> prime;
	
	notp[0] = notp[1] = 1;
	for(i=4;i<=MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<=MAX;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i<=MAX/i;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<=MAX;j+=i)
				notp[j] = 1;
	
	prime.push_back(2);
	prime.push_back(3);
	for(i=5,k=2;i<=MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			prime.push_back(i);
	
	vector<int>::iterator i1;
	for(i1=prime.begin();i1 != prime.end();i1++) {
		for(j=(*i1);j<=MAX;j+=(*i1))
			ans[j] += (*i1);
	}
	
	for(i=2;i<=MAX;i++) {
		if(notp[ans[i]] == 0)
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for(i=2;i<=MAX;i++)
		ans[i] += ans[i-1];
	
	while(scanf("%d",&i) && i) {
		scanf("%d",&j);
		printf("%d\n",ans[j]-ans[i-1]);
	}
	return 0;
}
