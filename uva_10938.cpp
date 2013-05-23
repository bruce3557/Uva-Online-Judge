#include<stdio.h>
int n,map[15002],ans[5001],tmp[15002],N[15002],used[5001],count;
void dfs(int st,int ed){
    if(st==ed){
        int a,b;
        if(count%2==0){
            a=ans[count/2],b=ans[count/2+1];
            if(a>b) a^=b^=a^=b;
            printf("The fleas jump forever between %d and %d.\n",a,b);
        }
        else
            printf("The fleas meet at %d.\n",ans[count/2+1]);
        return;
    }
    int i;
    for(i=0;i<N[st];i++)
        if(used[map[map[st]-i]]==0){
            used[map[map[st]-i]]=1;
            ans[++count]=map[map[st]-i];
            dfs(map[map[st]-i],ed);
            used[map[map[st]-i]]=0;
            if(ans[count]==ed)
                return;
            count--;
        }
}
main(){
    int l,i,j,k,p,st,ed;
    while(scanf("%d",&n) && n!=0){
        for(i=0;i<15002;i++)
            map[i]=tmp[i]=N[i]=0;
        for(i=0;i<5001;i++)
            used[i]=0;
        map[0]=n,p=0;
        for(i=1;i<n;i++){
            scanf("%d %d",&k,&j);
            N[k]++,N[j]++;
            tmp[p++]=k,tmp[p++]=j;
        }
        for(i=1;i<=n;i++)
            map[i]=map[i-1]+N[i];
        for(i=0;i<p;i+=2){
            N[tmp[i]]--,map[map[tmp[i]]-N[tmp[i]]]=tmp[i+1];
            N[tmp[i+1]]--,map[map[tmp[i+1]]-N[tmp[i+1]]]=tmp[i];
        }
        for(i=1;i<=n;i++)
           N[i]=map[i]-map[i-1];
        scanf("%d",&l);
        for(i=0;i<l;i++){

            scanf("%d %d",&st,&ed);
            ans[1]=st,count=1;
            used[st]=1;
            dfs(st,ed);
            used[st]=0;
        }
    }
}