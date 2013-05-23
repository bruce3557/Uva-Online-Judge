#include <stdio.h>
#include <string.h>

int n,m;
int S[2000010];

int main() {

    while(scanf("%d%d",&n,&m) && (n+m)) {
        memset(S, 0, sizeof(S));
        n+=m;
        for(int i=0;i<n;++i) {
            int a;
            scanf("%d",&a);
            S[a]++;
        }
        int count=0;
        for(int i=0;i<=2000000;++i)
            if(S[i] > 1)
                ++count;
        printf("%d\n", count);
    }

    return 0;
}

