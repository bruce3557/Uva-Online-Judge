#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

const int MAXN=5010;

int RA[MAXN], SA[MAXN], LCP[MAXN], RANK[MAXN], *FC, *SC, step;
char S[MAXN], Q[MAXN];

bool cmp(int a, int b) {
    if(step == -1 || FC[a] != FC[b])    return (FC[a] < FC[b]);
    return (FC[a+(1<<step)] < FC[b+(1<<step)]);
}

void suffix_array(char *S, int n) {
    for(int i=0;i<n;++i)
        RA[i] = S[SA[i] = i];
    for(FC=RA, SC=LCP, step=-1;(1<<step)<n;++step) {
        std::sort(SA, SA+n, cmp);
        int cnt = 0;
        for(int i=0;i<n;++i) {
            if(i > 0 && cmp(SA[i-1], SA[i]))    ++cnt;
            SC[SA[i]] = cnt;
        }
        if(cnt == n-1)  break;
        std::swap(FC, SC);
    }
    for(int i=0;i<n;++i)
        RA[SA[i]] = i;
}

void calc_lcp(int n) {
    for(int i=0;i<=n;++i)
        RANK[SA[i]] = i;
    for(int i=0, lcp=0;i<=n;++i) {
        if(RANK[i] == 0)
            LCP[0] = 0;
        else {
            int j = SA[RANK[i]-1];
            if(lcp > 0) --lcp;
            while(S[i+lcp] == S[j+lcp]) ++lcp;
            LCP[RANK[i]] = lcp;
        }
    }
}


int main() {
    int t;

    scanf("%d",&t);
    while(t--) {
        scanf("%s", S);
        int n = strlen(S);
        suffix_array(S, n+1);
        calc_lcp(n);

        int maxi = 0;
        for(int i=1;i<=n;++i)
            if(LCP[i] > maxi)
                maxi = LCP[i];
        printf("%d\n", maxi);
    }

    return 0;
}

