#include<stdio.h>
#include<string.h>
struct node{
    
    int t[2050],len;
        
    node(){
        len=1;
        memset(t,0,sizeof(t));
    }
    
    node operator +(node p){
        node res;
        for(int i=0;i<2000;i++)
            res.t[i]=t[i]+p.t[i];
        for(int i=0;i<2000;i++)
            if(res.t[i]>=10){
                res.t[i+1]+=res.t[i]/10;
                res.t[i]%=10;
            }
        for(int i=2000;i--;)
            if(res.t[i]>0){
                res.len=i+1;
                return res;
            }
        res.len=1;
        return res;
    }
    
    node operator *(int p){
        node res;
        for(int i=0;i<2000;i++)
            res.t[i]=t[i]*p;
        for(int i=0;i<2000;i++)
            if(res.t[i]>=10){
                res.t[i+1]+=res.t[i]/10;
                res.t[i]%=10;
            }
        for(int i=2000;i--;)
            if(res.t[i]>0){
                res.len=i+1;
                return res;
            }
        res.len=1;
        return res;
    }
    
    void print(){
        for(int i=len-1;i>=0;i--)
            printf("%d",t[i]);
        puts("");
    }
    
}s[801];
main(){
    int n;
    s[1].t[0]=1;
    for(n=2;n<800;n++)
        s[n]=(s[n-1]+s[n-2])*n;
    while(scanf("%d",&n) && n!=-1)
        s[n-1].print();
}
