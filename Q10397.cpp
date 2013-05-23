#include<stdio.h>
#include<math.h>
double map[751][751],dis[751],min,sum;
int past[751],x[751],y[751];
main(){
   int n,i,j,ptr,m;
   while(scanf("%d",&n)!=EOF){
       for(i=0;i<n;i++)
           scanf("%d %d",&x[i],&y[i]);
       for(i=0;i<n;i++)
           for(j=0;j<n;j++){
               if(i==j)    map[i][j]=99999999;
               else        map[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
           }
       scanf("%d",&m);
       while(m--){
           scanf("%d %d",&i,&j);
           map[i-1][j-1]=map[j-1][i-1]=0;
       }
       for(i=0;i<n;i++){
           dis[i]=map[0][i];
           past[i]=0;
       }
       for(i=1,sum=0;i<n;i++){
           min=99999999;
           for(j=0;j<n;j++)
               if(dis[j]<min){
                   min=dis[j];
                   ptr=j;
               }
           sum+=min;
           dis[ptr]=99999999;
           for(j=0;j<n;j++)
               if(j!=ptr && map[ptr][j]<dis[j] && dis[j]!=99999999){
                   dis[j]=map[ptr][j];
                   past[j]=ptr;
               }
       }
       printf("%.2lf\n",sum);
   }
}
