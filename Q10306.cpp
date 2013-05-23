#include <stdio.h>
#include <string.h>
#include <math.h>

struct node {
    int con,info,cnt;
} coin[50],q[500000];

char used[500][500];

int n,m;

int main() {
    int t;
    int i,j,x,y,tmp;
    int head,tail;
    
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d%d",&coin[i].con,&coin[i].info);
        memset(used,0,sizeof(used));
        head = tail = 0;
        for(i=0;i<n;i++) {
            q[tail] = coin[i];
            q[tail].cnt = 1;
            used[coin[i].con][coin[i].info] = 1;
            tail++;
        }
        while(head < tail) {
            x = q[head].con;
            y = q[head].info;
            tmp = x*x+y*y;
            if(tmp == m*m)    break;
            for(i=0;i<n;i++)
                if(x+coin[i].con <= m && y+coin[i].info <= m && used[x+coin[i].con][y+coin[i].info] == 0) {
                    used[x+coin[i].con][y+coin[i].info] = 1;
                    q[tail++] = (node){x+coin[i].con,y+coin[i].info,q[head].cnt+1};
                }
            head++;
        }
        if(head >= tail)
            puts("not possible");
        else
            printf("%d\n",q[head].cnt);
    }

    return 0;    
}
