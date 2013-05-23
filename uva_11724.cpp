#include <stdio.h>
#include <string.h>
#include <queue>
using std::queue;

int n,Time;
int lenop, lenvar;
int mapping[40],ind[40];
int var[500];

char map[40][40],tra[40][40];
char op[500],exp[500],used[500];
char pre[500];

int main() {
    int t,c=0;

    scanf("%d",&t);
    while(t--) {
        memset(map,0,sizeof(map));
        memset(mapping,0,sizeof(mapping));
        memset(used,0,sizeof(used));
        memset(ind,0,sizeof(ind));
        memset(tra,0,sizeof(tra));

        scanf("%s",exp);
        scanf("%d%*c",&n);
        for(int i=0;i<n;i++) {
            char a,b;
            scanf("%c>%c%*c",&a,&b);
            map[b-'a'][a-'a'] = 1;
            tra[b-'a'][a-'a'] = 1;
            ind[a-'a']++;
        }

        for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++)
                    tra[i][j] |= tra[i][k] && tra[k][j];

        bool flag = false;
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                if(tra[i][j] && tra[j][i])
                    flag = true;
        if(flag) {
            printf("Case %d: -1\n",++c);
            continue;
        }

        queue<int> Q;
        for(int i=0;i<26;i++)
            if(ind[i] == 0) {
                Q.push(i);
                mapping[i] = 1;
            }

        int count=2;
        while( !Q.empty() ) {
            int now = Q.front();
            for(int i=0;i<26;i++)
                if(map[now][i] && mapping[now]+1 > mapping[i]) {
                    Q.push(i);
                    mapping[i] = mapping[now]+1;
                }
            Q.pop();
        }

		/*trans expression to postfix*/ 
        int len = strlen(exp);
        int prelen = 0;
        lenop = lenvar = 0;
        for(int i=0;i<len;i++) {
            if(exp[i] >= 'a' && exp[i] <= 'z') {
                pre[prelen++] = exp[i];
            } else if(exp[i] == '(') {
                op[lenop++] = '(';
            } else if(exp[i] == ')') {
                while(lenop > 0 && op[lenop-1] != '(') {
                    pre[prelen++] = op[--lenop];
                }
                lenop--;
            } else if(exp[i] == '*') {
                op[lenop++] = exp[i];
            } else if(exp[i] == '+') {
                while(op[lenop-1] == '*') {
                    pre[prelen++] = op[lenop-1];
                    lenop--;
                }
                op[lenop++] = exp[i];
            }
        }
        while(lenop > 0) {
            pre[prelen++] = op[lenop-1];
            lenop--;
        }
        pre[prelen] = '\0';

		/*calculate the value of postfix expression*/
        lenvar = 0;
        int ptr,oo;
        for(ptr=0;ptr<prelen;ptr++) {
            if(pre[ptr] >= 'a' && pre[ptr] <= 'z') {
                var[lenvar++] = mapping[pre[ptr]-'a'];
            } else {
                int a,b;
                a = var[lenvar-1];
                b = var[lenvar-2];
                lenvar -= 2;
                if(pre[ptr] == '*')
                    var[lenvar++] = a*b;
                else
                    var[lenvar++] = a+b;
            }
        }

        printf("Case %d: %d\n",++c,var[0]);
    }

    return 0;
}
