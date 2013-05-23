#include <stdio.h>
#include <string.h>

struct node {
    char word[1010];
} ZZ[100010];

int len[100010],n,st[100],tt;
int ind[100],out[100];
int map[100][100];

void go(int now) {
    int i;
    for(i=0;i<26;i++)
        if(map[now][i]>0) {
            map[now][i]--;
            go(i);
            tt++;
        }
}

int main() {

    int t,total;
    int i,j,tmp,num,a,b,c,t2,start,cnt;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%*c",&n);
        memset(ind,0,sizeof(ind));
        memset(out,0,sizeof(out));
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
            gets(ZZ[i].word);

        for(i=0;i<n;i++)
            len[i] = strlen(ZZ[i].word);

        for(i=0;i<n;i++) {
            tmp = ZZ[i].word[len[i]-1]-'a';
            t2 = ZZ[i].word[0]-'a';
            out[t2]++,ind[tmp]++;
            map[t2][tmp]++;
        }
        num = a = b = total = 0;
        for(i=0;i<26;i++)
            if(ind[i] || out[i])
                total++;
        for(i=0;i<26;i++) {
            if(ind[i] || out[i]) {
                if(out[i] == ind[i]-1)
                    a++;
                else if(out[i] == ind[i]+1)
                    b++,start=i;
                else if(out[i] == ind[i])
                    num++;
            }
        }
        if((num == total-2 && a == 1 && b == 1) || num == total) {
            tt = 0;
            if(num == total) {
				for(i=0;i<26;i++)
					if(out[i] || ind[i]) {
						start = i;
						break;
					}
			}
            go(start);
            if(tt >= n)
                puts("Ordering is possible.");
            else
                puts("The door cannot be opened.");
        } else {
            puts("The door cannot be opened.");
        }
    }

    return 0;
}
