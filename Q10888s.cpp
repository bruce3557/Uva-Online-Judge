#include <stdio.h>
struct Node{
    int y;
    int x;
    int dis;
};
char map[50][50];
int s,t,m,n,nbox,nhouse;
int cap[100][100],cost[100][100],id[50][50],pre[1000],dis[1000];
int push(int k){
    if(k==s)
        return 0;
    cap[pre[k]][k]--;
    cap[k][pre[k]]++;
    cost[pre[k]][k]*=-1;
    cost[k][pre[k]]*=-1;
    return cost[pre[k]][k]*(-1)+push(pre[k]);
}
int MinCostFlow(){
    int i,j,k,flow=0;
    while(1){
        for(i=s;i<=t;i++)
            pre[i]=-1;
        pre[s]=-2,dis[s]=0;
        for(k=s;k<=t;k++)
            for(i=s;i<=t;i++)
                if(pre[i]!=-1){
                    for(j=s;j<=t;j++)
                        if(cap[i][j]>0 && (pre[j]==-1 || dis[i]+cost[i][j]<dis[j])){
                            pre[j]=i;
                            dis[j]=dis[i]+cost[i][j];
                        }
                }
        if(pre[t]==-1)
            return flow;
        flow+=push(t);
    }
    return flow;
}
void CalcCost(int y,int x){
    Node dq[2000];
    bool visit[50][50];
    int i,j,k,dir[4][2]={{+1,0},{-1,0},{0,+1},{0,-1}};
    dq[0]=(Node){y,x,0};
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            visit[i][j]=false;
    for(i=0,j=1;i<j;i++){
        if(map[dq[i].y][dq[i].x]=='X')
            cost[1+id[y][x]][1+nbox+id[dq[i].y][dq[i].x]]=
            cost[1+nbox+id[dq[i].y][dq[i].x]][1+id[y][x]]=dq[i].dis;
        for(k=0;k<4;k++)
            if(dq[i].y+dir[k][0]>=0 && dq[i].y+dir[k][0]<m &&
                dq[i].x+dir[k][1]>=0 && dq[i].x+dir[k][1]<n)
                if(map[dq[i].y+dir[k][0]][dq[i].x+dir[k][1]]!='#' &&
                    !visit[dq[i].y+dir[k][0]][dq[i].x+dir[k][1]]){
                    visit[dq[i].y+dir[k][0]][dq[i].x+dir[k][1]]=true;
                    dq[j++]=(Node){dq[i].y+dir[k][0],dq[i].x+dir[k][1],dq[i].dis+1};
                }
    }
}
main(){
    int T,i,j;
    for(scanf("%d",&T);T>0;T--){
        scanf("%d %d",&m,&n);
        nbox=nhouse=0;
        for(i=0;i<m;i++){
            scanf("%s",map[i]);
            for(j=0;j<n;j++)
                if(map[i][j]=='B')      id[i][j]=nbox++;
                else if(map[i][j]=='X') id[i][j]=nhouse++;
        }
        s=0, t=nbox+nhouse+1;
        for(i=s;i<=t;i++)
            for(j=s;j<=t;j++)
                cap[i][j]=0, cost[i][j]=999999999;
        for(i=1;i<=nbox;i++)
            for(j=nbox+1;j<=nbox+nhouse;j++)
                cap[i][j]=1;
        for(i=1;i<=nbox;i++)             cap[s][i]=1, cost[s][i]=cost[i][s]=0;
        for(i=nbox+1;i<=nbox+nhouse;i++) cap[i][t]=1, cost[i][t]=cost[t][i]=0;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(map[i][j]=='B')
                    CalcCost(i,j);
        printf("%d\n",MinCostFlow());
    }
}
