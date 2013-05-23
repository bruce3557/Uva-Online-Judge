#include<stdio.h>
char name[23][100];
int map[23][23];
main(){
    int c=0,i,j,k,n,m,minp,min,sum;
    while(scanf("%d %d",&n,&m) && n+m){
        for(i=1;i<=n;i++)
            scanf("%s",name[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=10000;
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            map[i][j]=map[j][i]=k;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    map[i][j]<?=map[i][k]+map[k][j];
        for(i=1,minp=0,min=500000;i<=n;i++){
            for(j=1,sum=0;j<=n;j++)
                if(i!=j)
                    sum+=map[i][j];
            if(min>sum)
                min=sum,minp=i;
        }
        printf("Case #%d : %s\n",++c,name[minp]);
    }
}
