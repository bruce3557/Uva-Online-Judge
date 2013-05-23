#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m;
struct node {
    int num, id;

    bool operator < (const node &t) const {
        return (num > t.num);
    }

    void get(int _id) {
        id = _id;
        scanf("%d", &num);
    }
} S[1010];

int main() {
    int t;

    scanf("%d",&t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
            S[i].get(i);
        std::sort(S, S+n);
        bool suc = true;
        for(int i=0;suc && i<n;++i) {
            std::sort(S+i, S+n);
            for(int j=i+1;suc && j<n && S[i].num > 0;++j) {
                --S[j].num;
                --S[i].num;
                if(S[j].num < 0)    suc = false;
            }
        }
        
        if(suc) puts("Yes");
        else    puts("No");
    }

    return 0;
}

