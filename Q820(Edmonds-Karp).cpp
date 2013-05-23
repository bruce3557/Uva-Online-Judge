/*Maximum Flow Problem
**Edmonds-Karp Algorithm
*/

 #include<stdio.h>
 #include <sys/timeb.h>

double elapse(struct timeb *before, struct timeb *after) {
  double t;
  t =   (after->time*1000 + after->millitm)
      - (before->time*1000 + before->millitm);
  t /= 1000;
  return t;
}

 int n,f[101][101],q[101],p[101];
 int min(int x,int y){ return x<y ? x:y; }
 int flow(int st,int ed){
     int sum=0,i,j,k,ptr,cap;
     while(1){
         q[1]=st;
         for(i=1;i<=n;i++)
             p[i]=-1;
         p[st]=0;
		 
		 //BFS
         for(i=1,j=2;i<j;i++){
             if(q[i]==ed) break;
             for(k=1;k<=n;k++)
                 if(p[k]==-1 && f[q[i]][k]>0){
                     p[k]=q[i];
                     q[j++]=k;
                 }
         }
		 
         if(q[i]!=ed || i>=j) break;
		 
         cap=f[p[ed]][ed];
         for(ptr=ed;p[ptr]!=0;ptr=p[ptr])
             cap=min(cap,f[p[ptr]][ptr]);
         sum+=cap;
         for(ptr=ed;p[ptr]!=0;ptr=p[ptr]){
             f[p[ptr]][ptr] -= cap;
             f[ptr][p[ptr]] += cap;
         }
     }
     return sum;
 }
 main(){
     int i,j,k,C=0,st,ed,e;
	 struct timeb before, after;
     double t;
	 /* Timing start */
	 ftime(&before);
	 
     while(scanf("%d",&n) && n>0){
         for(i=1;i<=n;i++)
             for(j=1;j<=n;j++)
                 f[i][j]=0;
         scanf("%d %d %d",&st,&ed,&e);
         while(e--){
             scanf("%d %d %d",&i,&j,&k);
             f[i][j]+=k;
             f[j][i]+=k;
         }
         printf("Network %d\nThe bandwidth is %d.\n\n",++C,flow(st,ed));
     }
	 /* Timing ends */
     ftime(&after);

     /* Get the elapse time between before and after */
     t = elapse(&before, &after);

     /* Print the number of seconds between before and after */
     fprintf(stderr,"The elapse time is: %lf seconds\n", t);

 }
