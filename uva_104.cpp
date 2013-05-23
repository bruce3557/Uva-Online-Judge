#include<stdio.h>
double map[21][21][21];
int path[21][21][21],print[21];
main(){
   int i,j,k,n,q,a,b;
   while(scanf("%d",&n)!=EOF){
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
               if(i==j)    map[0][i][j]=1;
               else        scanf("%lf",&map[0][i][j]);
       for(i=1;i<n;i++){
           for(j=0;j<n;j++)
               for(k=0;k<n;k++){
                   map[i][j][k]=map[i-1][j][k];
                   path[i][j][k]=-1;
                   for(q=0;q<n;q++)
                       if(map[i][j][k]<map[i-1][j][q]*map[0][q][k]){
                           map[i][j][k]=map[i-1][j][q]*map[0][q][k];
                           path[i][j][k]=q;
                       }
               }
           for(j=0;j<n;j++)
               if(map[i][j][j]>1.01){
                   for(k=i,a=b=j;k>0;k--){
                       print[k]=path[k][a][b];
                       b=print[k];
                   }
                   printf("%d",j+1);
                   for(k=1;k<=i;k++)
                       printf(" %d",print[k]+1);
                   printf(" %d\n",j+1);
                   break;
               }
           if(j<n) break;
       }
       if(i>=n)    puts("no arbitrage sequence exists");
   }
}
