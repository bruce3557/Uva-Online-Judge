#include<stdio.h>
main(){
    int t,n,k,i,j,mod[101],last[101],tmp;
    while(scanf("%d %d",&n,&k)!=EOF){
        scanf("%d",&tmp);
        for(i=0;i<k;i++)
            mod[i]=0;
        tmp%=k;
        if(tmp<0)
            tmp=-tmp;
        mod[tmp]=1;
        for(i=1;i<n;i++){
            scanf("%d",&tmp),tmp%=k;
            if(tmp<0)  tmp=-tmp;
            for(j=0;j<k;j++)
                last[j]=0;
            for(j=0;j<k;j++)
                if(mod[j]){
                    last[(j+tmp)%k]=1;
                    if(j>tmp)
                        last[(j-tmp)%k]=1;
                    else
                        last[(tmp-j)%k]=1;
                }
            for(j=0;j<k;j++)
                mod[j]=last[j];
        }
        if(mod[0])
            puts("Divisible");
        else
            puts("Not divisible");
                   
    }
}
