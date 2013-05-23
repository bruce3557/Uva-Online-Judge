#include<algorithm>
char s[100001],t[1001];
int n,m,c,f[1001];
void calc(){
    int i,j;
    f[1]=0;
    for(i=2;t[i];i++){
        j=f[i-1];
        if(t[i]==t[j+1])
            f[i]=j+1;
        else
            f[i]=0;
    }
}
main(){
    int i,j,tc;
    scanf("%d%*c",&tc);
    while(tc--){
        gets(s+1);
        scanf("%d%*c",&c);
        while(c--){
            gets(t+1);
            calc();
            for(i=j=1;s[i] && t[j];){
                if(s[i]==t[j])
                    i++,j++;
                else if(j==1)
                    i++;
                else
                    j=f[j-1]+1;
            }
            if(t[j]==0) puts("y");
            else        puts("n");
        }
    }
}
