#include<stdio.h>
#include<string.h>
int s[210][210],pre[210],q[210],n,m,st,ed;
int flow(){
    int i,j,k,ans=0,min;
    while(1){
        for(i=st;i<=ed;i++)
            pre[i]=-1;
        q[0]=st,i=0,j=1;
        while(i<j){
            if(q[i]==ed)    break;
            for(k=st;k<=ed;k++)
                if(pre[k]==-1 && s[q[i]][k]){
                    pre[k]=q[i];
                    q[j++]=k;
                }
            i++;
        }
        if(i>=j)    return ans;
        min=2147483647;
        for(k=ed;k!=st;k=pre[k])
            min<?=s[pre[k]][k];
        ans+=min;
        for(k=ed;k!=st;k=pre[k]){
            s[pre[k]][k]-=min;
            s[k][pre[k]]+=min;
        }
    }
}
main(){
    int i,j,k;
    while(scanf("%d",&n)!=EOF){
        memset(s,0,sizeof(s));
        for(i=1;i<=n;i++)
            scanf("%d",&s[i][i+n]);
        scanf("%d",&m);
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            s[i+n][j]=k;
        }
        st=0,ed=2*n+1;
        scanf("%d %d",&i,&j);
        while(i--)
            scanf("%d",&k),s[st][k]=2147483647;
        while(j--)
            scanf("%d",&k),s[n+k][ed]=2147483647;
        printf("%d\n",flow());
    }
}
