#include<stdio.h>
int n,map[26][26],ans;
int go(int now,int sum){
    int i,cnt;
    for(i=cnt=0;i<n;i++)
        if(map[now][i]){
            map[now][i]=map[i][now]=0;
            go(i,sum+1),cnt=1;
            map[now][i]=map[i][now]=1;
        }
    if(cnt==0)
        ans>?=sum;
}
main(){
    int i,j,m;
    while(scanf("%d %d",&n,&m) && n+m){
        for(i=ans=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=0;
        while(m--){
            scanf("%d %d",&i,&j);
            map[i][j]=map[j][i]=1;
        }
        for(i=0;i<n;i++)
            go(i,0);
        printf("%d\n",ans);
    }
}
