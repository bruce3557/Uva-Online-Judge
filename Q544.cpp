#include<stdio.h>
#include<string.h>
int map[201][201];
char name[201][31];
main(){
    int n,m,i,j,k,now,w,c=0;
    char a[31],b[31],st[31],ed[31];
    while(scanf("%d %d",&n,&m) && n+m){
        for(i=now=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=0;
        while(m--){
            scanf("%s %s %d",a,b,&w);
            for(i=0;i<now;i++)
                if(strcmp(name[i],a)==0)
                    break;
            if(i==now)
                strcpy(name[now++],a);
            for(j=0;j<now;j++)
                if(strcmp(name[j],b)==0)
                    break;
            if(j==now)
                strcpy(name[now++],b);
            map[i][j]=map[j][i]=w;
        }
        scanf("%s %s",st,ed);
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    if(i!=j)
                        map[i][j]>?=(map[i][k]<?map[k][j]);
        for(i=0;i<n;i++)
            if(strcmp(name[i],st)==0)
                break;
        for(j=0;j<n;j++)
            if(strcmp(name[j],ed)==0)
                break;
        printf("Scenario #%d\n%d tons\n\n",++c,map[i][j]);
    }
}
