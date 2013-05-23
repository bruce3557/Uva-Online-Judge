#include<stdio.h>
int n,m,c,r,len[1002],dp[1001][101];
char map[1001][1001],used[1001][1001];
void fill(int i,int j,int filled){
   //if(map[i][j]=='.' || i>n || j>m || i<1 || j<1)  return;
   used[i][j]=filled;
   if(map[i][j-1]=='#' && used[i][j-1]==0)              fill(i,j-1,filled);
   if(map[i-1][j]=='#' && used[i-1][j]==0) fill(i-1,j,filled);
   if(map[i+1][j]=='#' && used[i+1][j]==0) fill(i+1,j,filled);
   if(map[i][j+1]=='#' && used[i][j+1]==0) fill(i,j+1,filled);
}
main(){
   int i,j,ptr1,ptr2;
   for(i=0;i<1001;i++) map[i][0]=map[0][i]='.';
   while(scanf("%d %d",&n,&m)!=EOF){
       scanf("%d %d",&c,&r);
       for(i=1,r++;i<=n;i++)
           for(j=1;j<=m;j++)
               used[i][j]=0;
       for(i=1;i<=n;i++)   scanf("%s",map[i]+1);
       fill(1,1,1);
       fill(n,m,2);
       for(i=1;i<=m;i++){
           for(ptr2=1;used[ptr2][i]!=2 && ptr2<=n;ptr2++);
           for(ptr1=n;used[ptr1][i]!=1 && ptr1>=1;ptr1--);
           len[i-1]=ptr2-ptr1-1;
       }
       dp[0][0]=len[0];
       for(i=1;i<m;i++)    dp[i][0]=dp[i-1][0]<?len[i];
       for(i=1;i<c;i++){
           dp[r*i][i]=dp[r*(i-1)][i-1]+len[r*i];
           for(j=r*i+1;j<m;j++)    dp[j][i]=dp[j-1][i]<?(dp[j-r][i-1]+len[j]);
       }
       printf("%d\n",dp[m-1][c-1]);
   }
}
