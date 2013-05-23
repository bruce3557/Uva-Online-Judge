#include<stdio.h>
#include<math.h>
double L,u,v,t,tmp;
double abs(double x){
    return x>?-x;
}
double min(double a,double b){
    return a<?b;
}
main(){
    while(scanf("%lf",&L) && L){
        scanf("%lf %lf %lf",&u,&v,&t);
        tmp=abs(u-v)*t;
        printf("%.0lf\n",(min(u,v)-0.6)*t/L+(tmp+0.3)/L);
    }
}
