#include <stdio.h>
#include <string.h>
#include <algorithm>

class node{
	private:
		char s[100];
		int len;
	public:

		bool operator < (node t) const {
			return strcmp(s,t.s) < 0;
		}

		void getss(){
			gets(s);
		}

		void getlen(){
			len = strlen(s);
		}

		char *ps(){
			return s;
		}

		int plen(){
			return len;
		}
	
}file[1000];

int main(){
	int n,i,j,k,t;
	int col,max;
	while(scanf("%d",&n) != EOF){
		getchar();
		max = 0;
		for(i=0;i<n;i++){
			file[i].getss();
			file[i].getlen();
			if(max < file[i].plen())
				max = file[i].plen();
		}
		puts("------------------------------------------------------------");
		std::sort(file,file+n);
		if(max < 60){
			t = (60-max)/(max+2)+1;
			if(n%t == 0){
				col = n/t;
			} else {
				col = n/t+1;
			}
		} else {
			col = n;
		}
		for(i=0;i<col;i++,puts(""))
			for(j=i;j<n;j+=col){
				printf("%s",file[j].ps());
				for(k=max-file[j].plen();k>0;k--)
					printf(" ");
				if(j+col >= n)	continue;
				printf("  ");
			}
	}
	return 0;
}
