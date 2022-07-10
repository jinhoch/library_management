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
	printf("[3. ���� ����] �����ϼ̽��ϴ� \n");


	printf(" +=========================+\n");
	printf("|         ���� ����         |\n");
	printf(" +=========================+\n");
	printf("| 1. ����                   |\n");
	printf("| 2. ���� ����              |\n");
	printf("| 3. ������                 |\n");
	printf("| 4. ����                   |\n");
	printf("| 5. ����                   |\n");
	printf(" +=========================+\n");

	printf("\n\n� ���� ���� �����Ͻðڽ��ϱ�? (0 : ����) : ");
	scanf("%d", &sort_select);


	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			//���ݼ� ����
			if (sort_select == 1) {
				if (booklist[j]->price < booklist[least]->price) least = j;
			}
			//���࿬���� ����
			else if (sort_select == 2) {

				if ((booklist[j]->date.year * 10000 + booklist[j]->date.month * 100 + booklist[j]->date.day)
					< (booklist[least]->date.year * 10000 + booklist[least]->date.month * 100 + booklist[least]->date.day)) least = j;
			}
			//�������� ����
			else if (sort_select == 3) {
				if (booklist[j]->page < booklist[least]->page) least = j;
			}
			//����� ����
			else if (sort_select == 4) {
				if (strcmp(booklist[j]->title, booklist[least]->title) < 0) least = j;
			}
			//���ڼ� ����
			else if (sort_select == 5) {
				if (strcmp(booklist[j]->author, booklist[least]->author) < 0) least = j;
			}
			//�̿��� �޴� ��ȣ �Է½�
			else return;
		}
		_stBook* temp;

		temp = booklist[i];
		booklist[i] = booklist[least];
		booklist[least] = temp;
	}

	printf("������ �Ϸ�Ǿ����ϴ�\n");
	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);
	return;

}
