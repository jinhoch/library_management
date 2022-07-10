#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "book.h"


void add(char* title, int price, char* author, int page, int year, int month, int day) {

	if (n >= capacity) booklist_reallocate();

	if ((int)strlen(title) > 20) {
		printf("책 제목이 너무 길어 추가 하지 못했습니다\n");
		return;
	}

	if ((int)strlen(author) > 10) {
		printf("작가 이름이 너무 길어 추가 하지 못했습니다\n");
		return;
	}

	if ((year > 22) || (day > 31) || (month > 12)) {
		printf("발행 연도가 올바르지 못해 추가 하지 못했습니다\n");
		return;
	}


	/*
	booklist[n] = (_stBook*)malloc(sizeof(_stBook));

	if (booklist[n] == NULL) {
		printf("booklist[i + 1] malloc 실패\n");
		return;
	}
	*/

	booklist[n]->author = string_malloc_copy(author);
	booklist[n]->title = string_malloc_copy(title);
	booklist[n]->price = price;
	booklist[n]->page = page;
	booklist[n]->date.year = year;
	booklist[n]->date.month = month;
	booklist[n]->date.day = day;

	n++;

}



void keyboar_add() {
	char title_buf[50];  //title
	char author_buf[50];	//author
	char price_buf[15];		//price
	char page_buf[15];		//page
	char year_buf[15];		//year
	char month_buf[15];		//month
	char day_buf[15];		//day

	int int_price_buf;
	int int_page_buf;
	int int_year_buf;
	int int_month_buf;
	int int_day_buf;


	char add_select = 'y';
	system("cls");
	printf("[1. 도서 추가] 선택하셨습니다 \n");
	while (add_select == 'y') {
		system("cls");
		printf("책 이름을 입력하세요 : ");
		if (read_line(title_buf, 20) <= 0) continue;

		printf("가격을 입력하세요 : ");
		scanf("%s", price_buf);
		int_price_buf = string_to_int(price_buf);
		if (int_price_buf == -1) continue;

		printf("작가를 입력하세요 : ");
		scanf("%s", author_buf);


		printf("총 페이지 수를 입력하세요 : ");
		scanf("%s", page_buf);
		int_page_buf = string_to_int(page_buf);
		if (int_page_buf == -1) continue;

		printf("발행 연,월,일을 입력하세요(ex 22 01 01) : ");
		scanf("%s %s %s", year_buf, month_buf, day_buf);
		int_year_buf = string_to_int(year_buf);
		int_month_buf = string_to_int(month_buf);
		int_day_buf = string_to_int(day_buf);
		if (int_year_buf == -1 || int_month_buf == -1 || int_day_buf == -1) continue;

		add(title_buf, int_price_buf, author_buf, int_page_buf, int_year_buf, int_month_buf, int_day_buf);

		printf("계속 추가 하시겠습니까? (계속 : y / 종료 : 아무키) : ");
		scanf(" %c", &add_select);


	}

	printf("\n\n2초뒤 메뉴 화면으로 넘어갑니다\n ");
	Sleep(2000);
	return;

}


int read_line(char* str, int limit) {  //limit 배열 str의 크기이다 즉 limit 보다 더 긴 line경우에는 뒷부분이 잘린다
	int ch, i = 0;

	while ((ch = getchar()) != '\n') { //줄바꿈 문자가 나올때까지 읽는다
		if (i < limit - 1) str[i++] = ch; //배열의 용량을 초과하지않을때만 저장한다 또한 -1 하는이유는 마지막에 \0 추가 위해서
	}
	str[i] = '\0';//마지막에 \0을 추가해준다 문자열의 끝이라는것을 표시

	return i; //실제로 읽은 문자수를 반환한다
}


int string_to_int(char* s) {
	int int_change = 0;
	int count = strlen(s);
	int j = count-1;
	for (int i = 0; i < count; i++, j--) {
		switch (s[i])
		{
		case '0':
			int_change += my_pow(j) * 0;
			break;
		case '1':
			int_change += my_pow(j) * 1;
			break;
		case '2':
			int_change += my_pow(j) * 2;
			break;
		case '3':
			int_change += my_pow(j) * 3;
			break;
		case '4':
			int_change += my_pow(j) * 4;
			break;
		case '5':
			int_change += my_pow(j) * 5;
			break;
		case '6':
			int_change += my_pow(j) * 6;
			break;
		case '7':
			int_change += my_pow(j) * 7;
			break;
		case '8':
			int_change += my_pow(j) * 8;
			break;
		case '9':
			int_change += my_pow(j) * 9;
			break;
		default:
			int_change = -1;
			break;
		}
	}

	return int_change;

}

int my_pow(int a) {
	int b = 1;
	for (int i = 0; i < a; i++) {
		b *= 10;
	}


	return b;
}