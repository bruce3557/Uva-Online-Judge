#include<stdio.h>
#include<string.h>
char s[1000],rec[10];
main(){
    int i,j,k,l,n,cnt;
    while(scanf("%s",s)!=EOF){
        n=strlen(s);
        for(i=j=cnt=0;cnt<2 && i<n-2;i++)
            if(s[i]==s[i+2]){
                if(j==0){
                    rec[0]=s[i];
                    rec[1]=s[i+1];
                    j=1;
                    cnt++;
                }
                else if(rec[0]!=s[i] || rec[1]!=s[i+1])
                    cnt++;
            }
        for(i=j=0;cnt<2 && i<n-3;i++)
            if(s[i]==s[i+3] && s[i+1]==s[i+2] && s[i]!=s[i+1]){
                if(j==0){
                    rec[0]=s[i];
                    rec[1]=s[i+1];
                    j=1;
                    cnt++;
                }
                else if(rec[0]!=s[i] || rec[1]!=s[i+1])
                    cnt++;
            }
        if(cnt>=2)  puts(s);
    }
    scanf("  ");
}
