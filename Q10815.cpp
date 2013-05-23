#include <stdio.h>
#include <string.h>
#include <set>

using std::set;
struct node {
	int len;
	char word[110];
	
	node() { len = 0; }
	
	bool operator < (const node &t) const {
		return (strcmp(word,t.word) < 0);
	}
	
	bool operator == (const node &t) const {
		return (strcmp(word,t.word) == 0);
	}
	
	void copy(char *s) {
		len = strlen(s);
		for(int i=0;i<len;i++)
			word[i] = s[i];
		word[len] = '\0';
	}
	
	void Output() const {
		puts(word);
	}
	
	bool getWord() {
		if(scanf("%s",word) == EOF)	return false;
		return true;
	}
};

set< node > ans;

void Process(node &temp) {
	int i,j;
	
	i = 0;
	while(1) {
		if(temp.word[i] == '\0')	break;;
		char tmp[110];
		for(j=0; ;i++,j++) {
			if(temp.word[i] >= 'A' && temp.word[i] <= 'Z')	temp.word[i] = temp.word[i]-'A'+'a';
			if(temp.word[i] >= 'a' && temp.word[i] <= 'z')	tmp[j] = temp.word[i];
			else break;
		}
		tmp[j] = '\0';
		if(strlen(tmp) == 0) {
			i++;
			continue;
		}
		node cre;
		cre.copy(tmp);
		ans.insert(cre);
		if(temp.word[i] == '\0')	break;
		i++;
	}
	
}

int main() {

	node temp;
	while( temp.getWord() )
		Process(temp);

	for(set< node >::iterator i=ans.begin();i != ans.end();i++)
		i->Output();
	
	return 0;
}
