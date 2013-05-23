#include<stdio.h>
#include<string.h>
#include<algorithm>
long long d;
int n,ans;
char s[15],cnt[15],used[15];
void go(int now){
    int i;
    if(now>=n){
        long long sum=0,j=1;
        for(i=0;i<n;i++,j*=10)
            sum+=(cnt[i]-'0')*j;
        cntt++;
        if(sum%d==0)    ans++;
        return;
    }
    char tmp=' ';
    for(i=0;i<n;i++)
        if(s[i]!=tmp && used[i]==0){
            tmp=cnt[now]=s[i];
            used[i]=1;
            go(now+1);
            used[i]=0;
        }
}
main(){
    int m;
    scanf("%d",&m);
    while(m--){
        scanf("%s %I64d",s,&d);
        n=strlen(s);
        for(int i=0;i<n;i++)
            used[i]=0;
        std::sort(s,s+n);
        ans=cntt=0;
        go(0);
        printf("%d\n",ans);
    }
}
