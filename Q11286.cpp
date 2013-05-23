#include <stdio.h>
#include <string.h>
#include <set>
#include <map>

using std::map;
using std::set;

int n;
set<int> S[10010];

int main() {
    
    while( scanf("%d",&n) && n ) {
        int maxi = 0;
        int answer = 0;
        map<set<int>, int> Q;
        for(int i=0;i<n;++i) {
            S[i].clear();
            int a;
            for(int j=0;j<5;++j) {
                scanf("%d", &a);
                S[i].insert(a);
            }
            Q[S[i]] = Q[S[i]] + 1;
            if(Q[S[i]] > maxi)
                maxi = Q[S[i]];
        }
        answer = 0;
        for(int i=0;i<n;++i)
            if( Q[S[i]] == maxi )
                ++answer;
        printf("%d\n", answer);
    }

    return 0;
}

