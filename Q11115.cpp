#include<stdio.h>
int s[100],n,m;
main(){
    int i,j,len;
    while(scanf("%d %d",&n,&m) && n+m){
        if(n==10){
            printf("1");
            for(i=0;i<m;i++)
                printf("0");
            puts("");
            continue;
        }
        for(i=0;i<50;i++)
            s[i]=0;
        s[0]=1;
        for(i=0;i<m;i++){
            for(j=0;j<30;j++)
                s[j]*=n;
            for(j=0;j<30;j++)
                if(s[j]>=10){
                    s[j+1]+=s[j]/10;
                    s[j]%=10;
                }
        }
        for(i=30;s[i]==0 && i>0;i--);
        for(;i>=0;i--)
            printf("%d",s[i]);
        puts("");
    }
}
