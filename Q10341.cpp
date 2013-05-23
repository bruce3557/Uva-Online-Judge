#include<stdio.h>
#include<math.h>
int s[6],cnt;
double go(double x){
    return s[0]*exp(-x)+s[1]*sin(x)+s[2]*cos(x)+s[3]*tan(x)+s[4]*x*x+s[5];
}
main(){
    double st,ed,mid,c;
    
    while(scanf("%d%d%d%d%d%d",&s[0],&s[1],&s[2],&s[3],&s[4],&s[5])!=EOF){
        st=0.0,ed=1.0;
        if(go(st)*go(ed)>0)
            puts("No solution");
        else{
            cnt=0;
            while(cnt++<30){
                mid=(st+ed)/2.0;
                c=go(mid);
                if(c>0) st=mid;
                else    ed=mid;
            }
            printf("%.4lf\n",mid+10e-9);
        }
    }
}
