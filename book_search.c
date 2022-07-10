#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "book.h"




int search(char* name) {
	for (int i = 0; i < n; i++) {
		if (strcmp(booklist[i]->title, name) == 0) return i;
	}
	return -1;
}

void book_search() {
	char buf[INIT_CAPACITY] = { 0 }; //검색할 도서명 저장용
	char q;
	system("cls");
	printf("[4. 도서 검색] 선택하셨습니다 \n");


	printf("검색할 도서명을 입력하세요 : ");
	scanf("%s", buf);


	int index = search(buf);
	if (index == -1) printf(" [제목 : %s] 도서 존재 하지 않습니다 \n", buf);

	else printf("\n%02d번째 책 =  [제목] : %s  [가격] : %d  [작가] : %s  [페이지수] : %d  [발행일] : %d년 %d월 %d일 \n",
		index + 1, booklist[index]->title, booklist[index]->price, booklist[index]->author, booklist[index]->page, booklist[index]->date.year, booklist[index]->date.month, booklist[index]->date.day);



	printf("\n\n");
	printf("메뉴로 돌아가시겠습니까? (0 입력) : ");
	scanf("%hhd", &q);

	printf("\n\n2초뒤 메뉴 화면으로 넘어갑니다\n ");
	Sleep(2000);
	return;


}