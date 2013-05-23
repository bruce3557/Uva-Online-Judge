#include <stdio.h>
#include <string.h>

const int inf = 999999999;

int n,m;
int num;
int map[2000][2000];
int dist[2000];
char name[20];
bool used[2000];

inline bool read() {
	if( gets(name) == NULL )	return false;
	scanf("%d%d",&n,&m);
	num = n*m;
	for(int i=0;i<=num;++i)
		for(int j=0;j<=num;++j)
			map[i][j] = inf;
	for(int k=0;k<n-1;++k)
		for(int i=0;i<m;++i) {
			for(int j=0;j<m;++j) {
				int x;
				scanf("%d",&x);
				map[k*m+i][(k+1)*m+j] = x;
				//printf("(%d, %d), (%d, %d): %d\n",k,i,k+1,j,x);
			}
		}
	char str[1010];
	gets(str);
	return true;
}

inline void Solve() {
	for(int i=0;i<=num;++i) {
		dist[i] = inf;
		used[i] = false;
	}
	for(int i=0;i<m;++i)
		dist[i] = 0;
	for(int i=0;i<=num;++i) {
		int min = 99999999;
		int ptr = -1;
		for(int j=0;j<num;++j)
			if( !used[j] && min > dist[j] ) {
				min = dist[j];
				ptr = j;
			}
		//printf("ptr = %d\n",ptr);
		if( ptr == -1 || used[ptr] )	break;
		used[ptr] = true;
		for(int j=0;j<num;++j)
			if( !used[j] && dist[ptr]+map[ptr][j] < dist[j] )
				dist[j] = dist[ptr]+map[ptr][j];
	}
	int answer = inf;
	for(int i=0;i<m;++i)
		if(dist[(n-1)*m+i] < answer)
			answer = dist[(n-1)*m+i];
	//printf("%d\n",answer);
	puts(name);
	printf("%d\n",answer+(n-1)*2);
}

int main() {
	while( read() )	Solve();
	return 0;
}
