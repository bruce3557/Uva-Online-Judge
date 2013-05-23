#include<stdio.h>
int dp[5][8][8][8][8][8][5][8],color[4];
int go(int firc,int firs,int c1,int c2,int c3,int c4,int prec,int pres){
    if(c1==0 && c2==0 && c3==0 && c4==0)
        return (firc==prec || firs==pres)?0:1;
    if(dp[firc][firs][c1][c2][c3][c4][prec][pres]!=-1)
        return dp[firc][firs][c1][c2][c3][c4][prec][pres];
    int num[4]={c1,c2,c3,c4},tmp=0,i,j,fc,fs;
    for(i=0;i<4;i++){
        if(num[i]==0 || i==prec)    continue;
        for(j=1;j<=num[i] && j!=4;j++){
            if(j==pres) continue;
            if(firc==4) fc=i,fs=j;
            else    fc=firc,fs=firs;
            num[i]-=j;
            tmp+=go(fc,fs,num[0],num[1],num[2],num[3],i,j);
            num[i]+=j;
        }
    }
    dp[firc][firs][c1][c2][c3][c4][prec][pres]=tmp;
    return tmp;
}
main(){
    int t,i,cnt,ans,n;
    for(int c1=0;c1<5;c1++)
        for(int c2=0;c2<8;c2++)
            for(int c3=0;c3<8;c3++)
                for(int c4=0;c4<8;c4++)
                    for(int c5=0;c5<8;c5++)
                        for(int c6=0;c6<8;c6++)
                            for(int c7=0;c7<5;c7++)
                                for(int c8=0;c8<8;c8++)
                                    dp[c1][c2][c3][c4][c5][c6][c7][c8]=-1;
    for(scanf("%d",&t);t--;){
        for(i=0;i<4;i++)    color[i]=0;
        scanf("%d",&n);
        for(i=cnt=0;i<n;i++){
            scanf("%d",&color[i]);
            if(color[i]>0)    cnt++;
        }
        if(cnt==0)       puts("1");
        else if(cnt==1)  puts("0");
        else{
            ans=go(4,0,color[0],color[1],color[2],color[3],4,0);
            printf("%d\n",ans);
        }
    }
}
