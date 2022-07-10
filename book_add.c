#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "book.h"


void add(char* title, int price, char* author, int page, int year, int month, int day) {

	if (n >= capacity) booklist_reallocate();

	if ((int)strlen(title) > 20) {
		printf("å ������ �ʹ� ��� �߰� ���� ���߽��ϴ�\n");
		return;
	}

	if ((int)strlen(author) > 10) {
		printf("�۰� �̸��� �ʹ� ��� �߰� ���� ���߽��ϴ�\n");
		return;
	}

	if ((year > 22) || (day > 31) || (month > 12)) {
		printf("���� ������ �ùٸ��� ���� �߰� ���� ���߽��ϴ�\n");
		return;
	}


	/*
	booklist[n] = (_stBook*)malloc(sizeof(_stBook));

	if (booklist[n] == NULL) {
		printf("booklist[i + 1] malloc ����\n");
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
	printf("[1. ���� �߰�] �����ϼ̽��ϴ� \n");
	while (add_select == 'y') {
		system("cls");
		printf("å �̸��� �Է��ϼ��� : ");
		if (read_line(title_buf, 20) <= 0) continue;

		printf("������ �Է��ϼ��� : ");
		scanf("%s", price_buf);
		int_price_buf = string_to_int(price_buf);
		if (int_price_buf == -1) continue;

		printf("�۰��� �Է��ϼ��� : ");
		scanf("%s", author_buf);


		printf("�� ������ ���� �Է��ϼ��� : ");
		scanf("%s", page_buf);
		int_page_buf = string_to_int(page_buf);
		if (int_page_buf == -1) continue;

		printf("���� ��,��,���� �Է��ϼ���(ex 22 01 01) : ");
		scanf("%s %s %s", year_buf, month_buf, day_buf);
		int_year_buf = string_to_int(year_buf);
		int_month_buf = string_to_int(month_buf);
		int_day_buf = string_to_int(day_buf);
		if (int_year_buf == -1 || int_month_buf == -1 || int_day_buf == -1) continue;

		add(title_buf, int_price_buf, author_buf, int_page_buf, int_year_buf, int_month_buf, int_day_buf);

		printf("��� �߰� �Ͻðڽ��ϱ�? (��� : y / ���� : �ƹ�Ű) : ");
		scanf(" %c", &add_select);


	}

	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);
	return;

}


int read_line(char* str, int limit) {  //limit �迭 str�� ũ���̴� �� limit ���� �� �� line��쿡�� �޺κ��� �߸���
	int ch, i = 0;

	while ((ch = getchar()) != '\n') { //�ٹٲ� ���ڰ� ���ö����� �д´�
		if (i < limit - 1) str[i++] = ch; //�迭�� �뷮�� �ʰ������������� �����Ѵ� ���� -1 �ϴ������� �������� \0 �߰� ���ؼ�
	}
	str[i] = '\0';//�������� \0�� �߰����ش� ���ڿ��� ���̶�°��� ǥ��

	return i; //������ ���� ���ڼ��� ��ȯ�Ѵ�
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