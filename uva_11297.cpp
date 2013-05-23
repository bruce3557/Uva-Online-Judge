#include <stdio.h>
#include <string.h>
#define MAX (100000000000000000LL)

int n,m;
long long s[710][710];

inline long long F_Max(long long a, long long b) {	return a>b?a:b;	}
inline long long F_Min(long long a, long long b) {	return a<b?a:b; }

struct node {
	int lub,rub,ldb,rdb;
	long long Max, Min;
	node *one, *two, *three, *four;
	
	node() {
		Max = 0;
		Min = MAX;
		one = two = three = four = NULL;
	}
};

node *Build(node *ptr, int lubb, int rubb, int ldbb, int rdbb) {
	if(lubb > ldbb || rubb > rdbb)	return NULL;
	//printf("%d %d %d %d\n",lubb,rubb,ldbb,rdbb);
	if(lubb == ldbb && rubb == rdbb) {
		node *n_node = new node();
		n_node->lub = lubb;	n_node->rub = rubb;	n_node->ldb = ldbb;	n_node->rdb = rdbb;
		if(lubb > n || rubb > n) {
			n_node->Max = -MAX;
			n_node->Min = MAX;
			return n_node;
		}
		n_node->Max = n_node->Min = s[lubb][rubb];
		return n_node;
	}
	
	int mid_l = (lubb+ldbb)/2;
	int mid_r = (rubb+rdbb)/2;
	ptr = new node();
	ptr->lub = lubb;	ptr->rub = rubb;	ptr->ldb = ldbb;	ptr->rdb = rdbb;
	
	ptr->one = Build(ptr->one, lubb, rubb, mid_l, mid_r);
	if(ptr->one != NULL) {
		ptr->Max = F_Max(ptr->Max, ptr->one->Max);
		ptr->Min = F_Min(ptr->Min, ptr->one->Min);
	}
	ptr->two = Build(ptr->two, mid_l+1, rubb, ldbb, mid_r);
	if(ptr->two != NULL) {
		ptr->Max = F_Max(ptr->Max, ptr->two->Max);
		ptr->Min = F_Min(ptr->Min, ptr->two->Min);
	}
	ptr->three = Build(ptr->three, lubb, mid_r+1, mid_l, rdbb);
	if(ptr->three != NULL) {
		ptr->Max = F_Max(ptr->Max, ptr->three->Max);
		ptr->Min = F_Min(ptr->Min, ptr->three->Min);
	}
	ptr->four = Build(ptr->four, mid_l+1, mid_r+1, ldbb, rdbb);
	if(ptr->four != NULL) {
		ptr->Max = F_Max(ptr->Max, ptr->four->Max);
		ptr->Min = F_Min(ptr->Min, ptr->four->Min);
	}
	
	return ptr;
}

void Erase(node *ptr) {
	if(ptr == NULL)	return;
	Erase(ptr->one);
	Erase(ptr->two);
	Erase(ptr->three);
	Erase(ptr->four);
	delete ptr;
}

void Query(node *ptr, int lubb, int rubb, int ldbb, int rdbb, long long &min, long long &max) {
	if(lubb > ldbb || rubb > rdbb)	return;
	if(ptr == NULL)	return;
	if(lubb < ptr->lub || ldbb > ptr->ldb || rubb < ptr->rub || rdbb > ptr->rdb)	return;
	if(lubb == ptr->lub && rubb == ptr->rub && ldbb == ptr->ldb && rdbb == ptr->rdb) {
		min = F_Min(min, ptr->Min);
		max = F_Max(max, ptr->Max);
		return;
	}
	
	int mid_l = (ptr->lub+ptr->ldb)/2;
	int mid_r = (ptr->rub+ptr->rdb)/2;
	
	//the four section
	if(mid_l >= ldbb && mid_r >= rdbb) {
		Query(ptr->one, lubb, rubb, ldbb, rdbb, min, max);
		return;
	}	
	if(mid_l < lubb && mid_r >= rdbb) {
		Query(ptr->two, lubb, rubb, ldbb, rdbb, min, max);
		return;
	}	
	if(mid_r < rubb && mid_l >= ldbb) {
		Query(ptr->three, lubb, rubb, ldbb, rdbb, min, max);
		return;
	}	
	if(mid_l < lubb && mid_r < rubb) {
		Query(ptr->four, lubb, rubb, ldbb, rdbb, min, max);
		return;
	}
	
	//two intersection
	if(ptr->lub <= lubb && ptr->ldb >= ldbb && mid_r >= rdbb) {
		Query(ptr->one, lubb, rubb, mid_l, rdbb, min, max);
		Query(ptr->two, mid_l+1, rubb, ldbb, rdbb, min, max);
		return;
	}
	if(ptr->rub <= rubb && ptr->rdb >= rdbb && mid_l >= ldbb) {
		Query(ptr->one, lubb, rubb, ldbb, mid_r, min, max);
		Query(ptr->three, lubb, mid_r+1, ldbb, rdbb, min, max);
		return;
	}
	if(ptr->lub <= lubb && ptr->ldb >= ldbb && mid_r < rubb) {
		Query(ptr->three, lubb, rubb, mid_l, rdbb, min, max);
		Query(ptr->four, mid_l+1, rubb, ldbb, rdbb, min, max);
		return;
	}
	if(ptr->rub <= rubb && ptr->rdb >= rdbb && mid_l < lubb) {
		Query(ptr->two, lubb, rubb, ldbb, mid_r, min, max);
		Query(ptr->four, lubb, mid_r+1, ldbb, rdbb, min, max);
		return;
	}
	
	//four
	Query(ptr->one, lubb, rubb, mid_l, mid_r, min, max);
	Query(ptr->two, mid_l+1, rubb, ldbb, mid_r, min, max);
	Query(ptr->three, lubb, mid_r+1, mid_l, rdbb, min, max);
	Query(ptr->four,  mid_l+1, mid_r+1, ldbb, rdbb, min, max);
}

