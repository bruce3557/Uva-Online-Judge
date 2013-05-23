#include<stdio.h>
#include<string.h>

main(){
	char c,now[2001],notp[2001];
	int t,i,j,cnt=0,count,s[128];
	
	for(i=0,notp[1]=1;i<2001;i+=2)
		notp[i] = 1;

	for(notp[2]=0,i=3;i<=2001/i;i+=2)
		for(j=i*i;j<=2001/j;j+=i*2)
			notp[j] = 1;

			scanf("%d",&t);
	while(t--){
		scanf("%s",now);
		for(i=0;i<128;i++)
			s[i] = 0;
		for(i=0;i<strlen(now);i++)
			s[now[i]]++;
		
		printf("Case %d: ",++cnt);
		for(i=count=0;i<128;i++)
			if(notp[s[i]] == 0){
				printf("%c",i);
				count = 1;
			}
		
		if(count == 0)  printf("empty");
		puts("");
	}
}