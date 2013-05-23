#include<stdio.h>
int deg[30],map[30][30],n;
char s[100],ans[100],used[30];
void go(int now){
    if(now==n){
        for(int i=0;i<n-1;i++)
            printf("%c",ans[i]+'a');
        printf("%c\n",ans[n-1]+'a');
        return;
    }
    int i,j;
    for(i=0;i<26;i++)
        if(deg[i]==0 && used[i]==0){
            ans[now]=i;
            used[i]=1;
            for(j=0;j<26;j++)
                if(map[i][j]==1)
                    deg[j]--;
            go(now+1);
            for(j=0;j<26;j++)
                if(map[i][j]==1)
                    deg[j]++;
            used[i]=0;
        }
}
main(){
    int i,j,cnt=0;
    char a,b,c,d;
    while((s[0]=getchar())!=EOF){
        if(cnt) puts("");
        else    cnt=1;
        for(i=0;i<30;i++){
            used[i]=0;
            deg[i]=-1;
        }
        n=1;
        while(getchar()!='\n')
            s[n++]=getchar();
        for(i=0;i<30;i++)
            for(j=0;j<30;j++)
                map[i][j]=0;
        for(i=n=0;s[i]!='\0';i++)
            if('a'<=s[i] && s[i]<='z')
                deg[s[i]-'a']=0,n++;
        while(scanf("%c %c%c",&a,&c,&d)){
            a-='a',c-='a';
            map[a][c]=1;
            deg[c]++;
            if(d=='\n') break;
        }
        go(0);
        for(i=0;i<100;i++)
            s[i]='\0';
    }
}
