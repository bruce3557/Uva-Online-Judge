#include<algorithm>

struct node{
    char s[32];
    int len,front;
    bool operator <(node t) const{
        return len<t.len;
    }
}dict[25200];

struct edge{
    int a,b;
    bool operator <(edge t) const{
        return a<t.a;
    }
}e[5000001];

int abs(int a){
    return a>?-a;
}

int q[25200],d[25200],maxl,r[25200];
bool used[25200];

int find(int a,int b){
    int i,ans=0;
    for(i=0;i<dict[a].len;i++)
        ans+=dict[a].s[i]!=dict[b].s[i];
    return ans;
}

void print(int now){
    if(dict[now].front==-1){
        puts(dict[now].s);
        return;
    }
    print(dict[now].front);
    puts(dict[now].s);
}

main(){

    int n=0,i,j,k,c=0,m=0,a,b,la,lb;
    char st[101],ed[101];

    while(gets(dict[n].s) && dict[n].s[0]!='\n' && dict[n].s[0]!='\0'){
        dict[n].len=strlen(dict[n].s);
        n++;
    }
    std::sort(dict,dict+n);
    for(i=maxl=0;i<n;i++){
        d[dict[i].len]++;
        maxl>?=dict[i].len;
    }
    for(i=1;i<=maxl;i++)
        d[i]+=d[i-1];
    
    puts("");
    for(i=0;i<n;i++)
        puts(dict[i].s);
    puts("");
    
    for(i=0;i<n;i++)
        for(j=d[dict[i].len-1];j<d[dict[i].len];j++)
            if(find(i,j)==1){
                e[m++]=(edge){i,j};
                printf("%d %d\n",i,j);
            }
    std::sort(e,e+m);
    for(i=0;i<=m;i++)
        r[e[i].a+1]++;
    for(i=1;i<=n;i++)
        printf("%d\n",r[i]);
    for(i=1;i<=n;i++)
        r[i]+=r[i-1];
    for(i=1;i<=n;i++)
        printf("%d ",r[i]);
    puts("");
    
    while(scanf("%s %s",st,ed)!=EOF){
        if(c)   puts("");
        else    c=1;
        
        if((la=strlen(st))!=strlen(ed)){
           puts("No solution.");
           continue;
        }
        
        memset(used,0,sizeof(used));
        for(i=d[la-1];i<d[la];i++)
            if(strcmp(dict[i].s,st)==0)
                break;
        for(j=d[la-1];j<d[la];j++)
            if(strcmp(dict[j].s,ed)==0)
                break;
        if(i>=d[la] || j>=d[la]){
            puts("No solution.");
            continue;
        }
        
        a=i,b=j;
        dict[a].front=dict[b].front=-1;
        q[0]=a,used[a]=1;
        i=0,j=1;
        while(i<j){
            if(q[i]==b) break;
            for(k=r[e[q[i]].a];k<r[e[q[i]].a+1];k++)
                if(used[e[k].b]==0){
                    used[e[k].b]=1;
                    q[j++]=e[k].b;
                    dict[e[k].b].front=q[i];
                }
            if(dict[b].front!=-1)   break;
            i++;
        }
        
        if(i>=j)    puts("No solution.");
        else        print(b);
        
    }

}
