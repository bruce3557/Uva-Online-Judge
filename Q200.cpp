#include<stdio.h>
#include<string.h>

char s[10001][100];
int len[10001],n,map[30][30],deg[30];

int main(){

    int i,j,min;

    for(;gets(s[n]) && s[n][0]!='#';n++);

    for(i=0;i<n;i++)
        len[i]=strlen(s[i]);

    for(i=0;i<26;i++)
        deg[i]=-1;

    for(i=0;i<n;i++)
        for(j=0;j<len[i];j++)
            if(deg[s[i][j]-'A']==-1)
                deg[s[i][j]-'A']=0;

    for(i=0;i<n-1;i++){
        min=len[i]<len[i+1] ? len[i] : len[i+1];
        for(j=0;j<min;j++)
            if(s[i][j]!=s[i+1][j]){
                if(map[s[i][j]-'A'][s[i+1][j]-'A']==0){
                    map[s[i][j]-'A'][s[i+1][j]-'A']=1;
                    deg[s[i+1][j]-'A']++;
                }
                break;
            }
    }

    while(1){
        for(i=0;i<26;i++)
            if(deg[i]==0){
                deg[i]=-1;
                printf("%c",i+'A');
                for(j=0;j<26;j++)
                    if(map[i][j])
                        deg[j]--;
                break;
            }
        if(i>=26)   break;
    }
    puts("");

    ///scanf("  ");
    return 0;
}
