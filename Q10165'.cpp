#include<stdio.h>
main(){
    int n,now,tmp,i;
    while(scanf("%d",&n) && n){
        for(i=now=0;i<n;i++){
            scanf("%d",&tmp);
            now^=tmp;
        }
        if(now) puts("Yes");
        else    puts("No");
    }
}
