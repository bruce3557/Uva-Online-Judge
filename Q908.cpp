#include<stdio.h>
#include<algorithm>
struct node{
    int a,b,len;
}edge[1000001];
int s[1000001],n,m,k,ans;
bool cmp(node a,node b){
    return a.len<b.len;
}
main(){
    int i,j,l,flag=0,sum;
    while(scanf("%d",&n)!=EOF){
        if(flag)    puts("");
        else        flag=1;
        for(i=1,sum=ans=0;i<n;i++){
            scanf("%d %d %d",&j,&l,&k);
            sum+=k;
        }
        printf("%d\n",sum);
        for(i=1;i<=n;i++)
            s[i]=i;
        scanf("%d",&k);
        for(i=0;i<k;i++)
            scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].len);
        scanf("%d",&m);
        for(m+=k;i<m;i++)
            scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].len);
        std::sort(edge,edge+m,cmp);
        for(i=0;i<m;i++){
            for(j=edge[i].a;j!=s[j];j=s[j]);
            for(l=edge[i].b;l!=s[l];l=s[l]);
            if(j==l)    continue;
            s[j]=l,ans+=edge[i].len;
        }
        printf("%d\n",ans);
    }
}
