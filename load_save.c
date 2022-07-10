#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "book.h"



void load() {

	char title_buf[100];
	char author_buf[100];
	int price_buf;
	int page_buf;
	int year_buf;
	int month_buf;
	int day_buf;


	FILE* fp = fopen("input.txt", "r");

	if (fp == NULL) {

		printf("Open failed.\n");

		return;

	}


	while (fscanf(fp, "%s", title_buf) != EOF) {
		fscanf(fp, "%s", author_buf);
		fscanf(fp, "%d", &price_buf);
		fscanf(fp, "%d", &page_buf);
		fscanf(fp, "%d", &year_buf);
		fscanf(fp, "%d", &month_buf);
		fscanf(fp, "%d", &day_buf);

		Underbar_to_space(title_buf);
		add(title_buf, price_buf, author_buf, page_buf, year_buf, month_buf, day_buf);
	}


	fclose(fp);

	printf("���� �ε� ����\n");

	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);
	return;


}

void save() {

	FILE* fp = fopen("input_new_save.txt", "w");; //test������ w(����) ���� ����

	if (fp == NULL) {
		printf("���� ���� ����");
		return;
	}



	for (int i = 0; i < n; i++) {
		Space_to_underbar(booklist[i]->title);
		fprintf(fp, "%s %s %d %d %d %d %d\n", booklist[i]->title, booklist[i]->author, booklist[i]->price, booklist[i]->page, booklist[i]->date.year, booklist[i]->date.month, booklist[i]->date.day);
	}



	fclose(fp); //���� ������ �ݱ�
	printf("���� �Ϸ�\n");


	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);
	return;

}
