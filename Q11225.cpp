#include <stdio.h>
#include <string.h>

int cnt,n;
char s[100],tmp[100],tmp1[100];

double go(char *t,char *t1) {
    if(strcmp(t1,"spmurt") == 0) {
		if(strcmp(t,"one") == 0) {
			cnt++;
			return 4.5;
		}
		if(strcmp(t,"twenty-one") == 0) {
			cnt++;
			return 4.5;
		}
		return 0.5;
    }
    if(strcmp(t1,"loof") == 0){
        cnt++;
        return 4.5;
    }
    if(strcmp(t,"king") == 0)   return 4.5;
    if(strcmp(t,"queen")== 0)   return 3.5;
    if(strcmp(t,"knight") == 0) return 2.5;
    if(strcmp(t,"jack") == 0)   return 1.5;
    return 0.5;
}

int main() {

    int t,i,j,k,len,c=0;
    double point;

    scanf("%d",&t);
    while(t--) {
		if(c)	puts("");
        scanf("%d",&n);
        point = 0.0;
        cnt = 0;
        getchar();
        for(i=0;i<n;i++) {
            gets(s);
            len = strlen(s);

            for(j=k=0;j<len;j++,k++) {
                if(s[j] == ' ')
                    break;
                tmp[k] = s[j];
            }
            tmp[k] = '\0';

            for(j=len-1,k=0;j>=0;j--,k++) {
                if(s[j] == ' ') break;
                tmp1[k] = s[j];
            }
            tmp1[k] = '\0';
			
            point += go(tmp,tmp1);
        }
        printf("Hand #%d\n",++c);
        if(cnt == 3) {
            if(point < 36.0)
                printf("Game lost by %.0lf point(s).\n",36.0-point);
            else
                printf("Game won by %.0lf point(s).\n",point-36.0);
        } else if(cnt == 2) {
            if(point < 41.0)
                printf("Game lost by %.0lf point(s).\n",41.0-point);
            else
                printf("Game won by %.0lf point(s).\n",point-41.0);
        } else if(cnt == 1) {
            if(point < 51.0)
                printf("Game lost by %.0lf point(s).\n",51.0-point);
            else
                printf("Game won by %.0lf point(s).\n",point-51.0);

        } else {
            if(point < 56.0)
                printf("Game lost by %.0lf point(s).\n",56.0-point);
            else
                printf("Game won by %.0lf point(s).\n",point-56.0);

        }
        //puts("");
    }

    return 0;
}
