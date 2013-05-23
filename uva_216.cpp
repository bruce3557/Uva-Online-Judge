#include<stdio.h>
#include<string.h>
#include<math.h>
int n,ans[9],tmp[9],used[9];
double min;
struct node{
    double x,y;
}s[9];
void go(int now,int num,double sum){
    int i;
    if(num>=n){
        if(min>sum){
            for(i=0;i<num;i++)
                ans[i]=tmp[i];
            min=sum;
        }
        return ;
    }
    for(i=0;i<n;i++)
        if(used[i]==0){
            used[i]=1;
            tmp[num]=i;
            go(i,num+1,sum+sqrt(pow(s[now].x-s[i].x,2)+pow(s[now].y-s[i].y,2)));
            used[i]=0;
        }
}
main(){
    int i,j,c=0;
    while(scanf("%d",&n) && n){
        for(i=0;i<n;i++)
            scanf("%lf %lf",&s[i].x,&s[i].y);
        memset(used,0,sizeof(used));
        for(i=0,min=99999999;i<n;i++){
            used[i]=1;
            tmp[0]=i;
            go(i,1,0);
            used[i]=0;
        }
        puts("**********************************************************");
        printf("Network #%d\n",++c);
        for(i=1;i<n;i++)
            printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",s[ans[i-1]].x,s[ans[i-1]].y,s[ans[i]].x,s[ans[i]].y,sqrt(pow(s[ans[i]].x-s[ans[i-1]].x,2)+pow(s[ans[i]].y-s[ans[i-1]].y,2))+16);
        printf("Number of feet of cable required is %.2lf.\n",min+16*(n-1));
    }
}
