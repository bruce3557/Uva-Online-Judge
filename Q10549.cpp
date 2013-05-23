#include<stdio.h>
#include<stdlib.h>
int used[201],ans1[201],ans2[201],n,cnt;
struct node{
   int h,d,w;
}s[201];
int cmp(const void *a,const void *b){
   return (*(node *)b).h-(*(node *)a).h;
}
void dfs(int now,int p1,int p2){
   if(cnt==1)  return;
   if(now==2*n && p1==n && p2==n){
       cnt=1;
       return;
   }
   else if(now>=2*n || p1>n || p2>n)   return;
   if(used[now]==0){
       if(p1<n){
           if(p1==0){
               ans1[p1]=now;
               used[now]=1;
               dfs(now+1,p1+1,p2);
               used[now]=0;
           }
           else{
               if(s[now].h<=s[ans1[p1-1]].h-2*s[ans1[p1-1]].w && s[now].d<=s[ans1[p1-1]].d-2*s[ans1[p1-1]].w){
                   ans1[p1]=now;
                   used[now]=1;
                   dfs(now+1,p1+1,p2);
                   used[now]=0;
               }
           }
       }
       if(cnt==1)  return;
       if(p2<n){
           if(p2==0){
               used[now]=1;
               ans2[p2]=now;
               dfs(now+1,p1,p2+1);
               used[now]=0;
           }
           else{
               if(s[now].h<=s[ans2[p2-1]].h-2*s[ans2[p2-1]].w && s[now].d<=s[ans2[p2-1]].d-2*s[ans2[p2-1]].w){
                   ans2[p2]=now;
                   used[now]=1;
                   dfs(now+1,p1,p2+1);
                   used[now]=0;
               }
           }
       }
   }
}
main(){
   int c=0,i;
   while(scanf("%d",&n) && n){
       for(i=0;i<2*n;i++)
           scanf("%d %d %d",&s[i].h,&s[i].d,&s[i].w);
       for(i=cnt=0;i<201;i++)
           used[i]=ans1[i]=ans2[i]=0;
       if(c)   puts("");
       else    c=1;
       qsort(s,2*n,sizeof(node),cmp);
       dfs(0,0,0);
       for(i=0;i<n;i++)
           printf("%d %d %d\n",s[ans1[i]].h,s[ans1[i]].d,s[ans1[i]].w);
       puts("-");
       for(i=0;i<n;i++)
           printf("%d %d %d\n",s[ans2[i]].h,s[ans2[i]].d,s[ans2[i]].w);
   }
}