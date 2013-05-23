#include<stdio.h>
struct matrix{
    int m[41][41];
};
int n;
void multiple(matrix *a,matrix*b){
    int i,j,k,t;
    matrix rec;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            for(k=t=0;k<n;k++)
                t=(t+a->m[i][k]*b->m[k][j])%10;
            rec.m[i][j]=t;
        }
    *a=rec;
}
matrix pow(int p,matrix *a){
    if(p==1)    return *a;
    matrix rec;
    rec=pow(p/2,a);
    multiple(&rec,&rec);
    if(p%2==0)  return rec;
    multiple(&rec,a);
    return rec;
}
matrix go(int k,matrix *a){
    if(k==1)    return *a;
    matrix ans,t,rec={{{0}}};
    int i,j;
    if(k%2) rec=pow(k--,a);
    ans=pow(k/2,a);
    for(i=0;i<n;i++)
        ans.m[i][i]=(ans.m[i][i]+1)%10;
    t=go(k/2,a);
    multiple(&ans,&t);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans.m[i][j]=(ans.m[i][j]+rec.m[i][j])%10;
    return ans;
}
main(){
    int k,i,j;
    matrix s,ans;
    while(scanf("%d %d",&n,&k) && n){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&s.m[i][j]),s.m[i][j]%=10;
        ans=go(k,&s);
        for(i=0;i<n;i++,puts("")){
            printf("%d",ans.m[i][0]);
            for(j=1;j<n;j++)
                printf(" %d",ans.m[i][j]);
        }
        puts("");
    }
}
