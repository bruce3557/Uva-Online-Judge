#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m;
int num[100];
char map[200][200];
char used[200][200];

struct node {
    char x;
    int times;
    bool operator < (node t) const {
        return times > t.times || (times == t.times && x < t.x);
    }
}ans[100];

void go(int x,int y) {
    if(x-1 >= 0 && used[x-1][y] == 0 && map[x][y] == map[x-1][y]) {
        used[x-1][y] = 1;
        go(x-1,y);
    }
    if(y-1 >= 0 && used[x][y-1] == 0 && map[x][y] == map[x][y-1]) {
        used[x][y-1] = 1;
        go(x,y-1);
    }
    if(x+1 < n && used[x+1][y] == 0 && map[x][y] == map[x+1][y]) {
        used[x+1][y] = 1;
        go(x+1,y);
    }
    if(y+1 < m && used[x][y+1] == 0 && map[x][y] == map[x][y+1]) {
        used[x][y+1] = 1;
        go(x,y+1);
    }
}

int main() {

    int t,c=0;
    int i,j;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",map[i]);
        memset(num,0,sizeof(num));
        memset(used,0,sizeof(used));
        printf("World #%d\n",++c);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(used[i][j] == 0) {
                    used[i][j] = 1;
                    num[map[i][j]-'a']++;
                    go(i,j);
                }
        for(i=0;i<26;i++)
            ans[i] = (node){i+'a',num[i]};
        std::sort(ans,ans+26);
        for(i=0;ans[i].times > 0;i++)
            printf("%c: %d\n",ans[i].x,ans[i].times);
    }

    return 0;
}
