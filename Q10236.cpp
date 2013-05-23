#include <stdio.h>
#include <string.h>
#define MAX (2000000)

struct node {
	int len,s[250];
	
	node() {
		len = 0;
		memset(s,0,sizeof(s));
	}
	
	node operator + (node t) {
		int i,maxlen;
		node tmp;
		maxlen = len > t.len ? len : t.len;
		for(i=0;i<maxlen;i++)
			tmp.s[i] = s[i]+t.s[i];
		for(i=0;i<maxlen;i++)
			if(tmp.s[i] >= 10) {
				tmp.s[i+1] += tmp.s[i]/10;
				tmp.s[i] %= 10;
			}
		for(i=maxlen+5;i-1>0 && tmp.s[i-1] == 0;i--);
		tmp.len = i;
		return tmp;
	}
	
	void print() {
		if(len > 9) {
			for(int i=len-1;i>=len-9;i--)
				printf("%d",s[i]);
			puts("");
		} else {
			for(int i=len-1;i>=0;i--)
				printf("%d",s[i]);
			puts("");
		}
	}
	
} f[1000010];

bool notp[MAX];
int prime[150010],count;

int main() {
	int n;
	long long i,j,k;
	
	for(i=4;i<MAX;i+=2)
		notp[i] = 1;
	for(i=9;i<MAX;i+=3)
		notp[i] = 1;
	for(i=5,k=2;i<MAX;i+=k,k=6-k)
		if(notp[i] == 0)
			for(j=i*i;j<MAX;j+=i)
				notp[j] = 1;
	count=0;
	for(i=3;i<MAX;i++) {
		if(notp[i] == 0)
			prime[count++] = i;
		else if(i == 4)	prime[count++] = i;
	}
	//printf("%d %d\n",count,prime[count-1]);
	
	f[1].s[0] = f[2].s[0] = f[1].len = f[2].len = 1;
	for(i=3;i<=250000;i++)
		f[i] = f[i-1]+f[i-2];
	
	while(scanf("%d",&n) != EOF)
		f[prime[n-1]].print();
	
	return 0;
}
