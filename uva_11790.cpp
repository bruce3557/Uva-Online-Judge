/*
 *  uva_11790.cpp
 *  
 *
 *  Created by Bruce Kuo on 2011/10/20.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int n;
int lis[2010], lds[2010];
struct node {
	int h, w;
} build[2010];

int main() {
	int t, cases=0;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&build[i].h);
		for(int i=0;i<n;++i)
			scanf("%d",&build[i].w);
		
		memset(lis,0,sizeof(lis));
		memset(lds,0,sizeof(lds));
		for(int i=0;i<n;++i) 
			lis[i] = lds[i] = build[i].w;
		for(int i=1;i<n;++i)
			for(int j=0;j<i;++j)
				if(build[i].h > build[j].h && lis[j]+build[i].w > lis[i])
					lis[i] = lis[j]+build[i].w;
		for(int i=1;i<n;++i)
			for(int j=0;j<i;++j)
				if(build[i].h < build[j].h && lds[j]+build[i].w > lds[i])
					lds[i] = lds[j]+build[i].w;
		
		//for(int i=0;i<n;++i)
			//printf("%d %d\n",lis[i],lds[i]);
		int mds, mis;
		mds = mis = 0;
		for(int i=0;i<n;++i) {
			if(mds < lds[i])	mds = lds[i];
			if(mis < lis[i])	mis = lis[i];
		}
		
		printf("Case %d.",++cases);
		if(mis >= mds)	printf(" Increasing (%d). Decreasing (%d).\n",mis,mds);
		else			printf(" Decreasing (%d). Increasing (%d).\n",mds,mis);
	}
	
	return 0;
}

