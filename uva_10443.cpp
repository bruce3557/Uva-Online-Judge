/*
 *  uva_10903.cpp
 *  
 *
 *  Created by Christina on 2011/8/6.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int n,m,k;
int pivot;
char map[2][110][110];

int main() {
	int t=0;
	bool suc=false;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&m,&k);
		memset(map,0,sizeof(map));
		for(int i=0;i<n;++i)
			scanf("%s",map[0][i]);
		
		pivot = 0;
		for(int i=0;i<k;++i) {
			for(int j=0;j<n;++j)
				for(int q=0;q<m;++q) {
					bool fail = false;
					for(int e=0;e<4;++e) {
						if( j+dx[e] < 0 || j+dx[e] >= n || q+dy[e] < 0 || q+dy[e] >= m)	continue;
						if(map[pivot][j][q] == 'R' && map[pivot][j+dx[e]][q+dy[e]] == 'P') {
							map[1-pivot][j][q] = 'P';
							fail = true;
							break;
						}
						if(map[pivot][j][q] == 'S' && map[pivot][j+dx[e]][q+dy[e]] == 'R') {
							map[1-pivot][j][q] = 'R';
							fail = true;
							break;
						}
						if(map[pivot][j][q] == 'P' && map[pivot][j+dx[e]][q+dy[e]] == 'S') {
							map[1-pivot][j][q] = 'S';
							fail = true;
							break;
						}
					}
					if(!fail)
						map[1-pivot][j][q] = map[pivot][j][q];	   
				}
					
			pivot = 1-pivot;
		}
		
		if(suc)	puts("");
		else	suc = true;

		for(int i=0;i<n;++i,puts(""))
			for(int j=0;j<m;++j)
				printf("%c",map[pivot][i][j]);
	}
	
	return 0;
}
