#include<stdio.h>
#include<string.h>
struct node{
    int s[401],len;
}rec[200];

int n,m,p[2],x[2],y[2],st[2],lis[40001],len[2];
char s[21][21],a1[20001],a2[20001],t[2][20001];

main(){

    int tc,i,j,k,slen,max,c=0;
    scanf("%d",&tc);
    while(tc--){

        scanf("%d %d%*c",&n,&m);
        for(i=1;i<=n;i++)
            gets(s[i]+1);
        scanf("%d %d %d%*c",&p[0],&x[0],&y[0]);
        gets(a1);
        scanf("%d %d %d%*c",&p[1],&x[1],&y[1]);
        gets(a2);

        len[0]=len[1]=0;
        t[0][len[0]++]=s[x[0]][y[0]];
        for(i=0,slen=strlen(a1);i<=slen;i++){
            if(a1[i]=='E'){
                y[0]++;
                t[0][len[0]++]=s[x[0]][y[0]];
            }
            else if(a1[i]=='W'){
                y[0]--;
                t[0][len[0]++]=s[x[0]][y[0]];
            }
            else if(a1[i]=='N'){
                x[0]--;
                t[0][len[0]++]=s[x[0]][y[0]];
            }
            else if(a1[i]=='S'){
                x[0]++;
                t[0][len[0]++]=s[x[0]][y[0]];
            }
        }
        t[1][len[1]++]=s[x[1]][y[1]];
        for(i=0,slen=strlen(a2);i<=slen;i++){
            if(a2[i]=='E'){
                y[1]++;
                t[1][len[1]++]=s[x[1]][y[1]];
            }
            else if(a2[i]=='W'){
                y[1]--;
                t[1][len[1]++]=s[x[1]][y[1]];
            }
            else if(a2[i]=='N'){
                x[1]--;
                t[1][len[1]++]=s[x[1]][y[1]];
            }
            else if(a2[i]=='S'){
                x[1]++;
                t[1][len[1]++]=s[x[1]][y[1]];
            }
        }
        t[0][len[0]]=t[1][len[1]]='\0';

        for(i=0;i<=200;i++,rec[i].len=0)
            for(j=0;j<401;j++)
                rec[i].s[j]=-1;
        for(i=0;i<len[0];i++)
            rec[t[0][i]].s[rec[t[0][i]].len++]=i;

        for(i=0,max=1,lis[0]=-1;i<len[1];i++)
            if(rec[t[1][i]].len){
                for(j=rec[t[1][i]].len-1;j>=0;j--){
                    if(rec[t[1][i]].s[j]>lis[max-1])
                        lis[max++]=rec[t[1][i]].s[j];
                    else{
                        for(k=max-1;k>0;k--){
                            if(rec[t[1][i]].s[j]>lis[k])
                                lis[k+1]=rec[t[1][i]].s[j];
                        }
                    }
                }
            }

        printf("Case %d: %d %d\n",++c,len[0]-max+1,len[1]-max+1);
    }
}
