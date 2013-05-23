#include<stdio.h>
#include<string.h>
bool map[101][101];
int n;
main(){
    int i,j,k,m,cnt;
    while(scanf("%d",&n) && n){
        memset(map,0,sizeof(map));
        while(scanf("%d",&i) && i)
            while(scanf("%d",&j) && j)
                map[i][j]=1;
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    map[i][j] |= (map[i][k] && map[k][j]);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&j);
            for(k=1,cnt=0;k<=n;k++)
                if(map[j][k]==0)
                    cnt++;
            printf("%d",cnt);
            for(k=1;k<=n;k++)
                if(map[j][k]==0)
                    printf(" %d",k);
            puts("");
        }
    }
}
