#include<algorithm>
struct node{
    int x,y;
}init[10];
int flag,bound;
const int dx[4]={-1,0,1,0},
          dy[4]={0,1,0,-1},
          rev_d[4]={2,3,0,1};
const char c[]="urdl";
char path[51],s[5][5];
inline int abs(int x){
    return x>?-x;
}
inline bool check(){
    int inv,i,j,a,aa,b,bb;
    for(i=inv=0;i<9;i++){
        for(j=0;j<i;j++){
            a=i/3,aa=i%3;
            b=j/3,bb=j%3;
            if(s[a][aa] && s[a][aa]<s[b][bb])   inv++;
        }
    }
    return (inv%2==0);
}
inline int calc(){
    int i,j,value;
    for(i=value=0;i<3;i++)
        for(j=0;j<3;j++)
            value+=abs(i-init[s[i][j]].x)+abs(j-init[s[i][j]].y);
    return value;
}
inline int IDAs(int x,int y,int gv,int prevalue){
    int hv=calc(),v,nb=99999999,i,j;
    if(flag)    return gv;
    
    if(gv+hv>bound) return gv+hv;   
    
    if(hv==0){
        flag=1;
        return gv;
    }
    
    node news;
    for(i=0;i<4;i++){
        news=(node){x+dx[i],y+dy[i]};
        if(rev_d[i]==prevalue)  continue;
        if(news.x>=3 || news.x<0 ||news.y>=3 || news.y<0) continue;
        path[gv]=c[i];
        std::swap(s[x][y],s[news.x][news.y]);
        v=IDAs(news.x,news.y,gv+1,i);
        if(flag)    return v;
        nb<?=v;
        std::swap(s[news.x][news.y],s[x][y]);
    }
    return nb;
}
main(){
    int t,i,j,k,ax,ay;
    for(i=0,k=1;i<3;i++)
        for(j=0;j<3;j++)
            init[k++]=(node){i,j};
    init[0]=(node){2,2};
    scanf("%d%*c",&t);
    while(t--){
        scanf("%*c");
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                scanf("%c%*c",&s[i][j]);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++){
                if(s[i][j]=='x')    s[i][j]=0,ax=i,ay=j;
                else                s[i][j]-='0';
            }
        if(check()==0)
            puts("unsolvable");
        else{
            flag=bound=0;
            while(flag==0 && bound<38)
                bound=IDAs(ax,ay,0,-1);
            path[bound]='\0';
            puts(path);
        }
   }
}
