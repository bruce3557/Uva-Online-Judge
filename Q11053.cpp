#include<stdio.h>
long long n,a,b;
long long f(long long x){
    long long t=x%n;
    return (((((a*t)%n)*t)%n)+b)%n;
}
main(){
    long long len1,len2,x1,x2;
    while(scanf("%lld",&n) && n){
        scanf("%lld %lld",&a,&b);
        a%=n,b%=n;
        for(len1=0,x1=f(0),x2=f(f(0));x1!=x2;x1=f(x1),x2=f(f(x2)),len1++);
        for(len2=len1+1,x1=f(x1),x2=f(f(x2));x1!=x2;x1=f(x1),x2=f(f(x2)),len2++);
        printf("%lld\n",n-(len2-len1));
    }
}
