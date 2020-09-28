#define MAX_LENGTH 16
#define ADD_LENGTH 32

typedef struct _client {
	int num;
	char id[MAX_LENGTH];
	char passwd[MAX_LENGTH];
	char name[MAX_LENGTH];
	int age;
	char phone[MAX_LENGTH];
	char address[ADD_LENGTH];
}Client;


void add_client();
void show_list();
