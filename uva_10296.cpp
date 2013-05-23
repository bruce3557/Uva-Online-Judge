/*
 *  uva_10296.cpp
 *  
 *
 *  Created by Bruce Kuo on 2012/3/11.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include<stdio.h>
int n,m,map[16][16],sum,deg[16],used[16],cnt,min;
void go(int st,int now){
	if(now >= min)	return;
    if(st==n){
        if(min > now)	min = now;
        return;
    }
    if(deg[st]%2==0){
        go(st+1,now);
        return;
    }
    int i;
    for(i=st+1;i<=n;i++)
        if(deg[i]%2){
            deg[i]++;
            deg[st]++;
            go(st+1,now+map[st][i]);
            deg[i]--;
            deg[st]--;
        }
}
main(){
    int i,j,k;
    while(scanf("%d",&n) && n){
        scanf("%d",&m);
        sum=cnt=0;
        for(i=1;i<=n;i++){
            deg[i]=used[i]=0;
            for(j=1;j<=n;j++)
                map[i][j]=99999999;
        }
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            if(map[i][j] > k)	map[i][j] = k;
            if(map[j][i] > k)	map[j][i] = k;
            deg[i]++;
            deg[j]++;
            sum+=k;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
					if(map[i][j] > map[i][k]+map[k][j])
						map[i][j] = map[i][k]+map[k][j];
        min=99999999;
        go(1,0);
        printf("%d\n",sum+min);
    }
}
