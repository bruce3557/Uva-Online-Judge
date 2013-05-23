#include<stdio.h>

int map[101][101],n,m,i,j,k,l,max;
int main(){
    while(scanf("%d %d",&n,&m)&& n+m){
		max = 0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
                map[i][j]+=map[i-1][j]+map[i][j-1]-map[i-1][j-1];
            }
		
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                for(k=0;k<i;k++)
                    for(l=0;l<j;l++)
                        if( map[i][j]+map[k][l]-map[k][j]-map[i][l]==0 ) {
							int x = (i-k)*(j-l);
                            max = (max > x) ? max : x;
						}
        printf("%d\n",max);
    }
	
	return 0;
}
