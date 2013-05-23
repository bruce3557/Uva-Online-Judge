#include<stdio.h>
#include<string.h>
char s[100][100];
int n,len[100];

int find(int a,int b){
	int i,j,k,count,max = 0;
	for(i=0;i<len[a];i++){
		count = 0;
		for(j=0,k=i;j<len[b] && k<i+len[b];j++,k++)
			if(s[b][j]!=0 && s[a][k]!=0){
				if(s[b][j] == s[a][k])
					count++;
			}
		if(count > max)	max = count;
	}
	for(i=0;i<len[b];i++){
		count = 0;
		for(j=0,k=i;j<len[a] && k<i+len[a];j++,k++)
			if(s[a][j]!=0 && s[b][k]!=0){
				if(s[a][j] == s[b][k])
					count++;
			}
		if(count > max) max = count;
	}
	return max;
}

int main(){
	int t,i,j,max,minlen;
	int tmp;
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		max = 0;
		for(i=0;i<n;i++)
			len[i] = strlen(s[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++){
				tmp = find(i,j);
				if(tmp > max)
					max = tmp;
			}
		printf("%d\n",max);
	}
	return 0;
}
