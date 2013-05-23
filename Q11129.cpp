#include<stdio.h>
int s[10001],tmp[10001];
void go(int st,int ed){
    if(st>=ed)  return;
    int k=st+(ed-st)/2,i;
    for(i=1;i+st<=ed;i+=2){
        tmp[k+i/2+1]=s[i+st];
        if(i+st+1<=ed)
            tmp[st+i/2]=s[i+st+1];
    }
    tmp[k]=s[st];
    for(i=st;i<=ed;i++) s[i]=tmp[i];
    go(st,k-1);
    go(k+1,ed);
}
main(){
    int i,n;
    while(scanf("%d",&n) && n){
        for(i=0;i<n;i++)    s[i]=i;
        go(0,n-1);
        printf("%d:",n);
        for(i=0;i<n;i++)    printf(" %d",s[i]);
        puts("");
    }
}
