/*
 *  uva_10243.cpp
 *  
 *
 *  Created by Bruce Kuo on 2011/10/20.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using std::queue;
using std::vector;

int n;
int len[1010];
bool used[1010];
int parent[1010];

vector<int> e[1010];

inline bool read() {
	scanf("%d",&n);
	if( !n )	return false;
	for(int i=1;i<=n;++i)
		e[i].clear();
	for(int i=1;i<=n;++i) {
		int x;
		scanf("%d",&x);
		len[i] = x;
		for(int j=0;j<x;++j) {
			int y;
			scanf("%d",&y);
			e[i].push_back(y);
		}
	}
	return true;
}

void go(int now, int pi) {
	parent[now] = pi;
	used[now] = 1;
	int size = e[now].size();
	for(int i=0;i<size;++i) {
		if( pi == e[now][i] || used[e[now][i]] )	continue;
		go(e[now][i], now);
	}
}

inline void Solve() {
	int ans = 0;

	memset(used, 0, sizeof(used));
	parent[1] = -1;
	go(1, -1);
	queue<int> Q;
	for(int i=2;i<=n;++i)
		if(len[i] <= 1) {
			Q.push(i);
			//printf("%d ",i);
		}
	//puts("");
	//for(int i=1;i<=n;++i)
		//printf("%d %d\n",i,parent[i]);
	
	//printf("%d\n",Q.size());
	memset(used,0,sizeof(used));
	while( !Q.empty() ) {
		//printf("%d\n",Q.size());
		int tp = Q.front();
		Q.pop();
		//printf("%d %d\n",tp,parent[tp]);
		if(tp == 1) {
			continue;
			if(e[tp].size() > 1 && !used[tp])	{
				++ans;
				used[tp] = 1;
			}
			continue;
		}
		
		if(parent[tp] != 1) {
			if(!used[parent[tp]]) {
				++ans;
				used[parent[tp]] = 1;
				//printf("%d %d\n",tp,parent[tp]);
			}
			--len[parent[tp]];
			if(len[parent[tp]] <= 1)	Q.push(parent[tp]);
		}
	}
	
	//if(used[tp] <= 0
	if(e[1].size() > 1 && !used[1])	++ans;
	printf("%d\n",ans);
}

int main() {
	while( read() ) Solve();
	return 0;
}

