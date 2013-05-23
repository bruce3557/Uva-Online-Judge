#include <stdio.h>
#include <string.h>

struct node {
	char s[1010];
	int times;
	node *left,*right;
};

bool find;

void insert(char *s,node *now) {
	node *tmp;
	int t = strcmp(s,now->s),i;
	if(t == 0) {
		now->times++;
	} else if(t < 0) {
		if(now->left == NULL) {
			tmp = new node();
			for(i=0;s[i];i++)
				tmp->s[i] = s[i];
			tmp->s[i] = '\0';
			tmp->times = 1;
			now->left = tmp;
			return;
		}
		insert(s,now->left);
	} else {
		if(now->right == NULL) {
			tmp = new node();
			for(i=0;i<s[i];i++)
				tmp->s[i] = s[i];
			tmp->s[i] = '\0';
			tmp->times = 1;
			now->right = tmp;
			return;
		}
		insert(s,now->right);
	}
}

void traversal(int *num,node *now) {
	if(now == NULL)	return;
	traversal(num,now->left);
	if((now->times) == (*num)) {
		puts(now->s);
		find = true;
	}
	traversal(num,now->right);
}

void erase(node *now) {
	if(now == NULL)	return;
	node *tmp;
	tmp = now;
	erase(now->left);
	erase(now->right);
	delete tmp;
}

int main() {

	int i,len,n,c=0;;
	node *root;
	char tmp[1010],test[1010];
	
	while(scanf("%d",&n) != EOF) {
		root = NULL;
		find = false;
		if(c)	puts("");
		else	c = 1;
		while(scanf("%s",test)) {
			if(strcmp(test,"EndOfText") == 0)	break;
			len = 0;
			for(i=0;test[i];i++) {
				if(test[i] >= 'A' && test[i] <= 'Z')
					tmp[len++] = test[i]-'A'+'a';
				else if(test[i] >= 'a' && test[i] <= 'z')
					tmp[len++] = test[i];
			}
			tmp[len] = '\0';
			if(root == NULL) {
				root = new node();
				for(i=0;i<len;i++)
					root->s[i] = tmp[i];
				root->s[len] = '\0';
				root->left = root->right = NULL;
				root->times = 1;
			} else if(tmp[0] != '\0')
				insert(tmp,root);
		}
		traversal(&n,root);
		if(find == false)
			puts("There is no such word.");
		erase(root);
	}

	return 0;
}
