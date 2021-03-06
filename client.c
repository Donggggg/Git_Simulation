#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"
#include <string.h>

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

	if (check_client(client.id) == 0)
	{
		printf("already exist\n");
		
		fclose(fp);
		return;
	}

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

int  check_client(char* id)
{
	FILE *fp;
	Client client;

	if((fp = fopen("list.txt", "r")) == NULL){
		fprintf(stderr, "no list.\n");
		return 0;
	}

	while(fread(&client, sizeof(Client),1,fp) != 0)
	{
		fgetc(fp);
		if(strcmp(id, client.id) == 0)
		{
			fclose(fp);
			return 0;
			
		}

	}
	fclose(fp);
	return 1;
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

void modify_list()
{
	FILE *fp;
	char name[1024];
	char buffer[1024];
	Client client;

	if((fp = fopen("list.txt", "r+")) == NULL) {
		fprintf(stderr, "회원 리스트가 없습니다.\n");
		return ;
	}

	printf("수정할 회원 이름을 입력하세요 : ");
	scanf("%s",name);

	while(fread(&client, sizeof(Client), 1, fp) != 0)
	{
	  fgetc(fp);
	  if(strcmp(name,client.name)==0)
	  {
	    printf("수정 할 이름 >");
	    scanf("%s", client.name);

	    printf("수정 할 ID>");
	    scanf("%s", client.id);

	    printf("수정 할 나이>");
	    scanf("%d", &client.age);

	    printf("수정 할 전화번호>");
	    scanf("%s", client.phone);
	    
		printf("수정 할 주소>");
		scanf("%s", client.address);

	    fseek(fp,((client.num-1)*(sizeof(Client)+1)), SEEK_SET);
		
		fwrite(&client, sizeof(Client), 1, fp);
		fputc('\n',fp);
		sprintf(buffer, "%-4d  %-16s%-16s%-2d   %s     %s", client.num, client.name, client.id, client.age, client.phone, client.address);
//		printf("%s\n", buffer);
		break;
	  }
	}
	printf("수정 프로그램 완료\n");
	fclose(fp);
	return;
}
