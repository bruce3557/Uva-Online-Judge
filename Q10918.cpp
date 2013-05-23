#include<stdio.h>
main(){
    int i,s[31]={0};
    s[0]=1,s[2]=3;
    for(i=4;i<31;i+=2)
        s[i]=4*s[i-2]-s[i-4];
    while(scanf("%d",&i) && i!=-1)
        printf("%d\n",s[i]);
}
