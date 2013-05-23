#include<stdio.h>
#include<string.h>
struct node{
    int t[100],len;
    node(){
        len=0;
        memset(t,0,sizeof(t));
    }
    node operator +(node p){
        node res;
        for(int i=0;i<len || i<p.len;i++)
            res.t[i]=t[i]+p.t[i];
        for(int i=0;i<len || i<p.len;i++)
            if(res.t[i]>=10){
                res.t[i+1]+=res.t[i]/10;
                res.t[i]%=10;
            }
        for(int i=(len>?p.len)+5;i;i--)
            if(res.t[i]>0){
                res.len=i+1;
                return res;
            }
        res.len=1;
        return res;
    }
    void print(){
        for(int i=(len-1)>?0;i>=0;i--)
            printf("%d",t[i]);
        puts("");
    }
}s[260];
main(){
    int n;
    s[0].t[0]=s[1].t[0]=s[0].len=s[1].len=1;
    for(n=2;n<=250;n++)
        s[n]=s[n-2]+s[n-2]+s[n-1];
    while(scanf("%d",&n)!=EOF)
        if(n==0)    puts("0");
        else        s[n].print();
}
