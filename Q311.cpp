#include<stdio.h>
int s[6],ans;
main(){
    while(scanf("%d%d%d%d%d%d",&s[0],&s[1],&s[2],&s[3],&s[4],&s[5])){
        if(s[0]+s[1]+s[2]+s[3]+s[4]+s[5]==0)    break;
        ans=s[5]+s[4]+s[3];
        s[0]-=s[4]*11;
        if(s[3]*5>s[1]){
            s[0]-=(s[3]*5-s[1])*4;
            s[1]=0;
        }
        else    s[1]-=s[3]*5;
        ans+=s[2]/4,s[2]%=4;
        if(s[2]==3){
            ans++;
            s[0]-=9-(s[1]<?1)*4;
            if(s[1]>=1)
                s[1]--;
            else    s[1]=0;
        }
        else if(s[2]==2){
            ans++;
            s[0]-=18-(s[1]<?3)*4;
            if(s[1]>=3)
                s[1]-=3;
            else    s[1]=0;
        }
        else if(s[2]==1){
            ans++;
            s[0]-=27-(s[1]<?5)*4;
            if(s[1]>=5)
                s[1]-=5;
            else    s[1]=0;
        }
        ans+=s[1]/9,s[1]%=9;
        if(s[1]>0){
            ans++;
            s[0]-=36-s[1]*4;
        }
        s[0]>?=0;
        ans+=s[0]/36+(s[0]%36>0);
        printf("%d\n",ans);
    }
}
