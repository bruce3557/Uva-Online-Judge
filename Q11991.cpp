#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;
vector<int> S[1000010];

int main() {
    int n,m;

    while( scanf("%d%d",&n,&m) != EOF ) {
        for(int i=1;i<=1000000;++i)
            S[i].clear();
        for(int i=1;i<=n;++i) {
            int a;
            scanf("%d",&a);
            S[a].push_back(i);
        }

        while(m--) {
            int a,b;
            scanf("%d%d", &a, &b);
            if(a > S[b].size()) {
                puts("0");
            } else {
                printf("%d\n", S[b][a-1]);
            }
        }
            

    }
    
    return 0;
}

