#include<stdio.h>
#include<string.h>
char s[110],t[110];
int n,m,lcs[110][110];
main(){
    int i,j,len,ans,tmp;
    while(scanf("%s %s",s+1,t+1) && s[1]!='0' && t[1]!='0'){
        n=strlen(s+1);
        m=strlen(t+1);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                if(s[i]==t[j])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                    lcs[i][j]=lcs[i-1][j]>?lcs[i][j-1];
            }
        len=lcs[n][m];
        printf("%d\n",len);
        if((n-len)*2<=n && (m-len)*2<=m)    puts("1");
        else{
            ans=0;
            while(n>len){
                n/=2;
                ans++;
            }
            while(m>len){
                m/=2;
                ans++;
            }
            printf("%d\n",ans);
        }
    }
}
