#include<stdio.h>
struct node{
   int x,y,z;
}s[100001];
main(){
   int i,t,n,max,min,c=0,ans;
   scanf("%d",&t);
   while(t--){
       scanf("%d",&n);
       for(i=max=ans=0;i<n;i++)
           scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].z);
       min=2147483466;
       for(i=0;i<n;i++){
           max>?=s[i].x+s[i].y+s[i].z;
           min<?=s[i].x+s[i].y+s[i].z;
       }
       ans>?=max-min,max=0,min=2147483466;
       for(i=0;i<n;i++){
           max>?=s[i].x+s[i].y-s[i].z;
           min<?=s[i].x+s[i].y-s[i].z;
       }
       ans>?=max-min,max=0,min=2147483466;
       for(i=0;i<n;i++){
           max>?=s[i].x-s[i].y-s[i].z;
           min<?=s[i].x-s[i].y-s[i].z;
       }
       ans>?=max-min,max=0,min=2147483466;
       for(i=0;i<n;i++){
           max>?=s[i].x-s[i].y+s[i].z;
           min<?=s[i].x-s[i].y+s[i].z;
       }
       printf("Case #%d: %d\n",++c,ans>?(max-min));
   }
}
