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
	char buf[INIT_CAPACITY] = { 0 }; //�˻��� ������ �����
	char q;
	system("cls");
	printf("[4. ���� �˻�] �����ϼ̽��ϴ� \n");


	printf("�˻��� �������� �Է��ϼ��� : ");
	scanf("%s", buf);


	int index = search(buf);
	if (index == -1) printf(" [���� : %s] ���� ���� ���� �ʽ��ϴ� \n", buf);

	else printf("\n%02d��° å =  [����] : %s  [����] : %d  [�۰�] : %s  [��������] : %d  [������] : %d�� %d�� %d�� \n",
		index + 1, booklist[index]->title, booklist[index]->price, booklist[index]->author, booklist[index]->page, booklist[index]->date.year, booklist[index]->date.month, booklist[index]->date.day);



	printf("\n\n");
	printf("�޴��� ���ư��ðڽ��ϱ�? (0 �Է�) : ");
	scanf("%hhd", &q);

	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);
	return;


}