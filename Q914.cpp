#include<stdio.h>
char notp[1000001];
int  gap[1000001],dis[200];
main(){
    int i,j,t,n,m,pre,max,maxp,cnt,len;
    for(i=0;i<1000001;i++)  if(i%2) notp[i]=1;
    for(notp[2]=1,notp[1]=notp[0]=0,i=3;i<1000002/i;i+=2)
        if(notp[i])
            for(j=i*i;j<1000002;j+=i*2)
                notp[j]=0;
    for(i=3,pre=2,max=-1;i<1000002;i+=2)
        if(notp[i]==1)  gap[pre]=i-pre,pre=i;
    gap[999983]=2000,scanf("%d",&t);
    while(t--){
        for(i=0;i<200;i++)    dis[i]=0;
        scanf("%d %d",&n,&m);
        for(i=n;i<=m && notp[i]==0;i++);
        if(i>m)    puts("No jumping champion");
        else{
            for(;i+gap[i]<=m;i+=gap[i])    dis[gap[i]]++;
            for(i=1,max=-1,maxp=-1;i<201;i++)
                if(max<dis[i])  max=dis[i],maxp=i;
            for(i=1,cnt=0;i<201;i++)
                if(dis[i]==max && i!=maxp){
                    cnt=1;
                    break;
                }
            if(cnt==1)  puts("No jumping champion");
            else        printf("The jumping champion is %d\n",maxp);
        }
    }
}
