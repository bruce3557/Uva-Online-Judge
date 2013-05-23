#include <stdio.h>
#include <string.h>
struct LIS{
    int head;
    int len;
};
int main(){
    int on,n,m,i,j,maxlis,maxlen,p,d[1000],temp[1000];
    char s[10];
    LIS lis[1000];
    scanf("%d",&n);
    on=n;
    gets(s);
    gets(s);    //an empty line
    for(n=n;n>0;n--){
        m=0;
        while(gets(s)!=NULL){
            if(s[0]=='\x0')
                break;
            sscanf(s,"%d",&d[m++]);
        }

        if(n!=on)
            printf("\n");

        //LIS:d
        maxlis=0;
        maxlen=0;
        for(i=0;i<m;i++){
            lis[i].len=1;
            for(j=0;j<i;j++){
                if(d[i]>=d[j] && lis[i].len<lis[j].len+1){
                    lis[i].head=j;
                    lis[i].len=lis[j].len+1;
                }
            }
            if(lis[i].len>=maxlen){
                maxlen=lis[i].len;
                maxlis=i;
            }
        }

        printf("Max hits: %d\n",maxlen);
        p=maxlis;
        for(i=maxlen-1;i>=0;i--){
            temp[i]=d[p];
            p=lis[p].head;
        }
        for(i=0;i<maxlen;i++)
            printf("%d\n",temp[i]);
    }
	return 0;
}
