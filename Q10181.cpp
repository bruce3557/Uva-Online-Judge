#include<algorithm>
struct node{
    int x,y;
}init[17];
int s[5][5],flag,bound;
const int dx[4]={-1,0,1,0},
          dy[4]={0,1,0,-1},
          rev_d[4]={2,3,0,1};
const char c[]="URDL";
char path[51];
inline int abs(int x){
    return x>?-x;
}
inline bool check(){
    int inv,i,j,a,aa,b,bb;
    for(i=inv=0;i<16;i++){
        if(s[i/4][i%4]==0)  inv+=i+4>>2;
        else{
            for(j=0;j<i;j++){
                a=i/4,aa=i%4;
                b=j/4,bb=j%4;
                if(s[a][aa] && s[a][aa]<s[b][bb])   inv++;
            }
        }
    }
    return (inv%2==0);
}
inline int calc(){
    int i,j,value;
    for(i=value=0;i<4;i++)
        for(j=0;j<4;j++)
            value+=abs(i-init[s[i][j]].x)+abs(j-init[s[i][j]].y);
    return value;
}
void swap(int& x,int& y){
    int tmp;
    tmp=x,x=y,y=tmp;
}
inline int IDAs(int x,int y,int gv,int prevalue){
    int hv=calc()*3/2,v,nb=99999999,i,j;
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
        if(news.x>=4 || news.x<0 ||news.y>=4 || news.y<0) continue;
        path[gv]=c[i];
        swap(s[x][y],s[news.x][news.y]);
        v=IDAs(news.x,news.y,gv+1,i);
        if(flag)    return v;
        nb<?=v;
        swap(s[news.x][news.y],s[x][y]);
    }
    return nb;
}
main(){
    int t,i,j,k,ax,ay;
    init[0]=(node){3,3};
    for(i=0,k=1;i<4;i++)
        for(j=0;j<4;j++)
            init[k++]=(node){i,j};
    scanf("%d",&t);
    while(t--){
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                scanf("%d",&s[i][j]);
        if(check()==0)
            puts("This puzzle is not solvable.");
        else{
            for(i=0;i<4;i++)
                for(j=0;j<4;j++)
                    if(s[i][j]==0)
                        ax=i,ay=j;
            flag=bound=0;
            while(flag==0 && bound<57)
                bound=IDAs(ax,ay,0,-1);
            path[bound]='\0';
            puts(path);
        }
    }
}
