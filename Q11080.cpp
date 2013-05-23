#include<stdio.h>
int v,map[201][201],vertice[201],ans;
int coloring(int i){
    int j;
    for(j=0;j<v;j++)
        if(map[i][j]==1 && vertice[j]==j)
            vertice[j]=i;
        else if(map[i][j]==1 && vertice[j]!=j)
            return 1;
    return 0;
}
main(){
    int t,i,j,e,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&v,&e);
        for(i=0;i<v;i++)
            for(j=0;j<v;j++)
                map[i][j]=0;
        for(i=0;i<v;i++)
            vertice[i]=i;
        while(e--){
            scanf("%d %d",&a,&b);
            map[a][b]=map[b][a]=1;
        }
        for(i=ans=0;i<v;i++)
            if(vertice[i]==i){
                ans++;
                if(coloring(i))
                    break;
            }
        if(i<v) puts("-1");
        else    printf("%d\n",ans);
    }
}
