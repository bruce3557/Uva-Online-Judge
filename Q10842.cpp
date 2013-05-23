#include<stdio.h>
#include<stdlib.h>
struct node{
    int a,b,cap;
}edge[10001];
int cmp(const void *a,const void *b){
    return (*(node *)a).cap-(*(node *)b).cap;
}
int s[101];
main(){
    int n,m,i,j,k,t,ans,c=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            s[i]=i;
        for(i=ans=0;i<m;i++)
            scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].cap);
        qsort(edge,m,sizeof(node),cmp);
        for(i=m-1;i>=0;i--){
            for(j=edge[i].a;s[j]!=j;j=s[j]);
            for(k=edge[i].b;s[k]!=k;k=s[k]);
            if(j==k)    continue;
            ans=edge[i].cap;
            s[j]=k;
        }
        printf("Case #%d: %d\n",++c,ans);
    }
}
