#include <iostream>
#include <map>

int group[100010],v[100010];

int Union_Find(int visit) {
	if(v[visit] == visit)	return visit;
	return v[visit] = Union_Find(v[visit]);
}

int main() {

	int t,m,n,ptr1,ptr2,i;
	std::string s1,s2;
	std:: map<std::string, int> h;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&m);
		
		h.clear();
		for(i=0,n=1;i<=m+1;i++)
			group[i] = 1;
		
		while(m--) {
			std::cin >> s1 >> s2;
		
			if(h[s1] == 0) {
				h[s1] = n;
				v[n] = n;
				n++;
			}
			ptr1 = h[s1];
			
			if(h[s2] == 0) {
				h[s2] = n;
				v[n] = n;
				n++;
			}
			ptr2 = h[s2];
			
			ptr1 = Union_Find(ptr1);
			ptr2 = Union_Find(ptr2);
			
			if(ptr1 != ptr2) {
				group[ptr1] += group[ptr2];
				v[ptr2] = ptr1;
			}
			
			printf("%d\n",group[ptr1]);
		}
	}

	return 0;
}
