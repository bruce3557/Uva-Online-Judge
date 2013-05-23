#include<stdio.h>
#include<string.h>
int n;
char s[101][101],tmp[101][101],used[101];
void go(int st){
    if(used[st])    return;
    used[st]=1;
    for(int i=1;i<=n;i++)
        if(tmp[st][i] && used[i]==0)
            go(i);
}
main(){
    int i,j,k,sum,ans;
    char c;
    while(scanf("%d",&n) && n){
        memset(s,0,sizeof(s));
        while(scanf("%d",&i) && i){
            while(scanf("%d%c",&j,&c) && c!='\n')
                s[i][j]=s[j][i]=1;
            s[i][j]=s[j][i]=1;
        }
        ans=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                tmp[i][j]=s[i][j];
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                tmp[i][j]=tmp[j][i]=used[j]=0;
            sum=0;
            if(i==1)   go(2);
            else       go(1);
            for(j=1;j<=n;j++)
                if(used[j])
                    sum++;
            if(sum<n-1) ans++;
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    tmp[j][k]=s[j][k];
        }
        printf("%d\n",ans);
    }
}
