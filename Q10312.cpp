#include<stdio.h>
long long cata[27],s[27];
main(){
    int n,i;
    cata[0]=cata[1]=s[1]=s[2]=1;
    for(i=2;i<27;i++)
        cata[i]=(4*i-2)*cata[i-1]/(i+1);
    for(i=3;i<27;i++)
        s[i]=(3*(2*i-3)*s[i-1]-(i-3)*s[i-2])/i;
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",s[n]-cata[n-1]);
}
