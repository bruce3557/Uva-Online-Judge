#include<stdio.h>

struct node{
    int a,b;
}s[20010];

int abs(int x){return x>0?(x):(-x);}

int dp[20010][2],n;

main(){
    int i,j,k;
    while(scanf("%d",&n) && n){
        s[0]=(node){1,1};
        for(i=1;i<=n;i++)
            scanf("%d %d",&s[i].a,&s[i].b);
        s[n].b=n;
        for(i=1;i<=n;i++){
            j=dp[i-1][0]+abs(s[i-1].a-s[i].b);
            k=dp[i-1][1]+abs(s[i-1].b-s[i].b);
            dp[i][0]=((j<k)?(j):(k))+s[i].b-s[i].a;//走到左邊 
            j=dp[i-1][0]+abs(s[i-1].a-s[i].a);
            k=dp[i-1][1]+abs(s[i-1].b-s[i].a);
            dp[i][1]=((j<k)?(j):(k))+s[i].b-s[i].a;//走到右邊 
        }
        printf("%d\n",dp[n][1]+n-1);
    }
}
