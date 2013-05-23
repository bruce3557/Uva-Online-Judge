#include<cstdio>
int s[5][5],q[90],lim;
char c[]=" ULDR";
class map{
    public:
        int a,b;
}r[20];
int abs(int a){
    return a>?-a;
}
int cut(){
    int i,j,k=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(s[i][j]!=0)
                k+=abs(i-r[s[i][j]].a)+abs(j-r[s[i][j]].b);
    return k;
}
int dfs(int len,int now,int a,int b){
    int k;
    if(now==0){
        for(k=0;k<len;k++)
            printf("%c",c[q[k]]);
        puts("");
        return 1;
    }
    if(len+now>=lim)
        return 0;
    if((len==0 || q[len-1]!=3) && a>0){
        q[len]=1,s[a][b]=s[a-1][b],s[a-1][b]=0;
        if(dfs(len+1,now+abs(a-r[s[a][b]].a)-abs(a-r[s[a][b]].a-1),a-1,b)==1)
            return 1;
        s[a-1][b]=s[a][b],s[a][b]=0;
    }
    if((len==0 || q[len-1]!=4) && b>0){
        q[len]=2,s[a][b]=s[a][b-1],s[a][b-1]=0;
        if(dfs(len+1,now+abs(b-r[s[a][b]].b)-abs(b-r[s[a][b]].b-1),a,b-1)==1)
            return 1;
        s[a][b-1]=s[a][b],s[a][b]=0;
    }
    if((len==0 || q[len-1]!=1) && a<3){
        q[len]=3,s[a][b]=s[a+1][b],s[a+1][b]=0;
        if(dfs(len+1,now+abs(a-r[s[a][b]].a)-abs(a-r[s[a][b]].a+1),a+1,b)==1)
            return 1;
        s[a+1][b]=s[a][b],s[a][b]=0;
    }
    if((len==0 || q[len-1]!=2) && b<3){
        q[len]=4,s[a][b]=s[a][b+1],s[a][b+1]=0;
        if(dfs(len+1,now+abs(b-r[s[a][b]].b)-abs(b-r[s[a][b]].b+1),a,b+1)==1)
            return 1;
        s[a][b+1]=s[a][b],s[a][b]=0;
    }
    return 0;
}
main(){
    int t=1,i,j,k,a,b;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
           r[t++]=(map){i,j};
    for(scanf("%d",&t);t>0;t--){
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                scanf("%d",&s[i][j]);
        for(i=k=0;i<16;i++)
            if(s[i/4][i%4]==0)
                k+=i+4>>2,a=i/4,b=i%4;
            else for(j=0;j<i;j++)
                k+=s[i/4][i%4]<s[j/4][j%4]?1:0;
        printf("%d\n",k);
        if(k%2==0)
            for(lim=16;lim<50 && dfs(0,cut(),a,b)==0;lim+=4);
        else puts("This puzzle is not solvable.");
    }
}

