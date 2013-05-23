#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX (2000000)

using std::vector;
int n,ans,dp[1000010],aa[MAX+10];
vector< int > prime;
bool notp[MAX+10];

void GenPrime() {
	int i,j,k;
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
}

void Solve() {
	int tmp,min,k,ii,jj;
	memset(dp,0,sizeof(dp));
	vector< int > dep,next;
	vector< int >::iterator i,j;
	
	tmp = n,k=0;
	for(i=prime.begin();i!=prime.end() && (*i) <= n;i++) {
		if(tmp % (*i) == 0) {
			while(tmp % (*i) == 0) {
				tmp /= (*i);
				++dp[k];
			}
			dep.push_back((*i));
			++k;
		}
	}

	ans = -1;
	int a=1,size=dep.size();
	for(ii=0;ii<size;ii++)
		for(k=0;k<dp[ii];k++)
			a *= dep[ii];
	
	next.push_back(a);
	std::sort(dep.begin(),dep.end());
	for(i=next.begin();i != next.end();i++) {
		tmp = (*(next.end()-1));
		min = MAX+10;
		for(j=dep.begin();j!=dep.end();j++) {
			long long t = tmp*(*j);
			if(t < min)	min = t;
		}
		
		if(min > MAX) {
			min = -1;
			break;
		}
		if(min > n)	break;
		next.push_back(min);
	}
	ans = min;
	aa[n] = ans;
}

int main() {

	for(int i=0;i<=MAX;i++)	aa[i] = -2;
	GenPrime();

	while(scanf("%d",&n) != EOF) {
		if(aa[n] != -2) {
			if(aa[n] == -1)	puts("Not Exist!");
			else	printf("%d\n",aa[n]);
		}
		Solve();
		if(ans == -1)	puts("Not Exist!");
		else		printf("%d\n",ans);
	}

	return 0;
}
