#include<stdio.h>

int map[101][101],n,m;

int main(){
    int t,i,j,k,max,st,ed,c=0;
	
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=99999999;
				
        while(m--){
            scanf("%d %d",&i,&j);
            map[i][j]=map[j][i]=1;
        }
		
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    map[i][j]<?=map[i][k]+map[k][j];
		
        max=0;
        scanf("%d %d",&st,&ed);
		
        for(i=0;i<n;i++)
            map[i][i]=0;
			
        for(i=0;i<n;i++)
            max>?=map[st][i]+map[i][ed];
		
        printf("Case %d: %d\n",++c,max);
    }
	
	return 0;
}

