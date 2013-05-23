#include <stdio.h>
#include <string.h>
#define MAX 999999999

int n,m,dis[510];
int map[510][510];
char used[510];

double abs(double a) {
    if(a < 0)   return -a;
    return a;
}

int main() {
    int i,j,k,c=0;
    int min,minptr,ansptr1,ansptr2;
    double flag;
    double ans,tmp;

    while(scanf("%d%d",&n,&m) && n+m) {
        memset(used,0,sizeof(used));
        for(i=1;i<=n;i++)
            dis[i] = MAX;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j] = MAX;
        while(m--) {
            scanf("%d%d%d",&i,&j,&k);
            map[i][j] = map[j][i] = k;
        }
        dis[1] = 0;
        for(i=1;i<=n;i++) {
            min = MAX;
            for(j=1;j<=n;j++)
                if(used[j]==0 && dis[j] < min) {
                    min = dis[j];
                    minptr = j;
                }
            used[minptr] = 1;
            for(j=1;j<=n;j++)
                if(dis[j] > dis[minptr]+map[minptr][j])
                    dis[j] = dis[minptr]+map[minptr][j];
        }
        flag = 0;
        ans = -1;
        for(i=1;i<=n;i++)
            if(ans < dis[i]) {
                ans = dis[i];
                ansptr1 = i;
            }
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++)
                if(map[i][j] != MAX) {
                    min = dis[i] < dis[j] ? dis[i] : dis[j];
                    tmp = min+(map[i][j]-abs(dis[i]-dis[j]))/2+abs(dis[i]-dis[j]);
                    if(tmp > ans) {
                        ans = tmp;
                        ansptr1 = i;
                        ansptr2 = j;
                        flag = 1;
                    }
                }
        }
        if(flag == 0)
            printf("System #%d\nThe last domino falls after %.1lf seconds, at key domino %d.\n\n",++c,ans,ansptr1);
        else
            printf("System #%d\nThe last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",++c,ans,ansptr1,ansptr2);
    }

    return 0;
}
