#include<stdio.h>
#include<string.h>
int map[1001],used[1001],ans,n;
main(){
    int t,i,j,a,b,count,g=0;
    char c,w[1000];
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n,&c);
        for(i=1,ans=count=0;i<=n;i++)
            map[i]=i;
        while(gets(w)!=NULL && w[0]!='\0'){
            if(sscanf(w,"%c %d %d",&c,&a,&b)<3)   break;
            if(c=='c'){
                for(j=a;map[j]!=j;j=map[j]);
                for(i=b;map[i]!=i;i=map[i]);
                map[i]=j;
            }
            else{
                for(i=a;map[i]!=i;i=map[i]);
                for(j=b;map[j]!=j;j=map[j]);
                if(i==j)    ans++;
                count++;
            }
        }
        if(g) puts("");
        else    g=1;
        printf("%d,%d\n",ans,count-ans);
    }
}
