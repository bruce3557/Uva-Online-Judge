#include <stdio.h>
#include <string.h>

char flag;

char tran(char& x) {
	if(x >= 'A' && x <= 'C')		return '2';
	else if(x >= 'D' && x <= 'F')	return '3';
	else if(x >= 'G' && x <= 'I')	return '4';
	else if(x >= 'J' && x <= 'L')	return '5';
	else if(x >= 'M' && x <= 'O')	return '6';
	else if(x >= 'P' && x <= 'S')	return '7';
	else if(x >= 'T' && x <= 'V')	return '8';
	else							return '9';
}

struct node {
	char s[10];
	int len;
	
	node() { len = 0; }
	
	void set(char *ss,int slen) {
		len = 0;
		for(int i=0;i<slen;i++) {
			if(ss[i] >= '0' && ss[i] <= '9')
				s[len++] = ss[i];
			else if(ss[i] >= 'A' && ss[i] <= 'Z')
				s[len++] = tran(ss[i]);
		}
		s[len] = '\0';
	}
	
	bool operator < (node t) const {
		return strcmp(s,t.s) < 0;
	}
	
	bool operator == (node t) const {
		return strcmp(s,t.s) == 0;
	}
	
};

struct BST {
	int count;
	node x;
	BST *left,*right;
	
	BST() {
		count = 0;
		left = right = NULL;
	}
	
	BST(node a) {
		count = 1;
		x = a;
		left = right = NULL;
	}
	
};

bool find(BST *ptr,node a) {
	while(ptr != NULL) {
		if(a == (ptr->x)) {
			ptr->count++;
			return true; 
		}
		if(a < (ptr->x)) {
			ptr = ptr->left;
		} else {
			ptr = ptr->right;
		}
	}
	return false;
}

void insert(BST *ptr,node a) {
	while(1) {
		if(a < (ptr->x)) {
			if(ptr->left == NULL) {
				ptr->left = new BST(a);
				return;
			}
			ptr = ptr->left;
		} else {
			if(ptr->right == NULL) {
				ptr->right = new BST(a);
				return;
			}
			ptr = ptr->right;
		}
		
	}
}
	
void print(BST *ptr) {
	if(ptr == NULL)	return;
	
	print(ptr->left);
	
	if(ptr->count > 1) {
		flag = 1;
		int i;
		for(i=0;i<3;i++)
			printf("%c",(ptr->x).s[i]);
		printf("-");
		for(;i<7;i++)
			printf("%c",(ptr->x).s[i]);
		printf(" %d\n",ptr->count);
	}
	
	print(ptr->right);
}

void erase(BST *ptr) {
	if(ptr == NULL)	return;
	erase(ptr->left);
	erase(ptr->right);
	delete ptr;
}

int main() {

	int t,m;
	int i,j,c=0;
	char tmp[1010];
	node tt;
	BST *head,*ptr;
	
	scanf("%d",&t);
	while(t--) {
		if(c)	puts("");
		else	c = 1;
	
		flag = 0;
		head = NULL;
		scanf("%d",&m);
		for(i=0;i<m;i++) {
			scanf("%s",tmp);
			tt.set(tmp,strlen(tmp));
			if(find(head,tt) == false) {
				if(head == NULL)
					head = new BST(tt);
				else
					insert(head,tt);
			}
		}
		
		print(head);
		erase(head);
		if(flag == 0)
			puts("No duplicates.");
	}
	
	return 0;
}
