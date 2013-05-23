#include<stdio.h>
struct node{
    int a,b,len;
}e[2010];

int dis[1010],n,m;

bool Bellman_Ford(){
    int i,j;
    for(i=0;i<n;i++)
        dis[i]=99999999;
    dis[0]=0;
    for(i=0;i<n-1;i++)
        for(j=0;j<m;j++)
            if(dis[e[j].a]!=99999999 && dis[e[j].a]+e[j].len<dis[e[j].b])
                dis[e[j].b]=dis[e[j].a]+e[j].len;
    for(i=0;i<m && dis[e[i].a]+e[i].len>=dis[e[i].b];i++);
    return i>=m?0:1;        
}

main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].len);
        if(Bellman_Ford())  puts("possible");
        else                puts("not possible");
    }
}
