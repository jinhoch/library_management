#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "book.h"



void book_delete() {

	int j;
	int del_index;
	char buf[INIT_CAPACITY]; //삭제할 도서명 저장용 buf

	system("cls");
	printf("[2. 도서 삭제] 선택하셨습니다 \n");
	printf("삭제할 도서명을 입력하세요 : ");
	scanf("%s", buf);
	del_index = search(buf); //삭제할 도서명 index 넘겨준다


	if (del_index == -1) {
		printf("\n\n지울수 있는 도서가 존재하지 않습니다\n\n");
		return;
	}

	_stBook* p = booklist[del_index];

	for (j = del_index; j < n - 1; j++) {
		booklist[j] = booklist[j + 1];
	}
	n--;




	//booklist[del_index] 는 당연히 지우면 그 메모리공간 해제하는게 맞다
	//근데 booklist[del_index]->author, booklist[del_index]->title 를 free 해주는 이유는 아래와 같다
	//author과 title은  _strdup로 문자열을 넣어주었는데 이는 포인터 에 주소를 넣어준것이다
	// 즉 char* author 과 char* title 포인터 변수에 malloc으로 동적 메모리 할당후 주소값을 넘겨준것이므로
	// 지울때 free 해주어야한다 까먹으면 안된다! 


	free(p->author);
	free(p->title);
	free(p);


	printf("%d 번째 도서 [제목 : %s] 삭제가 완료되었습니다\n", del_index + 1, buf);

	printf("\n\n2초뒤 메뉴 화면으로 넘어갑니다\n ");
	Sleep(2000);

	return;

}