#include <stdio.h>
#include <string.h>

int n,m,dis[50];
int map[50][50][200],num[50][50];
char used[50];

int main() {

    int t,i,j,k,tt,a;
    int min,minptr,tmp;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        memset(used,0,sizeof(used));
        memset(num,0,sizeof(num));
        while(m--) {
            scanf("%d%d%d",&i,&j,&k);
            num[i][j] += k;
            for(tt=num[j][i];tt<num[i][j];tt++) {
                scanf("%d",&a);
                map[i][j][tt] = map[j][i][tt] = a;
            }
            num[j][i] += k;
        }
        for(i=1;i<=n;i++)
            dis[i] = 999999999;

        dis[1] = 0;
        for(i=0;i<n-1;i++) {
            min = 999999999;
            for(j=1;j<=n;j++)
                if(used[j]==0 && min > dis[j]) {
                    min = dis[j];
                    minptr = j;
                }
            used[minptr] = 1;
            tmp = dis[minptr];
            for(j=1;j<=n;j++) {
                if(used[j] == 0) {
                    min = 999999999;
                    for(k=0;k < num[minptr][j];k++) {
                        tt = map[minptr][j][k];
                        if(tt < (tmp%100))    tt = ((tmp+99)/100)*100+tt;
                        else                  tt = (tmp/100)*100+tt;
                        if(min > tt)    min = tt;
                    }
                    if(min < dis[j])
                        dis[j] = min;
                }
            }
        }

        for(i=1;i<=n;i++)
            if(dis[i] == 999999999)
                break;


        if(i <= n)   puts("-1");
        else {
            int max = -1;
            for(i=1;i<=n;i++)
                if(max < dis[i])
                    max = dis[i];
            printf("%d\n",max);
        }

    }

    return 0;
}
