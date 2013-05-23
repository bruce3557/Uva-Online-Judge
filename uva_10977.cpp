/*
 *  uva_10977.cpp
 *  
 *
 *  Created by Christina on 2011/8/6.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <queue>

using std::queue;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int R, C;
int m;
char map[210][210];
bool used[210][210];
struct node {
	int x, y, cnt;
	
	node(){}
	node(int _x, int _y, int _cnt) {
		x = _x;
		y = _y;
		cnt = _cnt;
	}
} mons[150];

bool readIn() {
	scanf("%d%d",&R,&C);
	if(R == 0 && C == 0)	return false;
	memset(map, false, sizeof(map));
	memset(used, false, sizeof(used));
	scanf("%d",&m);
	for(int i=0;i<m;++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		map[a][b] = 1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i)
		scanf("%d%d%d",&mons[i].x,&mons[i].y,&mons[i].cnt);
	return true;
}

inline long long dist(long long x, long long y) {
	return (x*x+y*y);
}

inline bool check(long long x, long long y) {
	if( x < 1 || y < 1 || x > R || y > C || used[x][y] || map[x][y] )	return false;
	for(int i=0;i<m;++i)
		if( dist(x-mons[i].x, y-mons[i].y) <= mons[i].cnt*mons[i].cnt )
			return false;
	return true;
}

int Solve() {
	queue<node> Q;
	if( check(1, 1) ) {
		used[1][1] = true;
		Q.push( node(1,1,0) );
	}
	while( !Q.empty() ) {
		node tp = Q.front();
		Q.pop();
		if( tp.x == R && tp.y == C )	return tp.cnt;
		for(int i=0;i<4;++i)
			if( check(tp.x+dx[i], tp.y+dy[i]) ) {
				used[tp.x+dx[i]][tp.y+dy[i]] = true;
				Q.push( node(tp.x+dx[i],tp.y+dy[i],tp.cnt+1) );
			}
	}
	return -1;
}

int main() {

	while( readIn() ) {
		int sol = Solve();
		if(sol != -1)	printf("%d\n",sol);
		else			puts("Impossible.");
	}
	
	return 0;
}
