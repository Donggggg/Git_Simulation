#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"

void add_client()
{
	FILE *fp;
	Client client;

	if((fp = fopen("list.txt", "a")) == NULL) {
		fprintf(stderr, "회원 리스트가 없습니다.\n");
		return ;
	}

	client.num = (ftell(fp) / sizeof(Client)) + 1;

	printf("이름을 입력하세요\n");
	printf("> ");
	scanf("%s", client.name);

	printf("아이디를 입력하세요\n");
	printf("> ");
	scanf("%s", client.id);

	printf("비밀번호를 입력하세요\n");
	printf("> ");
	scanf("%s", client.passwd);

	printf("나이를 입력하세요\n");
	printf("> ");
	scanf("%d", &client.age);

	printf("연락처를 입력하세요\n");
	printf("> ");
	scanf("%s", client.phone);

	printf("주소를 입력하세요.\n");
	printf(">");
	scanf("%s", client.address);

	fwrite(&client, sizeof(Client), 1, fp);

	fclose(fp);
}

void show_list()
{
	char buffer[1024];
	FILE *fp;
	Client client;

	if((fp = fopen("list.txt", "r")) == NULL) {
		fprintf(stderr, "회원 리스트가 없습니다.\n");
		return ;
	}

	sprintf(buffer, "%4s  %-16s  %-16s  %-2s      %s         %s", "번호", "이름", "아이디", "나이", "연락처", "주소");
	printf("%s\n", buffer);

	while(fread(&client, sizeof(Client), 1, fp) != 0)
	{
		fgetc(fp);
		sprintf(buffer, "%-4d  %-16s%-16s%-2d   %s      %s", client.num, client.name, client.id, client.age, client.phone, client.address);
		printf("%s\n", buffer);
	}

	fclose(fp);

}
