#include<stdio.h>
int n,s[10010],min;
bool notp[10000001];
main(){
    
    int t,i,j,k,min;
    char c;
    notp[0]=notp[1]=1;
    for(i=4;i<10000001;i+=2)
        notp[i]=1;
    for(i=9;i<10000001;i+=3)
        notp[i]=1;
    for(i=5,k=2;i<10001;i+=k,k=6-k)
        if(notp[i]==0){
            for(j=i*i;j<10000001;j+=i)
                notp[j]=1;
        }
    scanf("%d",&t);
    while(t--){
        
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&s[i]);
            
        min=n;
        for(i=1;i<=n;i++)
            s[i]+=s[i-1];
        for(i=0;i<n-1;i++)
            for(j=i+2;j<=n;j++)
                if(notp[s[j]-s[i]]==0){
                    min<?=j-i;
                    break;
                }
        
        if(min==n)  puts("This sequence is anti-primed.");
        else{
            printf("Shortest primed subsequence is length %d:",min);
            for(i=0;i<=n;i++)
                if(notp[s[i+min]-s[i]]==0)
                    break;
            for(j=i+1;j<=i+min;j++)
                printf(" %d",s[j]-s[j-1]);
            puts("");
        }
        
    }
}
