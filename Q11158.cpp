#include<stdio.h>
#include<algorithm>
using namespace std;
int s[51];
main(){
    int t,n,i,j,k,l,ans,c=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);
        k=s[0],l=s[n-1],ans=0;
        for(i=1;i<(n+1)/2;i++){
            if(i==n-1-i){
                ans+=(s[i]-k)>?(s[i]-l);
                break;
            }
            if(s[i]-k>s[i]-l && s[i]-k>s[n-i-1]-l){

            }
        }
        printf("Case %d: %d\n",++c,ans);
    }
}
