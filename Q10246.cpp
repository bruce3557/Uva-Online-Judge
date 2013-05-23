#include<algorithm>
int s[101][101],t[101][101],d[101][101],cost[101],n,m,q;
main(){
    int c=0,i,j,k,l;
    while(scanf("%d %d %d",&n,&m,&q) && n+m+q){
        
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                s[i][j]=t[i][j]=d[i][j]=999999999;
        
        for(i=1;i<=n;i++)
            scanf("%d",&cost[i]);
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            if(d[i][j]>k)
                d[i][j]=d[j][i]=k;
        }
        
        for(l=1;l<=n;l++){
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    s[i][j]=d[i][j];
            for(k=1;k<=n;k++)
                if(cost[k]<=cost[l])
                    for(i=1;i<=n;i++)
                        if(cost[i]<=cost[l])
                            for(j=1;j<=n;j++)
                                if(cost[j]<=cost[l])
                                    s[i][j]<?=s[i][k]+s[k][j];
            for(i=1;i<=n;i++)
                if(cost[i]<=cost[l])
                    for(j=1;j<=n;j++)
                        if(cost[j]<=cost[l])
                            t[i][j]<?=s[i][j]+cost[l];
        }
                
        if(c)   puts("");
        printf("Case #%d\n",++c);
        while(q--){
            scanf("%d %d",&i,&j);
            if(t[i][j]==999999999)
                puts("-1");
            else
                printf("%d\n",t[i][j]);
        }
        
    }
}
