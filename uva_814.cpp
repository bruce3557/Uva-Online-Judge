#include <stdio.h>
#include <string.h>

int n,num_city;
struct node {
	int num;
	char city[20];
	char user[110][20];
	
	node() { num = 0; }
} MTA[110], rcpt[110];

char msg[200][100];

int Find_MTA(char *dest) {
	for(int i=0;i<n;++i)
		if( !strcmp(MTA[i].city, dest ) )
			return i;
	return -1;
}

int Find_MTA_man(int pos, char *dest) {
	for(int i=0;i<MTA[pos].num;++i)
		if( !strcmp(MTA[pos].user[i], dest) )
			return i;
	return -1;
}

int Find_CT(char *dest) {
	for(int i=0;i<num_city;++i)
		if(strcmp(rcpt[i].city,dest) == 0)
			return i;
	return -1;
}

int Find_CT_user(int pos, char *dest) {
	for(int i=0;i<rcpt[pos].num;++i)
		if(strcmp(rcpt[pos].user[i], dest) == 0)
			return i;
	return -1;
}

int Response(int num) {
	if(num <= 0)	return 550;
	else	return 250;
}

int main() {
	
while(1) {	
	char type[30];
	int sdd;
	while( (sdd=scanf("%s",type)) != EOF && strcmp(type,"*") ) {
		scanf("%s %d",MTA[n].city,&MTA[n].num);
		for(int i=0;i<MTA[n].num;++i)
			scanf("%s",MTA[n].user[i]);
		++n;
	}
	if(sdd == EOF)	break;
	char sender[30];
	char sd_name[30];
	char sd_city[30];
	while(1) {
		//handle the data of sender
		scanf("%s",sender);
		if(strcmp(sender,"*") == 0)	break;
		
		int ptr=0;
		for(;sender[ptr] != '@';++ptr) sd_name[ptr] = sender[ptr];
		sd_name[ptr] = '\0';
		int i=0;
		for(++ptr;sender[ptr] != '\0';++ptr,++i)	sd_city[i] = sender[ptr];
		sd_city[i] = '\0';
		
		//handle the data of rcpt
		num_city=0;
		int len_u=0;
		char ttmp[100];
		char temp[100];
		char utmp[100];
		while(scanf("%s%*c",ttmp) && strcmp(ttmp,"*") ) {
			len_u = 0;
			for(ptr=0;ttmp[ptr] != '@';++ptr) utmp[ptr] = ttmp[ptr];
			utmp[ptr] = 0; len_u = ptr;
			for(i=0,++ptr;ttmp[ptr] != '\0';++ptr,++i)
				temp[i] = ttmp[ptr];
			temp[i] = '\0';
			
			
			
			int pos = Find_CT(temp);
			if( pos == -1 ) {
				rcpt[num_city].num = 0;
				strcpy(rcpt[num_city].city,temp);
				strcpy(rcpt[num_city].user[rcpt[num_city].num], utmp);
				++rcpt[num_city].num;
				++num_city;
			} else {
				int user_in = Find_CT_user(pos,utmp);
				if(user_in < 0) {
					strcpy(rcpt[pos].user[rcpt[pos].num], utmp);
					++rcpt[pos].num;
				}
			}
		}
		
		int num_msg=0;
		bool length=true;
		while( gets(msg[num_msg]) && strcmp(msg[num_msg],"*") ) {
			if(strlen(msg[num_msg]) > 72)	length=false;
			++num_msg;
		}
		
		for(int i=0;i<num_city;++i) {
			bool con=false;
			printf("Connection between %s and %s\n", sd_city, rcpt[i].city);
			printf("     HELO %s\n", sd_city);
			int pos = Find_MTA(sd_city);
			printf("     %d\n", Response(pos+1) );
			
			printf("     MAIL FROM:<%s>\n",sender);
			int pos_user = Find_MTA_man(pos, sd_name);
			//printf("pos=%d pos_user=%d\n",pos,pos_user);
			printf("     %d\n", Response(pos_user+1) );
			if(pos>=0 && pos_user>=0)	con=true;
			
			bool success=false;
			for(int j=0;j<rcpt[i].num;++j) {
				printf("     RCPT TO:<%s@%s>\n", rcpt[i].user[j], rcpt[i].city);
				pos = Find_MTA(rcpt[i].city);
				pos_user = Find_MTA_man(pos, rcpt[i].user[j]);
				if(pos_user >= 0)	success = true;
				if(pos < 0 || pos_user < 0) 
					printf("     550\n");
				else
					printf("     250\n");
			}
			
			if( success & con ) {
				puts("     DATA\n     354");
				for(int j=0;j<num_msg;++j)
					printf("     %s\n",msg[j]);
				if(length)
					puts("     .\n     250");
				else
					puts("     .\n     550");
			}			
			
			puts("     QUIT\n     221");
		}
		
	}
}	
	return 0;
}
