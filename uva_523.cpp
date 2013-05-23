#include<stdio.h>
int map[150][150],path[150][150],cost[150],n;
void go(int i,int j){
    if(i==j)    return;
    if(path[i][j]){
        go(i,path[i][j]);
        go(path[i][j],j);
    }
    else    printf("-->%d",j);
}
main(){
    int t,i,j,k,cnt,len;
    char *c,s[5001];
    scanf("%d",&t);
    while(t--){
        scanf(" "),fgets(s,5001,stdin);
        for(i=1;i<=150;i++)
            for(j=1;j<=150;j++)
                map[i][j]=path[i][j]=0;
        for(n=1,c=s;sscanf(c,"%d%n",&map[1][n],&len)==1;n++,c+=len)
            if(map[1][n]<0)
                map[1][n]=99999999;
        for(n--,i=2;i<=n;i++)
            for(j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]<0)
                    map[i][j]=99999999;
            }
        for(i=1;i<=n;i++){
            scanf("%d",&cost[i]);
            for(j=1;j<=n;j++)
                if(map[j][i]!=99999999)
                    map[j][i]+=cost[i];
        }
        scanf(" ");
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(map[i][j]>map[i][k]+map[k][j]){
                        map[i][j]=map[i][k]+map[k][j];
                        path[i][j]=k;
                    }
        cnt=0;
        while(fgets(s,1000,stdin)!=NULL && *s!='\n'){
            if(cnt) puts("");
            else    cnt=1;
            sscanf(s,"%d %d",&i,&j);
            printf("From %d to %d :\nPath: %d",i,j,i);
            go(i,j);
            printf("\nTotal cost : %d\n",map[i][j]-cost[j]);
        }
        if(t)   puts("\n");
    }
}
