#include<stdio.h>
#include<string.h>
int n,m,size[7],s[31][3];
char c[10];

int turn(){
   if(strcmp(c,"XXL") == 0)
       return 0;
   else if(strcmp(c,"XL") == 0)
       return 1;
   else if(strcmp(c,"L") == 0)
       return 2;
   else if(strcmp(c,"M") == 0)
       return 3;
   else if(strcmp(c,"S") == 0)
       return 4;
   else if(strcmp(c,"XS") == 0)
       return 5;
}

int dfs(int now){
	if(now >= m)
		return 1;
	int i;
	for(i=0;i<6;i++) {
		if(s[now][0] == i && size[i] > 0) {
			size[i]--;
			if(dfs(now+1) == 1)
				return 1;
			size[i]++;
		}
		if(s[now][1] == i && size[i] > 0) {
			size[i]--;
			if(dfs(now+1) == 1)
				return 1;
			size[i]++;
		}
	}
	
	return 0;
}

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		for(i=0;i<6;i++)
			size[i] = n/6;
		for(i=0;i<m;i++) {
			scanf("%s",c);
			s[i][0] = turn();
			scanf("%s",c);
			s[i][1] = turn();
		}
		if(dfs(0) == 1)
			puts("YES");
		else
			puts("NO");
   }
   
   return 0;
}