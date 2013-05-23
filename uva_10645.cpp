#include <stdio.h>
#include <string.h>
#include <algorithm>

const double inf = 1e10;
const double eps = 1e-8;

int n,m,k;
double dp[23][110][60][2];
int path[23][110][60][2][4];
int state[4];
struct node {
	int cost;
	double ben;
	int id;
	
	bool operator < (const node &t) const {
		return (cost < t.cost);
	}
	
	void get(int _id) {
		int v;
		scanf("%d%d",&cost,&v);
		ben = v;
		id = _id;
	}
} item[50];

inline bool read() {
	scanf("%d%d%d",&k,&n,&m);
	if(!k && !n && !m)	return false;
	for(int i=0;i<n;++i)
		item[i].get(i);
	for(int i=0;i<=k;++i)
		for(int j=0;j<=m;++j)
			for(int q=0;q<=n;++q) {
				dp[i][j][q][0] = dp[i][j][q][1] = -inf;
				for(int z=0;z<4;++z)
					path[i][j][q][0][z] = path[i][j][q][1][z] = -1;
			}
	return true;
}

inline double go(int D, int M, int E, int C) {
	if(M < 0)	return -inf+1;
	if(D <= 0)	return 0;
	if(dp[D][M][E][C] > -inf)	return dp[D][M][E][C];
	
	double maximum = -inf+1;
	double temp;
	if(M-item[E].cost >= 0) {
		if(C == 1) {
			temp = go(D-1, M-item[E].cost, E, 0)+item[E].ben*0.5;
			if(temp > maximum) {
				maximum = temp;
				path[D][M][E][C][0] = D-1;
				path[D][M][E][C][1] = M-item[E].cost;
				path[D][M][E][C][2] = E;
				path[D][M][E][C][3] = 0;				
			}
			temp = go(D-1, M-item[E].cost, E, 1);
			if(temp > maximum) {
				maximum = temp;
				path[D][M][E][C][0] = D-1;
				path[D][M][E][C][1] = M-item[E].cost;
				path[D][M][E][C][2] = E;
				path[D][M][E][C][3] = 0;				
			}
		} else {
			for(int i=0;i<n;++i) {
				if(i == E)
					temp = go(D-1, M-item[E].cost, i, 0);
				else
					temp = go(D-1, M-item[E].cost, i, 0)+item[E].ben;
				if(temp > maximum) {
					maximum = temp;
					path[D][M][E][C][0] = D-1;
					path[D][M][E][C][1] = M-item[E].cost;
					path[D][M][E][C][2] = i;
					path[D][M][E][C][3] = 0;
				}
				if(i != E) {
					temp = go(D-1, M-item[E].cost, i, 1)+item[E].ben;
					if(temp > maximum){
						maximum = temp;
						path[D][M][E][C][0] = D-1;
						path[D][M][E][C][1] = M-item[E].cost;
						path[D][M][E][C][2] = i;
						path[D][M][E][C][3] = 1;
					}
				}
			}
		}
	}
	return (dp[D][M][E][C] = maximum);
}

void PrintPath(int a, int b, int c, int d) {
	if(a == 1) {
		printf("%d",item[c].id+1);
		return;
	}
	
	int e = path[a][b][c][d][0];
	int f = path[a][b][c][d][1];
	int g = path[a][b][c][d][2];
	int h = path[a][b][c][d][3];
	PrintPath(e,f,g,h);
	printf(" %d",item[c].id+1);
}

inline void Solve() {
	if(n == 1) {
		if( item[0].cost*k <= m ) {
			if(k > 1)
				printf("%.1lf\n",item[0].ben*1.5);
			else
				printf("%.1lf\n",item[0].ben);
			printf("1");
			for(int i=1;i<k;++i)
				printf(" 1");
			puts("");
		} else {
			puts("0.0\n");
		}
		return;
	}

	std::sort(item,item+n);
	double answer = -inf;
	for(int i=0;i<n;++i) {
		double temp = go(k,m,i,0);
		if(temp > answer) {
			answer = temp;
			state[0] = k;
			state[1] = m;
			state[2] = i;
			state[3] = 0;
		}
		temp = go(k,m,i,1);
		if(temp > answer) {
			answer = temp;
			state[0] = k;
			state[1] = m;
			state[2] = i;
			state[3] = 1;
		}
	}
	if(answer <= 0)	puts("0.0\n");
	else {
		printf("%.1lf\n",answer);
		PrintPath(state[0], state[1], state[2], state[3]);
		puts("");
	}
}

int main() {
	while( read() )	Solve();
	return 0;
}
