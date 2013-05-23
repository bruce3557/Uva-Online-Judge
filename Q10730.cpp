#include<stdio.h>
int n,set[10001];
int go(){
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<(i+n+1)/2;j++)
            if(set[i]<set[j] && set[j]<set[2*j-i])
                return 0;
    return 1;
}
main(){
    char c;
    int i,a;
    while(scanf("%d%c",&n,&c) && n){
        for(i=0;i<n;i++){
            scanf("%d",&a);
            set[a]=i;
        }
        if(go())    puts("yes");
        else        puts("no");
    }
}
