#include<stdio.h>
int n,sum;
char s[40];
void go(int now){
    int i,j;
    for(i=now/3;i>0;i--){
        for(j=1;j<=i;j++)
            if(s[now-j]!=s[now-i-j] || s[now-j]!=s[now-2*i-j] || s[now-i-j]!=s[now-2*i-j])
                break;
        if(j>i) return;
    }
    if(now>=n){
        sum++;
        return;
    }
    if(s[now]!='*') go(now+1);
    else{
        s[now]='0';
        go(now+1);
        s[now]='1';
        go(now+1);
        s[now]='*';
    }
}
main(){
    int i,j,c=0;
    while(scanf("%d",&n) && n){
        scanf("%s",s);
        sum=0;
        go(0);
        printf("Case %d: %d\n",++c,sum);
    }
}
