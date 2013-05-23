#include<stdio.h>
#include<math.h>
struct node{
    double x,y;
}s[101];
double map[101][101],dis[101],sum,min,k,l;
int n,t,ptr;
main(){
    int i,j,flag=0;
    scanf("%d",&t);
    while(t--){
        if(flag)    puts("");
        else        flag=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf %lf",&s[i].x,&s[i].y);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(i==j)    map[i][j]=2147483647;
                else{
                    k=s[i].x-s[j].x,l=s[i].y-s[j].y;
                    map[i][j]=sqrt(k*k+l*l);
                }
            }
        for(i=sum=0;i<n;i++)
            dis[i]=map[0][i];
        dis[0]=2147483647;
        for(i=1;i<n;i++){
            min=2147483647;
            for(j=0;j<n;j++)
                if(dis[j]<min){
                    ptr=j;
                    min=dis[j];
                }
            sum+=min,dis[ptr]=2147483647;
            for(j=0;j<n;j++)
                if(dis[j]!=2147483647 && map[ptr][j]<dis[j] && j!=ptr)
                    dis[j]=map[ptr][j];
        }
        printf("%.2lf\n",sum);
    }
}
