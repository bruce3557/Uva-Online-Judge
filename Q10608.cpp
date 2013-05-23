#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
    int a,b;
    bool operator < (node t) const {
        return a < t.a || (a == t.a && b < t.b);
    }
} edge[1000010];

bool used[30010];
int n,m,ans,Ttime;
int st[30010],startT[30010],endT[30010];

void go(int i) {
    int j;
    startT[i] = Ttime;
    Ttime++;
    for(j=st[i];j<st[i+1];j++)
        if(used[edge[j].b] == 0) {
            used[edge[j].b] = 1;
            go(edge[j].b);
        }
    endT[i] = Ttime;
}

void DFS() {
    Ttime = 0;
    memset(used,0,sizeof(bool)*(n+5));
    int i;
    for(i=1;i<=n;i++)
        if(used[i] == 0) {
            used[i] = 1;
            go(i);
            if(endT[i]-startT[i] > ans) ans = endT[i]-startT[i];
        }
}

int main() {
    int i,j;
    int t;
   
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        ans = 0;
        for(i=1;i<=n;i++)
            st[i] = -1;
        for(i=0;i<2*m;i+=2) {
            scanf("%d%d",&edge[i].a,&edge[i].b);
            edge[i+1] = (node){edge[i].b,edge[i].a};
        }
        m *= 2;
        std::sort(edge,edge+m);
        for(i=0;i<m;i++)
            if(st[edge[i].a] == -1)
                st[edge[i].a] = i;
        st[n+1] = m;
        for(i=n;i>=1;i--)
            if(st[i] == -1)
                st[i] = st[i+1];
        DFS();
        printf("%d\n",ans);
    }
    return 0;  
}