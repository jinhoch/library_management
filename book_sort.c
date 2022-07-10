#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "book.h"


void book_sort() {
	int sort_select;
	int i, j, least;


	system("cls");
	printf("[3. 도서 정렬] 선택하셨습니다 \n");


	printf(" +=========================+\n");
	printf("|         정렬 기준         |\n");
	printf(" +=========================+\n");
	printf("| 1. 가격                   |\n");
	printf("| 2. 발행 연도              |\n");
	printf("| 3. 페이지                 |\n");
	printf("| 4. 제목                   |\n");
	printf("| 5. 저자                   |\n");
	printf(" +=========================+\n");

	printf("\n\n어떤 정렬 기준 선택하시겠습니까? (0 : 종료) : ");
	scanf("%d", &sort_select);


	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			//가격순 정렬
			if (sort_select == 1) {
				if (booklist[j]->price < booklist[least]->price) least = j;
			}
			//발행연도순 정렬
			else if (sort_select == 2) {

				if ((booklist[j]->date.year * 10000 + booklist[j]->date.month * 100 + booklist[j]->date.day)
					< (booklist[least]->date.year * 10000 + booklist[least]->date.month * 100 + booklist[least]->date.day)) least = j;
			}
			//페이지순 정렬
			else if (sort_select == 3) {
				if (booklist[j]->page < booklist[least]->page) least = j;
			}
			//제목순 정렬
			else if (sort_select == 4) {
				if (strcmp(booklist[j]->title, booklist[least]->title) < 0) least = j;
			}
			//저자순 정렬
			else if (sort_select == 5) {
				if (strcmp(booklist[j]->author, booklist[least]->author) < 0) least = j;
			}
			//이외의 메뉴 번호 입력시
			else return;
		}
		_stBook* temp;

		temp = booklist[i];
		booklist[i] = booklist[least];
		booklist[least] = temp;
	}

	printf("정렬이 완료되었습니다\n");
	printf("\n\n2초뒤 메뉴 화면으로 넘어갑니다\n ");
	Sleep(2000);
	return;

}
