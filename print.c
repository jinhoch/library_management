#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "book.h"



void menu_print() {
	//å�� �������� �޴� ȭ������ �Ѿ�鼭 sleep ����� �߰����� ����
	//�� ���α׷��� ó�� ���� �������� 

	system("cls");
	printf(" +=================================+\n");
	printf("|           �޴�                    |\n");
	printf(" +=================================+\n");
	printf("| 1. ���� �߰�                      |\n");
	printf("| 2. ���� ����                      |\n");
	printf("| 3. ���� ����                      |\n");
	printf("| 4. ���� �˻�                      |\n");
	printf("| 5. ���� �ε�                      |\n");
	printf("| 6. ���� ����                      |\n");
	printf("| 7. ���� Ȯ��                      |\n");
	printf("|                                   |\n");
	printf("|                                   |\n");
	printf("|�����뷮 [%10d/%10d]   |\n", n, capacity);
	printf(" +=================================+\n");
	

}



void print_status_booklist() {

	char q;

	system("cls");
	printf("[6. ���� Ȯ��] �����ϼ̽��ϴ� \n");
	printf("\n");


	printf("���� �뷮 [%d/%d]\n", n, capacity);
	printf("======================================================================================================\n");
	printf("      [��ȣ]                 [����]         [����]        [�۰�]        [��������]       [������]\n");
	printf("======================================================================================================\n");
	for (int i = 0; i < capacity; i++) printf("%10d    |%20s | %10d  |   %10s   | %10d   |   %2d�� %2d�� %2d�� | \n",
		i + 1, booklist[i]->title, booklist[i]->price, booklist[i]->author, booklist[i]->page, booklist[i]->date.year, booklist[i]->date.month, booklist[i]->date.day);
	printf("======================================================================================================\n");
	printf("\n\n");

	printf("�޴��� ���ư��ðڽ��ϱ�? (0 �Է�) : ");
	scanf("%hhd", &q);


	printf("\n\n2�ʵ� �޴� ȭ������ �Ѿ�ϴ�\n ");
	Sleep(2000);
	return;


}

