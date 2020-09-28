#include <stdio.h>
#include <stdlib.h>
#include "client.h"

int main()
{
	int input;

	while(1)
	{
		printf("--------------------------------------------------------------\n");
		printf("1. 회원추가  2. 회원목록  3. 종료 4.수정\n");
		printf("> ");
		scanf("%d", &input);
		printf("--------------------------------------------------------------\n");
		getchar();

		switch(input)
		{
			case 1 :
				// 회원추가
				add_client();
				break;
			case 2 :
				// 목록보기
				show_list();
				break;
			case 3 :
				exit(1);
				break;
			case 4 :
				modify_list();
				break;
			default :
				printf("지원하지 않는 기능입니다.\n");
				break;
		}
	}
}
