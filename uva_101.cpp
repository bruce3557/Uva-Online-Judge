#include <stdio.h>
#include <string.h>

int n;
int s[30][30],pile[30],len[30];

void Print() {
	for(int i=0;i<n;i++) {
		printf("%d:",i);
		for(int j=0;j<len[i];j++)
			printf(" %d",s[i][j]);
		puts("");
	}
}

int main() {

	while(scanf("%d",&n) != EOF) {
		for(int i=0;i<n;i++) {
			s[i][0] = i;
			len[i] = 1;
		}
		
		char str[10];
		while(1) {
			scanf("%s",str);
			int a,b;
			char dtr[10];
			if(strcmp(str,"quit") == 0)	break;
			if(strcmp(str,"move") == 0) {	
				scanf("%d %s %d",&a,dtr,&b);
				if(a == b)	continue;
				if(strcmp(dtr,"onto") == 0) {
					int ptr,i;
					for(i=0;i<n;i++) {
						for(ptr=0;ptr<len[i];ptr++)
							if(s[i][ptr] == a)
								break;
						if(ptr < len[i])	break;
					}
					
					int ib,ptrb;
					for(ib=0;ib<n;ib++) {
						for(ptrb=0;ptrb<len[ib];ptrb++)
							if(s[ib][ptrb] == b)
								break;
						if(ptrb < len[ib])	break;
					}
					
					if(i == ib)	continue;
					
					for(int j=ptr+1;j<len[i];j++) {
						int tmp = s[i][j];
						s[tmp][len[tmp]] = tmp;
						len[tmp]++;
					}
					
					for(int j=ptrb+1;j<len[ib];j++) {
						int tmp = s[ib][j];
						s[tmp][len[tmp]] = tmp;
						len[tmp]++;
					}
					
					len[ib] = ptrb+1;
					s[ib][len[ib]++] = s[i][ptr];
					len[i] = ptr;
				} else if(strcmp(dtr,"over") == 0) {
					int ptr,i;
					for(i=0;i<n;i++) {
						for(ptr=0;ptr<len[i];ptr++)
							if(s[i][ptr] == a)
								break;
						if(ptr < len[i])	break;
					}
					
					int ib,ptrb;
					for(ib=0;ib<n;ib++) {
						for(ptrb=0;ptrb<len[ib];ptrb++)
							if(s[ib][ptrb] == b)
								break;
						if(ptrb < len[ib])	break;
					}
					
					if(i == ib)	continue;
					
					for(int j=ptr+1;j<len[i];j++) {
						int tmp = s[i][j];
						s[tmp][len[tmp]] = tmp;
						len[tmp]++;
					}
					
					s[ib][len[ib]++] = s[i][ptr];
					len[i] = ptr;
				}
			} else if(strcmp(str,"pile") == 0) {
				scanf("%d %s %d",&a,dtr,&b);
				if(a == b)	continue;
				if(strcmp(dtr,"onto") == 0) {
					int i,ptr;
					int ib,ptrb;
					for(ib=0;ib<n;ib++) {
						for(ptrb=0;ptrb<len[ib];ptrb++)
							if(s[ib][ptrb] == b)
								break;
						if(ptrb < len[ib])	break;
					}
					
					for(int j=ptrb+1;j<len[ib];j++) {
						int tmp = s[ib][j];
						s[tmp][len[tmp]] = tmp;
						len[tmp]++;
					}
					len[ib] = ptrb+1;
					
					for(i=0;i<n;i++) {
						for(ptr=0;ptr<len[i];ptr++)
							if(s[i][ptr] == a)
								break;
						if(ptr < len[i])	break;
					}
					if(i == ib)	continue;
					for(int j=ptr;j<len[i];j++) {
						int tmp = s[i][j];
						s[ib][len[ib]] = tmp;
						len[ib]++;
					}
					len[i] = ptr;
				} else if(strcmp(dtr,"over") == 0) {
					int i,ptr;
					int ib,ptrb;
					for(ib=0;ib<n;ib++) {
						for(ptrb=0;ptrb<len[ib];ptrb++)
							if(s[ib][ptrb] == b)
								break;
						if(ptrb < len[ib])	break;
					}
					
					for(i=0;i<n;i++) {
						for(ptr=0;ptr<len[i];ptr++)
							if(s[i][ptr] == a)
								break;
						if(ptr < len[i])	break;
					}
					if(i == ib)	continue;
					
					for(int j=ptr;j<len[i];j++) {
						int tmp = s[i][j];
						s[ib][len[ib]] = tmp;
						len[ib]++;
					}
					len[i] = ptr;
				}
			}
		}
		
		Print();
	}

	return 0;
}