void Change(node *ptr, int lubb, int rubb, int ldbb, int rdbb, long long value) {
	if(lubb > ldbb || rubb > rdbb)	return ;
	if(lubb < ptr->lub || ldbb > ptr->ldb || rubb < ptr->rub || rdbb > ptr->rdb)	return;
	if(lubb == ptr->lub && rubb == ptr->rub && ldbb == ptr->ldb && rdbb == ptr->rdb) {
		s[lubb][rubb] = value;
		ptr->Min = ptr->Max = value;
		return;
	}
	
	int mid_l = (ptr->lub+ptr->ldb)/2;
	int mid_r = (ptr->rub+ptr->rdb)/2;
	
	//the four section
	if(mid_l >= ldbb && mid_r >= rdbb) {
		if(ptr->one != NULL) {
			Change(ptr->one, lubb, rubb, ldbb, rdbb, value);
			ptr->Max = F_Max(ptr->Max, ptr->one->Max);
			ptr->Min = F_Min(ptr->Min, ptr->one->Min);
		}
		return;
	}
	
	if(mid_l < lubb && mid_r >= rubb) {
		if(ptr->two != NULL) {
			Change(ptr->two, lubb, rubb, ldbb, rdbb, value);
			ptr->Max = F_Max(ptr->Max, ptr->two->Max);
			ptr->Min = F_Min(ptr->Min, ptr->two->Min);
		}
		return;
	}
	
	if(mid_r < rubb && mid_l >= ldbb) {
		if(ptr->three != NULL) {
			Change(ptr->three, lubb, rubb, ldbb, rdbb, value);
			ptr->Max = F_Max(ptr->Max, ptr->three->Max);
			ptr->Min = F_Min(ptr->Min, ptr->three->Min);
		}
		return;
	}
	
	if(mid_l < lubb && mid_r < rubb) {
		if(ptr->four != NULL) {
			Change(ptr->four, lubb, rubb, ldbb, rdbb, value);
			ptr->Max = F_Max(ptr->Max, ptr->four->Max);
			ptr->Min = F_Min(ptr->Min, ptr->four->Min);
		}
		return;
	}
}

int main() {
	int Q;
	
	while(scanf("%d%d",&n,&m) != EOF) {
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%lld",&s[i][j]);
				
		int size=1;
		while(size < n)	size*=2;			
		node *root = Build(root, 1,1,size,size);
		
		scanf("%d",&Q);
		while(Q--) {
			char type[10];
			scanf("%s",type);
			int a,b,d;
			if(strcmp(type,"q") == 0) {
				int c;
				scanf("%d%d%d%d",&a,&b,&c,&d);
				long long ans_min, ans_max;
				ans_min = MAX;
				ans_max = -MAX;
				if(n == 0 || m == 0) {
					puts("0 0");
					continue;
				}
				/*
				if(a < 1)	a = 1;
				if(b < 1)	b = 1;
				if(c > size)	c = size;
				if(d > size)	d = size;*/
				Query(root, a, b, c, d, ans_min, ans_max);
				printf("%lld %lld\n", ans_max, ans_min);
			} else {
				long long cc;
				scanf("%d%d%lld",&a,&b,&cc);
				Change(root, a, b, a, b, cc);
			}
		}
		
		Erase(root);
	}

	return 0;
}
