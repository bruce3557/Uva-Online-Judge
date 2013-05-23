#include <stdio.h>
#include <string.h>
#define MAX (999999999)

int map[110][110];

int main() {
    int c=0;
    int i,j,k,n,sum;
    double ans;
    for(i=1;i<=100;i++)
        for(j=1;j<=100;j++)
            map[i][j] = MAX;
    while(scanf("%d%d",&i,&j) && i !=0 && j != 0) {
        map[i][j] = 1;
        while(scanf("%d%d",&i,&j) && i && j) {
            map[i][j] = 1;
        }
        n = 0;
        for(i=1;i<=100;i++) {
            for(j=1;j<=100;j++)
                if(map[i][j] != MAX)
                    break;
            if(j <= 100)    n++;
        }
        for(i=1;i<=100;i++)
            map[i][i] = 0;
        for(k=1;k<=100;k++)
            for(i=1;i<=100;i++)
                for(j=1;j<=100;j++)
                    if(map[i][j] > map[i][k]+map[k][j])
                        map[i][j] = map[i][k]+map[k][j];
        sum = 0;
        for(i=1;i<=100;i++)
            for(j=1;j<=100;j++)
                if(map[i][j] != MAX)
                    sum += map[i][j];
        ans = (double)sum/(n*(n-1));
        printf("Case %d: average length between pages = %.3lf clicks\n",++c,ans);
        for(i=1;i<=100;i++)
            for(j=1;j<=100;j++)
                map[i][j] = MAX;
    }

    return 0;    
}
