#include<stdio.h>
main(){
    int s[101]={0},n,i,j,k,ans;
    while(scanf("%d",&n)!=EOF){
        for(i=ans=0;n;n--){
            scanf("%d",&k);
            for(j=0;j<i;j++)
                if(s[j]>=k)
                    break;
            if(i==j)
                ans+=k;
            else
                s[j]-=k;
            s[i++]=k;
        }
        printf("%d\n",ans);
    }
}
