#include<stdio.h>
#include<string.h>
char c,s[5000];
main(){
    int t,i,j,cnt,min,n,ans[1001],len,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d ",&n);
        for(i=1,min=10000;i<=n;i++){
            len=0;
            gets(s);
            for(j=0;s[j]!=NULL;j++)
                if(s[j]==' ')
                    len++;
            if(len==min)    ans[cnt++]=i;
            else if(len<min){
                min=len;
                ans[0]=i;
                cnt=1;
            }
        }
        printf("%d",ans[0]);
        for(i=1;i<cnt;i++)  printf(" %d",ans[i]);
        puts("");
    }
}
