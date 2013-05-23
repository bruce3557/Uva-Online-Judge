#include<stdio.h>
int s[20001],lis[20001];
main(){
    int top,n,i,j,c=0;
    while(scanf("%d",&s[0]) && s[0]!=-1){
        for(i=1;scanf("%d",&s[i]) && s[i]!=-1;i++);
        lis[0]=2147483647,top=0,n=i;
        for(i=0;i<n;i++){
            if(s[i]<=lis[top])
                lis[++top]=s[i];
            else{
                for(j=top;j>=0;j--)
                    if(lis[j]>s[i]){
                        lis[j+1]=s[i];
                        break;
                    }
            }
        }
        if(c)   puts("");
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++c,top);
    }
}
