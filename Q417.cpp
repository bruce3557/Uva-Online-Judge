#include<stdio.h>
#include<string.h>
char s[10];
struct node{
    char t[10];
    int len;
}d[100000];
main(){
    int n,i,j,k,l;
    for(i=1;i<=26;i++){
        d[i].t[0]='a'+i-1;
        d[i].len=1;
    }
    
    i=1,j=27;
    while(i<j){
        if(d[i].len<5){
            for(l=d[i].t[d[i].len-1]+1;l<='z';l++){
                for(k=0;k<d[i].len;k++)
                    d[j].t[k]=d[i].t[k];
                d[j].t[k]=l;
                d[j].len=d[i].len+1;
                j++;
            }
        }
        i++;
    }
    
    while(gets(s)!=NULL){
        n=strlen(s);
        for(i=1;i<n && s[i]>s[i-1];i++);
        if(i<n) puts("0");
        else{
            for(i=1;i<83682;i++)
                if(n==d[i].len){
                    for(j=0;j<n && d[i].t[j]==s[j];j++);
                    if(j>=n)
                        printf("%d\n",i);
                }
        }
    }
}
