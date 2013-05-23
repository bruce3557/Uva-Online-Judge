#include <stdio.h>
#include <string.h>

int n, m;
int A[2001010];

int main() {
    
    while( scanf("%d%d",&n, &m) && (n+m) ) {
        memset(A, 0, sizeof(A));
        while(n--) {
            int a, b;
            scanf("%d%d",&a,&b);
            ++a;
            ++A[a];
            --A[b+1];
        }
        while(m--) {
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            ++a;
            for(int i=0;i<=1000000;i+=c) {
                ++A[i+a];
                --A[i+b+1];
            }
        }
        for(int i=1;i<=1000000;++i)
            A[i] += A[i-1];

        bool suc = true;
        for(int i=0;suc && i<=1000000;++i)
            if(A[i] > 1)
                suc = false;
        if(suc) puts("NO CONFLICT");
        else    puts("CONFLICT");
    }

    return 0;
}

