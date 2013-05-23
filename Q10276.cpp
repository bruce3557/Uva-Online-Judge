#include<stdio.h>
#include<math.h>
char check(int num){
    int tmp=sqrt(num);
    if(tmp*tmp==num)    return 1;
    return 0;
}
main(){
    int stack[51],n=0,i,j,ans[51],t;
    for(i=1;n<51;i++){
        for(j=0;j<n;j++)
            if(check(i+stack[j])){
                stack[j]=i;
                break;
            }
        if(j==n)    stack[n++]=i;
        ans[n]=i;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
}
