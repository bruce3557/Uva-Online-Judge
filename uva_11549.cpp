#include<stdio.h>
#include<map>
using namespace std;
long long s[10];
int main(){
	long long t,i;
	long long n,k,tmp,tt,max;
	map<long long,char> used;
	s[0] = 1;
	for(i=1;i<=9;i++)
		s[i] = s[i-1]*10;
	scanf("%lld",&t);
	while(t--){
		used.clear();
		scanf("%lld%lld",&n,&k);
		max = k;
		used[k] = 1;
		tmp = k*k;
		if(tmp >= s[n]){
			while(tmp >= s[n])	tmp /= 10;
		}
		
		if(max < tmp)
			max = tmp;
		while(used[tmp] == 0){
			used[tmp] = 1;
			tmp *= tmp;
			if(tmp >= s[n]){
				while(tmp >= s[n]) tmp /=10;
			}
			if(max < tmp)
				max = tmp;
		}
		printf("%lld\n",max);
	}
	return 0;
}
