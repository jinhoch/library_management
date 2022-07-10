#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "book.h"



void menu_print() {
	//책이 없을때는 메뉴 화면으로 넘어가면서 sleep 기능을 추가하지 않음
	//즉 프로그램을 처음 실행 했을때는 

	system("cls");
	printf(" +=================================+\n");
	printf("|           메뉴                    |\n");
	printf(" +=================================+\n");
	printf("| 1. 도서 추가                      |\n");
	printf("| 2. 도서 삭제                      |\n");
	printf("| 3. 도서 정렬                      |\n");
	printf("| 4. 도서 검색                      |\n");
	printf("| 5. 파일 로드                      |\n");
	printf("| 6. 파일 저장                      |\n");
	printf("| 7. 도서 확인                      |\n");
	printf("|                                   |\n");
	printf("|                                   |\n");
	printf("|도서용량 [%10d/%10d]   |\n", n, capacity);
	printf(" +=================================+\n");
	

}



void print_status_booklist() {

	char q;

	system("cls");
	printf("[6. 도서 확인] 선택하셨습니다 \n");
	printf("\n");


	printf("현재 용량 [%d/%d]\n", n, capacity);
	printf("======================================================================================================\n");
	printf("      [번호]                 [제목]         [가격]        [작가]        [페이지수]       [발행일]\n");
	printf("======================================================================================================\n");
	for (int i = 0; i < capacity; i++) printf("%10d    |%20s | %10d  |   %10s   | %10d   |   %2d년 %2d월 %2d일 | \n",
		i + 1, booklist[i]->title, booklist[i]->price, booklist[i]->author, booklist[i]->page, booklist[i]->date.year, booklist[i]->date.month, booklist[i]->date.day);
	printf("======================================================================================================\n");
	printf("\n\n");

	printf("메뉴로 돌아가시겠습니까? (0 입력) : ");
	scanf("%hhd", &q);


	printf("\n\n2초뒤 메뉴 화면으로 넘어갑니다\n ");
	Sleep(2000);
	return;


}

