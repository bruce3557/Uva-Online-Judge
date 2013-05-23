#include <stdio.h>
#include <string.h>

const int MAX = 1000000;

int np, num;
int prime[300000];
bool notp[MAX+10];
int N[MAX+10];

inline void Build() {
	notp[0] = notp[1] = 1;
	for(int i=4;i<=MAX;i+=2)
		notp[i] = true;
	for(int i=9;i<=MAX;i+=3)
		notp[i] = true;
	for(int i=5,k=2;i*i<=MAX;i+=k,k=6-k)
		if( !notp[i] )
			for(int j=i*i;j<=MAX;j+=i)
				notp[j] = true;
	prime[0] = 2;	prime[1] = 3;
	np = 2;
	for(int i=5,k=2;i<=MAX;i+=k,k=6-k)
		if( !notp[i] )
			prime[np++] = i;
			
	//printf("%d: %d\n", 38, notp[38]);
	N[0] = 1;
	//printf("%d ",N[0]);
	for(int i=1;i<=MAX;++i) {
		if( notp[N[i-1]] == 0 ) {
			N[i] = N[i-1]+2;
			//if( i  <= 20)	printf("%d ",N[i]);
			continue;
		}
		int tp = N[i-1];
		int sum = 1;
		bool suc = false;
		for(int j=0;j<np && tp > 1 && prime[j] <= tp;++j) {
			int count = 0;
			while( tp > 1 && (tp%prime[j]) == 0 ) {
				++count;
				tp /= prime[j];
			}
			if(count > 0) {
				sum *= (count+1);
				suc = true;
			}
		}
		N[i] = N[i-1]+sum;
		if(N[i] > MAX) {
			num = i+1;
			break;
		}
		/*if(N[i] > MAX) {
			printf("%d %d\n",i,N[i]);
			break;
		}*/
		//if(i <= 20)	printf("%d ",N[i]);
	}
	//puts("");
}

int main() {
	int t, cases=0;
	int A, B;
	
	Build();
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&A,&B);
		int pa, pb;
		
		int st, ed;
		st = 0, ed = num;
		while(st < ed) {
			int mid = (st+ed)/2;
			if( N[mid] < A )
				st = mid+1;
			else 
				ed = mid;
		}
		pa = ed;
		//printf("%d %d: %d\n",st, ed, N[pa]);
		
		st = 0, ed = num;
		while(st < ed) {
			int mid = (st+ed)/2;
			if( N[mid] <= B )
				st = mid+1;
			else 
				ed = mid;
		}
		pb = ed;
		printf("Case %d: %d\n",++cases,pb-pa);
	}
	return 0;
}
