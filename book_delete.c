#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "book.h"



void book_delete() {

	int j;
	int del_index;
	char buf[INIT_CAPACITY]; //������ ������ ����� buf

	system("cls");
	printf("[2. ���� ����] �����ϼ̽��ϴ� \n");
	printf("������ �������� �Է��ϼ��� : ");
	scanf("%s", buf);
	del_index = search(buf); //������ ������ index �Ѱ��ش�


	if (del_index == -1) {
		printf("\n\n����� �ִ� ������ �������� �ʽ��ϴ�\n\n");
		return;
	}

	_stBook* p = booklist[del_index];

	for (j = del_index; j < n - 1; j++) {
		booklist[j] = booklist[j + 1];
	}
	n--;




	//booklist[del_index] �� �翬�� ����� �� �޸𸮰��� �����ϴ°� �´�
	//�ٵ� booklist[del_index]->author, booklist[del_index]->title �� free ���ִ� ������ �Ʒ��� ����
	//author�� title��  _strdup�� ���ڿ��� �־��־��µ� �̴� ������ �� �ּҸ� �־��ذ��̴�
	// �� char* author �� char* title ������ ������ malloc���� ���� �޸� �Ҵ��� �ּҰ��� �Ѱ��ذ��̹Ƿ�
	// ���ﶧ free ���־���Ѵ� ������� �ȵȴ�! 


	free(p->author);
	free(p->title);
	free(p);


	printf("%d ��° ���� [���� : %s] ������ �Ϸ�Ǿ����ϴ�\n", del_index + 1, buf);

	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);

	return;

}