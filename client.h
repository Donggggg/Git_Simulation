#define MAX_LENGTH 16

typedef struct _client {
	int num;
	char id[MAX_LENGTH];
	char passwd[MAX_LENGTH];
	char name[MAX_LENGTH];
	int age;
	char phone[MAX_LENGTH];
}Client;


void add_client();
void show_list();
int check_client(char*);
void modify_list();
