#include<algorithm>
int n,s[500001],t[500001];

main(){
    int i;
    while(scanf("%d",&n) && n){
        for(i=0;i<n;i++)
            scanf("%d %d",&s[i],&t[i]);
        std::sort(s,s+n);
        std::sort(t,t+n);
        for(i=0;i<n && s[i]==t[i];i++);
        if(i<n) puts("NO");
        else    puts("YES");
    }
}
