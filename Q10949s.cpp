#include<stdio.h>
int n,m,len[2],d[200][1500],lis[20001];
char s[21][21],t[20001],tmp;
main(){
    int x,y,tc,c=0,i,j,max,l;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d%*c",&n,&m);
        for(i=1;i<=n;i++)
            gets(s[i]+1);
        for(i=0;i<200;i++)
            d[i][0]=0;
        scanf("%d %d %d%*c",&len[0],&x,&y);
        gets(t);
        d[s[x][y]][0]=d[s[x][y]][1]=1;
        for(i=max=0;i<len[0];i++){
            if(t[i]=='N')        x--;
            else if(t[i]=='S')   x++;
            else if(t[i]=='E')   y++;
            else                y--;
            tmp=s[x][y];
            d[tmp][++d[tmp][0]]=i+2;
        }
        scanf("%d %d %d%*c",&len[1],&x,&y);
        gets(t);
        if(d[s[x][y]][0])
            lis[1]=d[s[x][y]][1],max=1;
        for(i=0;i<len[1];i++){
            if(t[i]=='N')        x--;
            else if(t[i]=='S')   x++;
            else if(t[i]=='E')   y++;
            else                y--;
            tmp=s[x][y],l=d[tmp][0];
            if(d[tmp][0]){
                for(j=max;j>0;j--)
                    if(d[tmp][l]>lis[j]){
                        if(j==max)  max++;
                        j++;
                        lis[j]=d[tmp][l];
                        l--;
                        if(l==0)    break;
                    }
                if(max==0)  max=1;
                if(j==0)    lis[1]=d[tmp][1];
            }
        }
        printf("Case %d: %d %d\n",++c,len[0]-max+1,len[1]-max+1);
    }
}
