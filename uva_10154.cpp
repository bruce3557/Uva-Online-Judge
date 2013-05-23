#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct turtle{
    int wei,str;
}tut[5610];
int cmp(const void *a,const void *b){
    return (*(turtle *)a).str-(*(turtle *)b).str;
}
main(){
    int i,j,max,n,cnt,now,nowset,s[5610];//囧s為現在疊到最多
    for(n=0;scanf("%d %d",&tut[n].wei,&tut[n].str)!=EOF;n++);
    qsort(tut,n,sizeof(tut[0]),cmp);
    for(i=now=cnt=0;i<n;i++){
        if(tut[i].wei+now<=tut[i].str){
            s[cnt++]=i;
            now+=tut[i].wei;
        }
        else{
            for(j=0,max=nowset=-1;j<cnt;j++){
                if(tut[s[j]].wei>max){
                    max=tut[s[j]].wei;
                    nowset=j;
                }
            }
            if(max>tut[i].wei){
                s[nowset]=i;
                now-=max-tut[i].wei;
            }
        }
    }
    printf("%d\n",cnt);
}