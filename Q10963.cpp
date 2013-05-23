#include<stdio.h>
main(){
   int t,i,j,a,b,cnt,c=0,gap,n;
   scanf("%d",&t);
   while(t--){
       scanf("%d",&n);
       scanf("%d %d",&a,&b);
       gap=a-b;
       for(i=1,cnt=0;i<n;i++){
           scanf("%d %d",&a,&b);
           if(gap!=a-b)
               cnt=1;
       }
       if(c)   puts("");
       else    c=1;
       if(cnt)
           puts("no");
       else
           puts("yes");
   }
}
